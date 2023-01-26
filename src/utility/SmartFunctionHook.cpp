#include "SmartFunctionHook.hpp"
#include "Log/Logging.hpp"

#include <detours.h>
#define FFI_BUILDING // Statically linking libffi
#include <ffi.h>

namespace RHook {

	SmartFunctionHook::~SmartFunctionHook()
	{
		Remove();

		auto& ppArgs = (ffi_type**&)m_ppArgs;
		auto& pCif = (ffi_cif*&)m_pCif;
		auto& pClosure = (ffi_closure*&)m_pClosure;

		if (pClosure != nullptr) {
			ffi_closure_free(m_pClosure);
			m_pClosure = nullptr;
		}

		if (pCif != nullptr) {
			delete pCif;
		}

		if (ppArgs != nullptr) {
			delete[] m_ppArgs;
			m_ppArgs = nullptr;
		}
	}

	bool SmartFunctionHook::Create()
	{
		if (m_Target == 0 || m_Destination == 0 || m_Original != nullptr) {
			RH_RHOOK_ERROR("[SMART FUNCTION HOOK] \"{:s}\" Hook not initialized", m_Name.empty() ? "Unnamed" : m_Name.c_str());
			return false;
		}

		m_Original = m_Target;

		if (auto status = DetourTransactionBegin(); status != NO_ERROR) {
			RH_RHOOK_ERROR("[SMART FUNCTION HOOK] \"{:s}\" Failed to hook {:p}: 0x{:x} on DetourTransactionBegin()", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, status);

			m_Destination = 0;
			m_Target = 0;
			m_Original = 0;
			return false;
		}

		if (auto status = DetourUpdateThread(GetCurrentThread()); status != NO_ERROR) {
			RH_RHOOK_ERROR("[SMART FUNCTION HOOK] \"{:s}\" Failed to hook {:p}: 0x{:x} on DetourUpdateThread()", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, status);

			m_Destination = 0;
			m_Target = 0;
			m_Original = 0;

			if (auto status = DetourTransactionCommit(); status != NO_ERROR) {
				RH_RHOOK_ERROR("[SMART FUNCTION HOOK] \"{:s}\" Failed to hook {:p}: 0x{:x} on DetourTransactionCommit()", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, status);
			}

			return false;
		}

		m_Original = m_Target;

		if (auto status = DetourAttach(&m_Original, m_Binding); status != NO_ERROR) {
			RH_RHOOK_ERROR("[SMART FUNCTION HOOK] \"{:s}\" Failed to hook {:p}: 0x{:x} on DetourAttach()", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, status);

			m_Destination = 0;
			m_Target = 0;
			m_Original = 0;

			if (auto status = DetourTransactionCommit(); status != NO_ERROR) {
				RH_RHOOK_ERROR("[SMART FUNCTION HOOK] \"{:s}\" Failed to hook {:p}: 0x{:x} on DetourTransactionCommit()", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, status);
			}

			return false;
		}

		if (auto status = DetourTransactionCommit(); status != NO_ERROR) {
			RH_RHOOK_ERROR("[SMART FUNCTION HOOK] \"{:s}\" Failed to hook {:p}: 0x{:x} on DetourTransactionCommit()", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, status);

			m_Destination = 0;
			m_Target = 0;
			m_Original = 0;
			return false;
		}

		RH_RHOOK_INFO("[SMART FUNCTION HOOK] \"{:s}\" Hooked {:p}->{:p}", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, m_Destination);
		return true;
	}

	bool SmartFunctionHook::Unhook()

