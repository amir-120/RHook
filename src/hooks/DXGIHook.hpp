#pragma once

#include <assert.h>
#include <functional>
#include <array>
#include <memory>
#include <mutex>
#include <wrl.h>

#pragma comment(lib, "dxgi")

#include <dxgi1_2.h>

#include "../utility/FunctionHook.hpp"

using Microsoft::WRL::ComPtr;

#define DXGIHOOK_INTERNAL(X) RHook::DXGIHook::SkipDetours([&]() X)

namespace RHook {
	class DXGIHook {
	public:
		typedef std::function<void(DXGIHook&)> CallBackFn;

		DXGIHook() = delete;
		DXGIHook(const DXGIHook& other) = delete;
		DXGIHook(DXGIHook&& other) = delete;
		DXGIHook(std::recursive_mutex* hookMutex);
		virtual ~DXGIHook();

		bool HookDXGI(IUnknown* pDevice);
		bool UnhookDXGI();

		static  const auto& IsDXGIHooked() { return s_IsDXGIHooked; }

		static void SkipDetours(const std::function<void()>& code);

#define ADD_HOOK_METHODS(SYMBOL) auto& Get##SYMBOL##Params() const { assert(s_ParamList[(size_t)HIdx::SYMBOL] != nullptr,	\
		"Tried to access hook params outside call!");																		\
		return *(SYMBOL##Parameters_t*)s_ParamList[(size_t)HIdx::SYMBOL]; }													\
			static void Signal##SYMBOL##Detour(const bool& state) { s_DetourExecutionList[(size_t)HIdx::SYMBOL] = state; }	\
			void OnPre##SYMBOL(CallBackFn fn) { m_OnPreFunctionCallList[(size_t)HIdx::SYMBOL] = fn; }						\
			void OnPost##SYMBOL(CallBackFn fn) { m_OnPostFunctionCallList[(size_t)HIdx::SYMBOL] = fn; }	

		ADD_HOOK_METHODS(Present)
		ADD_HOOK_METHODS(ResizeBuffers)
		ADD_HOOK_METHODS(ResizeTarget)

#define ADD_RESULT_LOGIC(TYPE, SYMBOL) auto& Get##SYMBOL##Result() { assert(s_ResultList[(size_t)HIdx::SYMBOL] != nullptr, "Tried to access hook result outside call!"); \
			return *(TYPE*)s_ResultList[(size_t)HIdx::SYMBOL]; }

		ADD_RESULT_LOGIC(HRESULT, Present)
		ADD_RESULT_LOGIC(HRESULT, ResizeBuffers)
		ADD_RESULT_LOGIC(HRESULT, ResizeTarget)

		DXGIHook& operator=(const DXGIHook& other) = delete;
		DXGIHook& operator=(DXGIHook&& other) = delete;

	protected:
		void ReleaseDXGI();

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
			RWrapper<IDXGISwapChain*> swapChain;
			RWrapper<UINT> syncInterval;
			RWrapper<UINT> flags;
		};

		struct ResizeBuffersParameters_t {
			RWrapper<IDXGISwapChain*> swapChain;
			RWrapper<UINT> bufferCount;
			RWrapper<UINT> width;
			RWrapper<UINT> height;
			RWrapper<DXGI_FORMAT> newFormat;
			RWrapper<UINT> swapChainFlags;
		};

		struct ResizeTargetParameters_t {
			RWrapper<IDXGISwapChain*> swapChain;
			RWrapper<CONST DXGI_MODE_DESC*> newTargetParameters;
		};

		enum class HIdx : size_t {
			Present = 0,
			ResizeBuffers,
			ResizeTarget,

			Size,
		};

		std::recursive_mutex* m_HookMutex{ nullptr };

		inline static bool s_IsDXGIHooked{ false };

		ComPtr<IDXGISwapChain1> m_PSwapChain{};
		ComPtr<IDXGIFactory2> m_PDXGIFactory{};

		inline static std::array<std::unique_ptr<FunctionHook>, (size_t)HIdx::Size> s_HookList;
		inline static std::array<bool, (size_t)HIdx::Size> s_DetourExecutionList{};
		inline static std::array<void*, (size_t)HIdx::Size> s_ParamList{}, s_ResultList{};
		std::array<FunctionHook*, (size_t)HIdx::Size> m_ActiveHookList{};

		// Callbacks to actually do work when the hooked functions get called.
		std::array<CallBackFn, (size_t)HIdx::Size> m_OnPreFunctionCallList{ nullptr }, m_OnPostFunctionCallList{ nullptr };

		static HRESULT WINAPI Present(IDXGISwapChain* swapChain, UINT syncInterval, UINT flags);
		static HRESULT WINAPI ResizeBuffers(IDXGISwapChain* swapChain, UINT bufferCount, UINT width, UINT height, DXGI_FORMAT newFormat, UINT swapChainFlags);
		static HRESULT WINAPI ResizeTarget(IDXGISwapChain* swapChain, const DXGI_MODE_DESC* newTargetParameters);
	};
}