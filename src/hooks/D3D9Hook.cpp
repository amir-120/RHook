#include "D3D9Hook.hpp"
#include "D3D9VMTIndices.hpp"

#include "Log/Logging.hpp"

namespace RHook {
	static D3D9Hook* g_D3D9Hook{ nullptr };

	D3D9Hook::D3D9Hook(std::recursive_mutex* hookMutex)
		: m_HookMutex{ hookMutex }
	{}

	D3D9Hook::~D3D9Hook() {
		// Explicitly unhook the methods we hooked so we can reset g_d3d9Hook.
		Unhook();
		g_D3D9Hook = nullptr;
	}

	bool D3D9Hook::Hook() {
		RH_RHOOK_INFO("Hooking D3D9");

		// Set hook object preemptively -- otherwise, the hook is written and is likely
		// to execute and crash before we verify success.
		g_D3D9Hook = this;

		HWND hWnd = GetDesktopWindow();

		// All we do here is create a IDirect3DDevice9 so that we can get the address
		// of the methods we want to hook from its vtable.
		//using D3DCreate9Fn = IDirect3D9 * (WINAPI*)(UINT);

		auto d3d9Module = LoadLibrary("d3d9.dll");

		if (d3d9Module == nullptr) {
			RH_RHOOK_ERROR("[D3D9 HOOK] Failed to load d3d9.dll.");
			return false;
		}

		auto realDirect3DCreate9Fn = (decltype(Direct3DCreate9)*)GetProcAddress(d3d9Module, "Direct3DCreate9");

		if (realDirect3DCreate9Fn == nullptr) {
			RH_RHOOK_ERROR("[D3D9 HOOK] Couldn't find Direct3DCreate9.");
			return false;
		}

		RH_RHOOK_INFO("[D3D9 HOOK] Got Direct3DCreate9 {:p}", (void*)realDirect3DCreate9Fn);

		auto d3d = realDirect3DCreate9Fn(D3D_SDK_VERSION);

		if (d3d == nullptr) {
			RH_RHOOK_ERROR("[D3D9 HOOK] Failed to create IDirect3D9.");
			return false;
		}

		D3DPRESENT_PARAMETERS pp{};

		ZeroMemory(&pp, sizeof(pp));

		pp.Windowed = 1;
		pp.SwapEffect = D3DSWAPEFFECT_FLIP;
		pp.BackBufferFormat = D3DFMT_A8R8G8B8;
		pp.BackBufferCount = 1;
		pp.hDeviceWindow = hWnd;
		pp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

		IDirect3DDevice9* device{ nullptr };

		if (auto hr = d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_NULLREF, hWnd,
			D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_NOWINDOWCHANGES, &pp, &device); FAILED(hr))
		{
			RH_RHOOK_ERROR("[D3D9 HOOK] Failed to create D3D9 device. ERROR: {:s}", WINCOM_ERROR(hr));
			d3d->Release();
			return false;
		}

		// Grab the addresses of the methods we want to hook.
		auto realPresentFn = (*(uintptr_t**)device)[(size_t)IDirect3DDevice9VMT::Present];
		auto realResetFn = (*(uintptr_t**)device)[(size_t)IDirect3DDevice9VMT::Reset];
		auto realEndSceneFn = (*(uintptr_t**)device)[(size_t)IDirect3DDevice9VMT::EndScene];

#define ADD_HOOK(SYMBOL) s_HookList[(size_t)HIdx::SYMBOL] = std::make_unique<FunctionHook>(real##SYMBOL##Fn, (uintptr_t)&D3D9Hook::SYMBOL, #SYMBOL"()");

		ADD_HOOK(Present)
		ADD_HOOK(Reset)
		ADD_HOOK(EndScene)

		// Enable detours
		for (auto& execute : s_DetourExecutionList) {
			execute = true;
		}

		device->Release();
		d3d->Release();

		s_Hooked = true;

		// Set the active hooks
		for (size_t i = 0; i < s_HookList.size(); i++) {
			if (s_HookList[i]->Create()) {
				m_ActiveHookList[i] = s_HookList[i].get();
			}
			else {
				RH_RHOOK_ERROR("[D3D9 HOOK] Failed to hook {:s}", s_HookList[i]->GetName());
				s_Hooked = false;
			}
		}

