#pragma once

#include <assert.h>
#include <functional>
#include <array>
#include <memory>
#include <mutex>

#pragma comment(lib, "d3d9.lib")

#include <d3d9.h>

#include "../utility/FunctionHook.hpp"

#define D3D9HOOK_INTERNAL(X) RHook::D3D9Hook::SkipDetours([&]() X)

namespace RHook {
    class D3D9Hook {
    public:
        typedef std::function<void(D3D9Hook&)> CallBackFn;

        D3D9Hook() = delete;
        D3D9Hook(const D3D9Hook& other) = delete;
        D3D9Hook(D3D9Hook&& other) = delete;
        D3D9Hook(std::recursive_mutex* hookMutex);
        virtual ~D3D9Hook();

        bool Hook();
        bool Unhook();

		static  const auto& IsHooked() { return s_Hooked; }

        static void SkipDetours(const std::function<void()>& code);

#define ADD_HOOK_METHODS(SYMBOL) auto& Get##SYMBOL##Params() const { assert(s_ParamList[(size_t)HIdx::SYMBOL] != nullptr,	\
		"Tried to access hook params outside call!");																		\
		return *(SYMBOL##Parameters_t*)s_ParamList[(size_t)HIdx::SYMBOL]; }													\
			static void Signal##SYMBOL##Detour(const bool& state) { s_DetourExecutionList[(size_t)HIdx::SYMBOL] = state; }	\
			void OnPre##SYMBOL(CallBackFn fn) { m_OnPreFunctionCallList[(size_t)HIdx::SYMBOL] = fn; }						\
			void OnPost##SYMBOL(CallBackFn fn) { m_OnPostFunctionCallList[(size_t)HIdx::SYMBOL] = fn; }		

		ADD_HOOK_METHODS(Present)
		ADD_HOOK_METHODS(Reset)
		ADD_HOOK_METHODS(EndScene)

#define ADD_RESULT_LOGIC(TYPE, SYMBOL) auto& Get##SYMBOL##Result() { assert(s_ResultList[(size_t)HIdx::SYMBOL] != nullptr, "Tried to access hook result outside call!"); \
			return *(TYPE*)s_ResultList[(size_t)HIdx::SYMBOL]; }

		ADD_RESULT_LOGIC(HRESULT, Present)
		ADD_RESULT_LOGIC(HRESULT, Reset)
		ADD_RESULT_LOGIC(HRESULT, EndScene)

        D3D9Hook& operator=(const D3D9Hook& other) = delete;
        D3D9Hook& operator=(D3D9Hook&& other) = delete;

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

		struct PresentParameters_t {
			RWrapper<IDirect3DDevice9*> device;
			RWrapper<CONST RECT*> src;
			RWrapper<CONST RECT*> dest;
			RWrapper<HWND> hWnd;
			RWrapper<CONST RGNDATA*> dirtyRgn;
		};

		struct ResetParameters_t {
			RWrapper<IDirect3DDevice9*> device;
			RWrapper<D3DPRESENT_PARAMETERS*> presentParams;
		};

		struct EndSceneParameters_t {
			RWrapper<IDirect3DDevice9*> device;
		};

		enum class HIdx : size_t {
			Present = 0,
            Reset,
            EndScene,

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

        static HRESULT WINAPI Present(IDirect3DDevice9* device, CONST RECT* src, CONST RECT* dest, HWND hWnd, CONST RGNDATA* dirtyRgn);
        static HRESULT WINAPI Reset(IDirect3DDevice9* device, D3DPRESENT_PARAMETERS* presentParams);
        static HRESULT WINAPI EndScene(IDirect3DDevice9* device);
    };
}