	{
		// Don't try to remove invalid hooks.
		if (m_Target == 0 || m_Destination == 0 || m_Original == 0 || m_Original == m_Target) {
			return true;
		}

		if (auto status = DetourTransactionBegin(); status != NO_ERROR) {
			RH_RHOOK_ERROR("[SMART FUNCTION HOOK] \"{:s}\" Failed to unhook {:p}: 0x{:x} on DetourTransactionBegin()", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, status);

			return false;
		}

		if (auto status = DetourUpdateThread(GetCurrentThread()); status != NO_ERROR) {
			RH_RHOOK_ERROR("[SMART FUNCTION HOOK] \"{:s}\" Failed to unhook {:p}: 0x{:x} on DetourUpdateThread()", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, status);

			if (auto status = DetourTransactionCommit(); status != NO_ERROR) {
				RH_RHOOK_ERROR("[SMART FUNCTION HOOK] \"{:s}\" Failed to unhook {:p}: 0x{:x} on DetourTransactionCommit()", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, status);
			}

			return false;
		}

		if (auto status = DetourDetach(&m_Original, m_Binding); status != NO_ERROR) {
			RH_RHOOK_ERROR("[SMART FUNCTION HOOK] \"{:s}\" Failed to unhook {:p}: 0x{:x} on DetourDetach()", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, status);

			if (auto status = DetourTransactionCommit(); status != NO_ERROR) {
				RH_RHOOK_ERROR("[SMART FUNCTION HOOK] \"{:s}\" Failed to unhook {:p}: 0x{:x} on DetourTransactionCommit()", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, status);
			}

			return false;
		}

		if (auto status = DetourTransactionCommit(); status != NO_ERROR) {
			RH_RHOOK_ERROR("[SMART FUNCTION HOOK] \"{:s}\" Failed to unhook {:p}: 0x{:x} on DetourTransactionCommit()", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, status);

			return false;
		}

		m_Original = 0;

		RH_RHOOK_INFO("[SMART FUNCTION HOOK] \"{:s}\" Unhooked {:p}, Previous detour: {:p}", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, m_Destination);
		return true;
	}

	bool SmartFunctionHook::Remove()
	{
		// Save away for logging
		auto target = m_Target;

		// Unhook.
		if (!Unhook()) {
			RH_RHOOK_INFO("[SMART FUNCTION HOOK] \"{:s}\" Failed to remove hook: {:p}", m_Name.empty() ? "Unnamed" : m_Name.c_str(), target);
			return false;
		}

		RH_RHOOK_INFO("[SMART FUNCTION HOOK] \"{:s}\" Removed hook: {:p}", m_Name.empty() ? "Unnamed" : m_Name.c_str(), target);

		// Invalidate the members.
		m_Target = nullptr;
		m_Destination = nullptr;
		m_Original = nullptr;

		return true;
	}

	void SmartFunctionHook::InitializeUnnamed(bool (*setup)(SmartFunctionHook* pThis))
	{
		RH_RHOOK_INFO("[SMART FUNCTION HOOK] Setting up a smart hook on {:p}->{:p}", m_Target, m_Destination);

		if (!setup(this)) {
			RH_RHOOK_ERROR("[SMART FUNCTION HOOK] \"{:s}\" Failed to enclose the target function!");
		}
	}

	void SmartFunctionHook::InitializeNamed(bool (*setup)(SmartFunctionHook* pThis))
	{
		RH_RHOOK_INFO("[SMART FUNCTION HOOK] \"{:s}\" Setting up a smart hook on {:p}->{:p}", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, m_Destination);

		if (!setup(this)) {
			RH_RHOOK_ERROR("[SMART FUNCTION HOOK] \"{:s}\" Failed to enclose the target function on {:p}->{:p}", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, m_Destination);
		}
	}

	bool SmartFunctionHook::InitializeClosure(const size_t argc, void (*fun)(void*, void*, void**, void*))
	{
		auto& ppArgs = (ffi_type**&)m_ppArgs;
		auto& pCif = (ffi_cif*&)m_pCif;
		auto& bindingFn = (void (*&)(ffi_cif*, void*, void**, void*))fun;
		auto& pClosure = (ffi_closure*&)m_pClosure;

		ppArgs = new ffi_type* [argc] { nullptr };
		for (size_t i = 0; i < argc; i++) {
			ppArgs[i] = &ffi_type_pointer;
		}

		pCif = new ffi_cif{};
		pClosure = (ffi_closure*)ffi_closure_alloc(sizeof(ffi_closure), &m_Binding);

		if (m_pClosure == nullptr)
			return false;

		if (ffi_prep_cif(pCif, FFI_DEFAULT_ABI, argc, &ffi_type_pointer, ppArgs) != FFI_OK) {
			return false;
		}

		if (ffi_prep_closure_loc(pClosure, pCif, bindingFn, this, m_Binding) != FFI_OK) {
			return false;
		}

		return true;
	}

}