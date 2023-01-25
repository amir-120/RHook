#pragma once

#include <assert.h>
#include <functional>
#include <array>
#include <memory>
#include <mutex>
#include <windows.h>

#pragma comment(lib, "OpenGL32.Lib")

#include <gl/GL.h>

#include "../utility/FunctionHook.hpp"

#define OPENGLHOOK_INTERNAL(X) RHook::OpenGLHook::SkipDetours([&]() X)

namespace RHook {
	class OpenGLHook {
	public:
		typedef std::function<void(OpenGLHook&)> CallBackFn;

		OpenGLHook() = delete;
		OpenGLHook(const OpenGLHook& other) = delete;
		OpenGLHook(OpenGLHook&& other) = delete;
		OpenGLHook(std::recursive_mutex* hookMutex);
		virtual ~OpenGLHook();

		bool Hook();
		bool Unhook();

		static const auto& IsHooked() { return s_Hooked; }

		static void SkipDetours(const std::function<void()>& code);

#define ADD_HOOK_METHODS(SYMBOL) auto& Get##SYMBOL##Params() const { assert(s_ParamList[(size_t)HIdx::SYMBOL] != nullptr,	\
		"Tried to access hook params outside call!");																		\
		return *(SYMBOL##Parameters_t*)s_ParamList[(size_t)HIdx::SYMBOL]; }													\
			static void Signal##SYMBOL##Detour(const bool& state) { s_DetourExecutionList[(size_t)HIdx::SYMBOL] = state; }	\
			void OnPre##SYMBOL(CallBackFn fn) { m_OnPreFunctionCallList[(size_t)HIdx::SYMBOL] = fn; }						\
			void OnPost##SYMBOL(CallBackFn fn) { m_OnPostFunctionCallList[(size_t)HIdx::SYMBOL] = fn; }	

		ADD_HOOK_METHODS(SwapBuffers)

#define ADD_RESULT_LOGIC(TYPE, SYMBOL) auto& Get##SYMBOL##Result() { assert(s_ResultList[(size_t)HIdx::SYMBOL] != nullptr, "Tried to access hook result outside call!"); \
			return *(TYPE*)s_ResultList[(size_t)HIdx::SYMBOL]; }

		ADD_RESULT_LOGIC(BOOL, SwapBuffers)

		OpenGLHook& operator=(const OpenGLHook& other) = delete;
		OpenGLHook& operator=(OpenGLHook&& other) = delete;

	protected:
		template<typename T>
		class RWrapper : public std::reference_wrapper<T> {
		public:
			RWrapper(T& val)
				: std::reference_wrapper<T>(val)
			{}

			void operator=(const T& rhs) { this->get() = rhs; }
			template<typename = std::enable_if_t<std::is_pointer_v<T>>>
			auto* operator->() { return this->get(); }

			operator T& () { return this->get(); }
			operator const T& () const { return this->get(); }
		};

		struct SwapBuffersParameters_t {
			RWrapper<HDC> hDC;
		};

		enum class HIdx : size_t {
			SwapBuffers = 0,

			Size,
		};

		std::recursive_mutex* m_HookMutex{ nullptr };

		inline static bool s_Hooked{ false };

		inline static std::array<std::unique_ptr<FunctionHook>, (size_t)HIdx::Size> s_HookList;
		inline static std::array<bool, (size_t)HIdx::Size> s_DetourExecutionList{};
		inline static std::array<void*, (size_t)HIdx::Size> s_ParamList{}, s_ResultList{};
		std::array<FunctionHook*, (size_t)HIdx::Size> m_ActiveHookList{};

		// Callbacks to actually do work when the hooked functions get called.
		std::array<CallBackFn, (size_t)HIdx::Size> m_OnPreFunctionCallList{ nullptr }, m_OnPostFunctionCallList{ nullptr };

		static BOOL  WINAPI SwapBuffers(HDC hDC);
	};
}