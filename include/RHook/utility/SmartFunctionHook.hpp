#pragma once

#include <windows.h>
#include <cstdint>
#include <type_traits>
#include <functional>
#include <mutex>

#include "./Address.hpp"

namespace RHook {
	class SmartFunctionHook {
	public:
		SmartFunctionHook() = delete;
		SmartFunctionHook(const SmartFunctionHook& other) = delete;
		SmartFunctionHook(SmartFunctionHook&& other) = delete;

		//************************************
		// Method:    SmartFunctionHook
		// FullName:  RHook::SmartFunctionHook<CType>::SmartFunctionHook
		// Access:    public 
		// Returns:   
		// Qualifier: : m_Target(target), m_Destination(destination), m_ppActiveHook(ppActiveHook), m_Name(name)
		// Parameter: CType* target: The address to be hooked
		// Parameter: CType* destination: Address to jump to
		// Parameter: SmartFunctionHook** ppActiveHook: Pointer to SmartFunctionHook*, will be updated to point to the current SmartFunctionHook per execution of the hook
		// Parameter: std::string_view name: Optional parameter, used for organizing and logging
		//************************************
		template <typename CType>	
		SmartFunctionHook(CType* target, CType* destination, SmartFunctionHook** ppActiveHook, std::string_view name = "Unnamed")
			: m_Target(target), m_Destination(destination), m_ppActiveHook(ppActiveHook), m_Name(name)
		{
			auto setupFn = &SmartFunctionHook::Setup<CType>;
			using setup_t = bool(SmartFunctionHook*);

			Initialize((setup_t*&)setupFn);
		}

		virtual ~SmartFunctionHook();

		bool Create();

		bool Unhook();

		// Called automatically by the destructor, but you can call it explicitly
		// if you need to remove the hook.
		bool Remove();

		const auto& GetTarget() const {
			return m_Target;
		}

		template <typename T>
		T GetTarget() const {
			return m_Target.As<T>();
		}

		const auto& GetDestination() const {
			return m_Destination;
		}

		template <typename T>
		T GetDestination() const {
			return m_Destination.As<T>();
		}

		const auto& GetTrampoline() const {
			return m_Trampoline;
		}

		template <typename T>
		T GetTrampoline() const {
			return m_Trampoline.As<T>();
		}

		auto IsValid() const {
			return m_Trampoline != nullptr && m_pClosure != nullptr && m_pBinding != nullptr;
		}

		const auto& IsEnabled() const { return m_IsEnabled; }

		void SetName(const std::string& name) {
			m_Name = name;
		}

		const auto& GetName() {
			return m_Name;
		}

		SmartFunctionHook& operator=(const SmartFunctionHook& other) = delete;
		SmartFunctionHook& operator=(SmartFunctionHook&& other) = delete;

	private:
		template<typename>
		struct FunctionInfo;

		template<typename Ret, typename... Args>
		struct FunctionInfo<Ret(Args...)> {
			using RType = Ret;
			static constexpr size_t Argc = sizeof...(Args);
		};

		template<typename Ret, typename... Args>
		struct FunctionInfo<Ret(*)(Args...)> : FunctionInfo<Ret(Args...)> {};

		void Initialize(bool (*setup)(SmartFunctionHook* pThis));

		bool InitializeClosure(const size_t argc, void (*fun)(void*, void*, void**, void*));

		template <typename CType>
		bool Setup()
		{
			constexpr auto argc = FunctionInfo<CType>::Argc;
			const auto binding = FunctionBinding<CType>;

			return InitializeClosure(argc, binding);
		}

		template<typename Ret, typename... Args, size_t... N>
		inline static Ret FunctionBindingCall(void** args, Ret(fn)(Args...), std::index_sequence<N...>)
		{
			if constexpr (std::is_same_v<Ret, void>) {
				fn(*(Args*)(args[N])...);
			}
			else {
				return fn(*(Args*)(args[N])...);
			}
		}

		template <typename CType>
		static void FunctionBinding(void* cif, void* ret, void** args, void* hook)
		{
			// Return type
			using CRType = typename FunctionInfo<CType>::RType;

			// Argument count
			constexpr auto argc = FunctionInfo<CType>::Argc;

			// Set the active hook
			auto pCurrentHook = (SmartFunctionHook*)hook;
			*pCurrentHook->m_ppActiveHook = pCurrentHook;

			if constexpr (std::is_same_v<CRType, void>) {
				FunctionBindingCall(args, pCurrentHook->m_Destination.As<CType*>(), std::make_index_sequence<argc> {});
			}
			else {
				*(CRType*)ret = FunctionBindingCall(args, pCurrentHook->m_Destination.As<CType*>(), std::make_index_sequence<argc> {});
			}
		}

	private:
		std::recursive_mutex m_HookMutex{};
		bool m_IsEnabled{ false };

		Address m_Target{ nullptr };
		Address m_Destination{ nullptr };
		Address m_Trampoline{ nullptr };

		std::function<void(SmartFunctionHook*)> m_PreHookEnableCallback{}, m_PostHookEnableCallback{},
			m_PreHookDisableCallback{}, m_PostHookDisableCallback{};

		SmartFunctionHook** m_ppActiveHook{ nullptr };
		std::string m_Name{};

		// Closure data
		void* m_pCif { nullptr }; // ffi_cif
		void** m_ppArgs{ nullptr }; // ffi_type
		void* m_pClosure{ nullptr }; // ffi_closure
		void* m_pBinding{ nullptr };
	};
}