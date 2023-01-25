#pragma once

#include <windows.h>
#include <cstdint>
#include <type_traits>

#include "./Address.hpp"

namespace RHook {
	class FunctionHook {
	public:
		FunctionHook() = delete;
		FunctionHook(const FunctionHook& other) = delete;
		FunctionHook(FunctionHook&& other) = delete;
		FunctionHook(Address target, Address destination);
		FunctionHook(Address target, Address destination, std::string_view name);
		virtual ~FunctionHook();

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
			return m_Original != nullptr;
		}

		void SetName(const std::string& name) {
			m_Name = name;
		}

		const auto& GetName() {
			return m_Name;
		}

		FunctionHook& operator=(const FunctionHook& other) = delete;
		FunctionHook& operator=(FunctionHook&& other) = delete;

	private:
		LPVOID m_Target{ nullptr };
		LPVOID m_Destination{ nullptr };
		LPVOID m_Original{ nullptr };

		std::string m_Name{};
	};
}