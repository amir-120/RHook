#include "DXGIHook.hpp"

#include "D3DDXGIVMTIndices.hpp"

#include "Log/Logging.hpp"

namespace RHook {
	static DXGIHook* g_DXGIHook = nullptr;

	DXGIHook::DXGIHook(std::recursive_mutex* hookMutex)
		: m_HookMutex{ hookMutex }
	{}

	DXGIHook::~DXGIHook() {
		UnhookDXGI();
		g_DXGIHook = nullptr;
	}

	bool DXGIHook::HookDXGI(IUnknown* pDevice) {
		RH_RHOOK_INFO("Hooking DXGI");

		g_DXGIHook = this;

		DXGI_SWAP_CHAIN_DESC1 swapChainDesc1;

		ZeroMemory(&swapChainDesc1, sizeof(swapChainDesc1));

		swapChainDesc1.Width = 1;
		swapChainDesc1.Height = 1;
		swapChainDesc1.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
		swapChainDesc1.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapChainDesc1.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;
		swapChainDesc1.BufferCount = 2;
		swapChainDesc1.SampleDesc.Count = 1;
		swapChainDesc1.AlphaMode = DXGI_ALPHA_MODE_PREMULTIPLIED;

		// Manually get CreateDXGIFactory export because the user may be running Windows 7
		const auto dxgiModule = LoadLibrary("dxgi.dll");
		if (dxgiModule == nullptr) {
			RH_RHOOK_ERROR("[DXGI HOOK] Failed to load dxgi.dll");
			return false;
		}

		auto realCreateDXGIFactoryFn = (decltype(CreateDXGIFactory)*)GetProcAddress(dxgiModule, "CreateDXGIFactory");

		if (realCreateDXGIFactoryFn == nullptr) {
			RH_RHOOK_ERROR("[DXGI HOOK] Failed to get CreateDXGIFactory export.");
			return false;
		}

		RH_RHOOK_INFO("[DXGI HOOK] Creating Dummy DXGI Factory.");

		if (auto hr = realCreateDXGIFactoryFn(IID_PPV_ARGS(&m_PDXGIFactory)); FAILED(hr)) {
			RH_RHOOK_ERROR("[DXGI HOOK] Failed to create Dummy DXGI Factory. ERROR: {:s}", WINCOM_ERROR(hr));
			return false;
		}

		RH_RHOOK_INFO("[DXGI HOOK] Creating Dummy SwapChain");

		if (auto hr = m_PDXGIFactory->CreateSwapChainForComposition(pDevice, &swapChainDesc1, NULL,
			&m_PSwapChain); FAILED(hr)) {
			RH_RHOOK_ERROR("[DXGI HOOK] Failed to create Dummy DXGI SwapChain. ERROR: {:s}", WINCOM_ERROR(hr));
			return false;
		}

		//RH_RHOOK_INFO("[DXGI HOOK] Querying Dummy SwapChain");
		//
		//if (auto hr = swapChain1->QueryInterface(IID_PPV_ARGS(&swapChain)); FAILED(hr)) {
		//	RH_RHOOK_ERROR("[DXGI HOOK] Failed to retrieve DXGI SwapChain. ERROR: {:s}", WINCOM_ERROR(hr));
		//	return false;
		//}

		auto realPresentFn = (*(uintptr_t**)m_PSwapChain.Get())[(size_t)IDXGISwapChainVMT::Present]; // Present
		auto realResizeBuffersFn = (*(uintptr_t**)m_PSwapChain.Get())[(size_t)IDXGISwapChainVMT::ResizeBuffers]; // ResizeBuffers
		auto realResizeTargetFn = (*(uintptr_t**)m_PSwapChain.Get())[(size_t)IDXGISwapChainVMT::ResizeTarget]; // ResizeTarget

#define ADD_HOOK(SYMBOL) s_HookList[(size_t)HIdx::SYMBOL] = std::make_unique<FunctionHook>(real##SYMBOL##Fn, (uintptr_t)&DXGIHook::SYMBOL, #SYMBOL"()");

		ADD_HOOK(Present)
		ADD_HOOK(ResizeBuffers)
		ADD_HOOK(ResizeTarget)

		// Enable detours
		for (auto& execute : s_DetourExecutionList) {
			execute = true;
		}

		s_IsDXGIHooked = true;

		// Set the active hooks
		for (size_t i = 0; i < s_HookList.size(); i++) {
			if (s_HookList[i]->Create()) {
				m_ActiveHookList[i] = s_HookList[i].get();
			}
			else {
				RH_RHOOK_ERROR("[DXGI HOOK] Failed to hook {:s}", s_HookList[i]->GetName());
				s_IsDXGIHooked = false;
			}
		}

		if (!s_IsDXGIHooked) {
			// If a problem occurred, reset the hook.
			// Call unhook just to be sure all hooks are removed.
			UnhookDXGI();

			for (auto& hook : s_HookList) {
				hook.reset();
			}

			g_DXGIHook = nullptr;

			return false;
		}

		return s_IsDXGIHooked;
	}

