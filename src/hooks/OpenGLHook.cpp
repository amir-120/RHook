#include "OpenGLHook.hpp"

#include "Log/Logging.hpp"

namespace RHook {
	static OpenGLHook* g_OpenGLHook = nullptr;

	OpenGLHook::OpenGLHook(std::recursive_mutex* hookMutex)
		: m_HookMutex(hookMutex)
	{}

	OpenGLHook::~OpenGLHook()
	{
		Unhook();
		g_OpenGLHook = nullptr;
	}

	bool OpenGLHook::Hook()
	{
		RH_RHOOK_INFO("Hooking OpenGL");

		g_OpenGLHook = this;

		auto openGLModule = GetModuleHandleA("opengl32.dll");
		if (!openGLModule) {
			RH_RHOOK_ERROR("[OPENGL HOOK] Failed to load opengl32.dll.");
			return false;
		}

		auto realSwapBuffersFn = (decltype(SwapBuffers)*)GetProcAddress(openGLModule, "wglSwapBuffers");
		if (!realSwapBuffersFn) {
			RH_RHOOK_ERROR("[OPENGL HOOK] Failed to load wglSwapBuffers() export.");
			return false;
		}

#define ADD_HOOK(SYMBOL) s_HookList[(size_t)HIdx::SYMBOL] = std::make_unique<FunctionHook>(real##SYMBOL##Fn, (uintptr_t)&OpenGLHook::SYMBOL, #SYMBOL"()");

		ADD_HOOK(SwapBuffers)

		// Enable detours
		for (auto& execute : s_DetourExecutionList) {
			execute = true;
		}

		s_Hooked = true;

		// Set the active hooks
		for (size_t i = 0; i < s_HookList.size(); i++) {
			if (s_HookList[i]->Create()) {
				m_ActiveHookList[i] = s_HookList[i].get();
			}
			else {
				RH_RHOOK_ERROR("[OPENGL HOOK] Failed to hook {:s}", s_HookList[i]->GetName());
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

	bool OpenGLHook::Unhook()
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

	void OpenGLHook::SkipDetours(const std::function<void()>& code)
	{
		const auto detoursExecutionStateBack = s_DetourExecutionList;

		code();

		s_DetourExecutionList = detoursExecutionStateBack;
	}

#define DETOUR_RETURN(RESULT, SYMBOL, ...) {																								\
			const auto& executeDetour = s_DetourExecutionList[(size_t)HIdx::SYMBOL];														\
				  auto&	callDepth = g_OGLCallDepth##SYMBOL;																					\
			const auto& hook = g_OpenGLHook->m_ActiveHookList[(uint64_t)HIdx::SYMBOL];														\
			const auto& preDetourFn = g_OpenGLHook->m_OnPreFunctionCallList[(size_t)HIdx::SYMBOL];											\
			const auto& postDetourFn = g_OpenGLHook->m_OnPostFunctionCallList[(size_t)HIdx::SYMBOL];										\
				  auto&	pParams = *(SYMBOL##Parameters_t**)&s_ParamList[(size_t)HIdx::SYMBOL];												\
				  auto&	pResult = *(decltype(RESULT)**)&s_ResultList[(size_t)HIdx::SYMBOL];													\
																																			\
			/*This line must be called before calling our detour function because we might have to unhook the function inside our detour.	\
			*/auto originalFn = hook->GetOriginal<decltype(OpenGLHook::SYMBOL)>();															\
			auto realFn = hook->GetTarget<decltype(OpenGLHook::SYMBOL)>();																	\
																																			\
			if (g_OpenGLHook != nullptr && executeDetour && callDepth == 0) {																\
				static SYMBOL##Parameters_t tmpParams = { __VA_ARGS__ };																	\
				tmpParams = { __VA_ARGS__ };																								\
				pParams = &tmpParams;																										\
				pResult = &RESULT;																											\
				OpenGLHook::SkipDetours([&]() {																								\
					if (preDetourFn) {																										\
						preDetourFn(*g_OpenGLHook);																							\
					}																														\
				});																															\
			}																																\
																																			\
			callDepth++;																													\
																																			\
			if (g_OpenGLHook != nullptr && hook->IsValid())																					\
				RESULT = originalFn( __VA_ARGS__ );																							\
			else																															\
				RESULT = realFn( __VA_ARGS__ ); 																							\
																																			\
			callDepth--;																													\
																																			\
			if (g_OpenGLHook != nullptr && executeDetour && callDepth == 0) {																\
				OpenGLHook::SkipDetours([&]() {																								\
					if (postDetourFn) {																										\
						postDetourFn(*g_OpenGLHook);																						\
					}																														\
				});																															\
				pResult = nullptr;																											\
				pParams = nullptr;																											\
			}																																\
		}

	thread_local size_t g_OGLCallDepthSwapBuffers = 0;
	BOOL WINAPI OpenGLHook::SwapBuffers(HDC hDC)
	{
		std::scoped_lock _{ *g_OpenGLHook->m_HookMutex };

		static BOOL result = {};
		DETOUR_RETURN(result, SwapBuffers, hDC)

		return result;
	}
}