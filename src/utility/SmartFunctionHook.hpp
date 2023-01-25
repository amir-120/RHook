#pragma once

#include <windows.h>
#include <cstdint>
#include <type_traits>

#include "./Address.hpp"

namespace RHook {
	class SmartFunctionHook {
	public:
		SmartFunctionHook() = delete;
		SmartFunctionHook(const SmartFunctionHook& other) = delete;
		SmartFunctionHook(SmartFunctionHook&& other) = delete;

		template <typename CType>
		SmartFunctionHook(CType* target, CType* destination, SmartFunctionHook** ppActiveHook)
			: m_Target(target), m_Destination(destination), m_ppActiveHook(ppActiveHook)
		{
			auto setupFn = &SmartFunctionHook::Setup<CType>;
			using setup_t = bool(SmartFunctionHook*);

			InitializeUnnamed((setup_t*&)setupFn);
		}

		template <typename CType>	
		SmartFunctionHook(CType* target, CType* destination, SmartFunctionHook** ppActiveHook, std::string_view name)
			: m_Target(target), m_Destination(destination), m_ppActiveHook(ppActiveHook), m_Name(name)
		{
			auto setupFn = &SmartFunctionHook::Setup<CType>;
			using setup_t = bool(SmartFunctionHook*);

			InitializeNamed((setup_t*&)setupFn);
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
		T* GetTarget() const {
			return (T*)m_Target;
		}

		const auto& GetDestination() const {
			return m_Destination;
		}

		template <typename T>
		T* GetDestination() const {
			return (T*)m_Destination;
		}

		const auto& GetOriginal() const {
			return m_Original;
		}

		template <typename T>
		T* GetOriginal() const {
			return (T*)m_Original;
		}

		auto IsValid() const {
			return m_Original != nullptr && m_pClosure != nullptr && m_Binding != nullptr;
		}

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

		void InitializeUnnamed(bool (*setup)(SmartFunctionHook* pThis));
		void InitializeNamed(bool (*setup)(SmartFunctionHook* pThis));

		bool InitializeClosure(const size_t argc, void (*fun)(void*, void*, void**, void*));

		template <typename CType>
		bool Setup()
		{
			constexpr auto argc = FunctionInfo<CType>::Argc;
			const auto binding = FunctionBinding<CType>;

			return InitializeClosure(argc, binding);
		}

		LPVOID m_Target{ nullptr };
		LPVOID m_Destination{ nullptr };
		LPVOID m_Original{ nullptr };

		SmartFunctionHook** m_ppActiveHook{ nullptr };
		std::string m_Name{};

		// Closure data
		void* m_pCif { nullptr }; // ffi_cif
		void** m_ppArgs{ nullptr }; // ffi_type
		void* m_pClosure{ nullptr }; // ffi_closure
		void* m_Binding{ nullptr };

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
			using CRType = typename FunctionInfo<CType>::RType;
			constexpr auto argc = FunctionInfo<CType>::Argc;

			auto pCurrentHook = (SmartFunctionHook*)hook;
			*pCurrentHook->m_ppActiveHook = pCurrentHook;

			if constexpr (std::is_same_v<CRType, void>) {
				FunctionBindingCall(args, (CType*)pCurrentHook->m_Destination, std::make_index_sequence<argc> {});
			}
			else {
				*(CRType*)ret = FunctionBindingCall(args, (CType*)pCurrentHook->m_Destination, std::make_index_sequence<argc> {});
			}
		}
	};
}