		if (!s_Hooked) {
			// If a problem occurred, reset the hook.
			// Call unhook just to be sure all hooks are removed.
			Unhook();

			for (auto& hook : s_HookList) {
				hook.reset();
			}

			s_Hooked = false;

			return false;
		}

		return s_Hooked;
	}


	bool D3D9Hook::Unhook()
	{
		bool unhooked = true;

		for (auto& hook : s_HookList) {
			if (hook) unhooked = unhooked && hook->Remove();
		}

		if (unhooked) {
			s_Hooked = false;
			return true;
		}

		return false;
	}


	void D3D9Hook::SkipDetours(const std::function<void()>& code)
	{
		const auto detoursExecutionStateBack = s_DetourExecutionList;

		code();

		s_DetourExecutionList = detoursExecutionStateBack;
	}

#define DETOUR_RETURN(RESULT, SYMBOL, ...) {																								\
			const auto& executeDetour = s_DetourExecutionList[(size_t)HIdx::SYMBOL];														\
				  auto&	callDepth = g_D3D9CallDepth##SYMBOL;																				\
			const auto& hook = g_D3D9Hook->m_ActiveHookList[(uint64_t)HIdx::SYMBOL];														\
			const auto& preDetourFn = g_D3D9Hook->m_OnPreFunctionCallList[(size_t)HIdx::SYMBOL];											\
			const auto& postDetourFn = g_D3D9Hook->m_OnPostFunctionCallList[(size_t)HIdx::SYMBOL];											\
				  auto&	pParams = *(SYMBOL##Parameters_t**)&s_ParamList[(size_t)HIdx::SYMBOL];												\
				  auto&	pResult = *(decltype(RESULT)**)&s_ResultList[(size_t)HIdx::SYMBOL];													\
																																			\
			/*This line must be called before calling our detour function because we might have to unhook the function inside our detour.	\
			*/auto originalFn = hook->GetOriginal<decltype(D3D9Hook::SYMBOL)>();															\
			auto realFn = hook->GetTarget<decltype(D3D9Hook::SYMBOL)>();																	\
																																			\
			if (g_D3D9Hook != nullptr && executeDetour && callDepth == 0) {																	\
				static SYMBOL##Parameters_t tmpParams = { __VA_ARGS__ };																	\
				tmpParams = { __VA_ARGS__ };																								\
				pParams = &tmpParams;																										\
				pResult = &RESULT;																											\
				D3D9Hook::SkipDetours([&]() {																								\
					if (preDetourFn) {																										\
						preDetourFn(*g_D3D9Hook);																							\
					}																														\
				});																															\
			}																																\
																																			\
			callDepth++;																													\
																																			\
			if (g_D3D9Hook != nullptr && hook->IsValid())																					\
				RESULT = originalFn( __VA_ARGS__ );																							\
			else																															\
				RESULT = realFn( __VA_ARGS__ ); 																							\
																																			\
			callDepth--;																													\
																																			\
			if (g_D3D9Hook != nullptr && executeDetour && callDepth == 0) {																	\
				D3D9Hook::SkipDetours([&]() {																								\
					if (postDetourFn) {																										\
						postDetourFn(*g_D3D9Hook);																							\
					}																														\
				});																															\
				pResult = nullptr;																											\
				pParams = nullptr;																											\
			}																																\
		}

	thread_local size_t g_D3D9CallDepthPresent = 0;
	HRESULT D3D9Hook::Present(IDirect3DDevice9* device, CONST RECT* src, CONST RECT* dest, HWND hWnd, CONST RGNDATA* dirtyRgn) {
		std::scoped_lock _{ *g_D3D9Hook->m_HookMutex };

		HRESULT result = {};
		DETOUR_RETURN(result, Present, device, src, dest, hWnd, dirtyRgn)

		return result;
	}

	thread_local size_t g_D3D9CallDepthReset = 0;
	HRESULT D3D9Hook::Reset(IDirect3DDevice9* device, D3DPRESENT_PARAMETERS* presentParams) {
		std::scoped_lock _{ *g_D3D9Hook->m_HookMutex };

		HRESULT result = {};
		DETOUR_RETURN(result, Reset, device, presentParams)

		return result;
	}

	thread_local size_t g_D3D9CallDepthEndScene = 0;
	HRESULT D3D9Hook::EndScene(IDirect3DDevice9* device) {
		std::scoped_lock _{ *g_D3D9Hook->m_HookMutex };

		HRESULT result = {};
		DETOUR_RETURN(result, EndScene, device)

		return result;
	}
}