	bool DXGIHook::UnhookDXGI() {
		ReleaseDXGI();

		bool unhooked = true;

		for (auto& hook : s_HookList) {
			if (hook) unhooked = unhooked && hook->Remove();
		}

		if (unhooked) {
			s_IsDXGIHooked = false;
			return true;
		}

		return false;
	}

	void DXGIHook::ReleaseDXGI()
	{
		m_PSwapChain.Reset();
		m_PDXGIFactory.Reset();
	}

	void DXGIHook::SkipDetours(const std::function<void()>& code)
	{
		// A static array of false elements to use as detour disabling
		static std::array<bool, s_DetourExecutionList.size()> noDetourSwap = { false };

		s_DetourExecutionList.swap(noDetourSwap);

		code();

		s_DetourExecutionList.swap(noDetourSwap);
	}

#define DETOUR_RETURN(RESULT, SYMBOL, ...) {																								\
			const auto& executeDetour = s_DetourExecutionList[(size_t)HIdx::SYMBOL];														\
				  auto&	callDepth = g_DXGICallDepth##SYMBOL;																				\
			const auto& hook = g_DXGIHook->m_ActiveHookList[(uint64_t)HIdx::SYMBOL];														\
			const auto& preDetourFn = g_DXGIHook->m_OnPreFunctionCallList[(size_t)HIdx::SYMBOL];											\
			const auto& postDetourFn = g_DXGIHook->m_OnPostFunctionCallList[(size_t)HIdx::SYMBOL];											\
				  auto&	pParams = *(SYMBOL##Parameters_t**)&s_ParamList[(size_t)HIdx::SYMBOL];												\
				  auto&	pResult = *(decltype(RESULT)**)&s_ResultList[(size_t)HIdx::SYMBOL];													\
																																			\
			/*This line must be called before calling our detour function because we might have to unhook the function inside our detour.	\
			*/auto originalFn = hook->GetOriginal<decltype(DXGIHook::SYMBOL)>();															\
			auto realFn = hook->GetTarget<decltype(DXGIHook::SYMBOL)>();																	\
																																			\
			if (g_DXGIHook != nullptr && executeDetour && callDepth == 0) {																	\
				static SYMBOL##Parameters_t tmpParams = { __VA_ARGS__ };																	\
				tmpParams = { __VA_ARGS__ };																								\
				pParams = &tmpParams;																										\
				pResult = &RESULT;																											\
				DXGIHook::SkipDetours([&]() {																								\
					if (preDetourFn) {																										\
						preDetourFn(*g_DXGIHook);																							\
					}																														\
				});																															\
			}																																\
																																			\
			callDepth++;																													\
																																			\
			if (g_DXGIHook != nullptr && hook->IsValid())																					\
				RESULT = originalFn( __VA_ARGS__ );																							\
			else																															\
				RESULT = realFn( __VA_ARGS__ ); 																							\
																																			\
			callDepth--;																													\
																																			\
			if (g_DXGIHook != nullptr && executeDetour && callDepth == 0) {																	\
				DXGIHook::SkipDetours([&]() {																								\
					if (postDetourFn) {																										\
						postDetourFn(*g_DXGIHook);																							\
					}																														\
				});																															\
				pResult = nullptr;																											\
				pParams = nullptr;																											\
			}																																\
		}

	thread_local size_t g_DXGICallDepthPresent = 0;
	HRESULT WINAPI DXGIHook::Present(IDXGISwapChain* swapChain, UINT syncInterval, UINT flags) {
		std::scoped_lock _{ *g_DXGIHook->m_HookMutex };
		
		static HRESULT result = {};
		DETOUR_RETURN(result, Present, swapChain, syncInterval, flags)

		return result;
	}

	thread_local size_t g_DXGICallDepthResizeBuffers = 0;
	HRESULT WINAPI DXGIHook::ResizeBuffers(IDXGISwapChain* swapChain, UINT bufferCount, UINT width, UINT height, DXGI_FORMAT newFormat, UINT swapChainFlags) {
		std::scoped_lock _{ *g_DXGIHook->m_HookMutex };

		static HRESULT result = {};
		DETOUR_RETURN(result, ResizeBuffers, swapChain, bufferCount, width, height, newFormat, swapChainFlags)

		return result;
	}

	thread_local size_t g_DXGICallDepthResizeTarget = 0;
	HRESULT WINAPI DXGIHook::ResizeTarget(IDXGISwapChain* swapChain, const DXGI_MODE_DESC* newTargetParameters) {
		std::scoped_lock _{ *g_DXGIHook->m_HookMutex };

		static HRESULT result = {};
		DETOUR_RETURN(result, ResizeTarget, swapChain, newTargetParameters)

		return result;
	}
}