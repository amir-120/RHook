#include <RHook/utility/SmartFunctionHook.hpp>
#include <log/Logging.hpp>

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
		extern bool g_IsMSDetoursInitialized;

		if (!g_IsMSDetoursInitialized) {
			if (DetourRestoreAfterWith() == TRUE) {
				RHOOK_INFO("[FUNCTION HOOK] MS Detours initialized successfully.");
			}
			else {
				RHOOK_ERROR("[FUNCTION HOOK] MS Detours failed to initiliaze.");
			}

			g_IsMSDetoursInitialized = true;
		}

		std::scoped_lock _{ m_HookMutex };

		if (m_PreHookEnableCallback)
			m_PreHookEnableCallback(this);

		if (m_Target == nullptr || m_Destination == nullptr || m_Trampoline != nullptr) {
			RHOOK_ERROR("[SMART FUNCTION HOOK] \"{:s}\" Hook not initialized", m_Name.c_str());
			return false;
		}

		m_Trampoline = m_Target;

		if (auto status = DetourTransactionBegin(); status != NO_ERROR) {
			RHOOK_ERROR("[SMART FUNCTION HOOK] \"{:s}\" Failed to hook {:p}: 0x{:x} on DetourTransactionBegin()", m_Name.c_str(), m_Target.Ptr(), status);

			m_Destination.Set(nullptr);
			m_Target.Set(nullptr);
			m_Trampoline.Set(nullptr);
			return false;
		}

		if (auto status = DetourUpdateThread(GetCurrentThread()); status != NO_ERROR) {
			RHOOK_ERROR("[SMART FUNCTION HOOK] \"{:s}\" Failed to hook {:p}: 0x{:x} on DetourUpdateThread()", m_Name.c_str(), m_Target.Ptr(), status);

			m_Destination.Set(nullptr);
			m_Target.Set(nullptr);
			m_Trampoline.Set(nullptr);

			if (auto status = DetourTransactionCommit(); status != NO_ERROR) {
				RHOOK_ERROR("[SMART FUNCTION HOOK] \"{:s}\" Failed to hook {:p}: 0x{:x} on DetourTransactionCommit()", m_Name.c_str(), m_Target.Ptr(), status);
			}

			return false;
		}

		m_Trampoline = m_Target;

		if (auto status = DetourAttach(&m_Trampoline.As<LPVOID>(), m_pBinding); status != NO_ERROR) {
			RHOOK_ERROR("[SMART FUNCTION HOOK] \"{:s}\" Failed to hook {:p}: 0x{:x} on DetourAttach()", m_Name.c_str(), m_Target.Ptr(), status);

			m_Destination.Set(nullptr);
			m_Target.Set(nullptr);
			m_Trampoline.Set(nullptr);

			if (auto status = DetourTransactionCommit(); status != NO_ERROR) {
				RHOOK_ERROR("[SMART FUNCTION HOOK] \"{:s}\" Failed to hook {:p}: 0x{:x} on DetourTransactionCommit()", m_Name.c_str(), m_Target.Ptr(), status);
			}

			return false;
		}

		if (auto status = DetourTransactionCommit(); status != NO_ERROR) {
			RHOOK_ERROR("[SMART FUNCTION HOOK] \"{:s}\" Failed to hook {:p}: 0x{:x} on DetourTransactionCommit()", m_Name.c_str(), m_Target.Ptr(), status);

			m_Destination.Set(nullptr);
			m_Target.Set(nullptr);
			m_Trampoline.Set(nullptr);
			return false;
		}

		RHOOK_INFO("[SMART FUNCTION HOOK] \"{:s}\" Hooked {:p}->{:p}", m_Name.c_str(), m_Target.Ptr(), m_Destination.Ptr());

		m_IsEnabled = true;

		if (m_PostHookEnableCallback)
			m_PostHookEnableCallback(this);

		return true;
	}

	bool SmartFunctionHook::Unhook()
	{
		if (m_Trampoline == nullptr) {
			RHOOK_WARN("[SMART FUNCTION HOOK \"{:s}\" .Hook() called while the detour is not placed!", m_Name);
			return true;
		}

		std::scoped_lock _{ m_HookMutex };

		if (m_PreHookDisableCallback)
			m_PreHookDisableCallback(this);

		// Don't try to remove invalid hooks.
		if (m_Target == nullptr || m_Destination == nullptr || m_Trampoline == nullptr || m_Trampoline == m_Target) {
			return true;
		}

		if (auto status = DetourTransactionBegin(); status != NO_ERROR) {
			RHOOK_ERROR("[SMART FUNCTION HOOK] \"{:s}\" Failed to unhook {:p}: 0x{:x} on DetourTransactionBegin()", m_Name.c_str(), m_Target.Ptr(), status);

			return false;
		}

		if (auto status = DetourUpdateThread(GetCurrentThread()); status != NO_ERROR) {
			RHOOK_ERROR("[SMART FUNCTION HOOK] \"{:s}\" Failed to unhook {:p}: 0x{:x} on DetourUpdateThread()", m_Name.c_str(), m_Target.Ptr(), status);

			if (auto status = DetourTransactionCommit(); status != NO_ERROR) {
				RHOOK_ERROR("[SMART FUNCTION HOOK] \"{:s}\" Failed to unhook {:p}: 0x{:x} on DetourTransactionCommit()", m_Name.c_str(), m_Target.Ptr(), status);
			}

			return false;
		}

		if (auto status = DetourDetach(&m_Trampoline.As<LPVOID>(), m_pBinding); status != NO_ERROR) {
			RHOOK_ERROR("[SMART FUNCTION HOOK] \"{:s}\" Failed to unhook {:p}: 0x{:x} on DetourDetach()", m_Name.c_str(), m_Target.Ptr(), status);

			if (auto status = DetourTransactionCommit(); status != NO_ERROR) {
				RHOOK_ERROR("[SMART FUNCTION HOOK] \"{:s}\" Failed to unhook {:p}: 0x{:x} on DetourTransactionCommit()", m_Name.c_str(), m_Target.Ptr(), status);
			}

			return false;
		}

		if (auto status = DetourTransactionCommit(); status != NO_ERROR) {
			RHOOK_ERROR("[SMART FUNCTION HOOK] \"{:s}\" Failed to unhook {:p}: 0x{:x} on DetourTransactionCommit()", m_Name.c_str(), m_Target.Ptr(), status);

			return false;
		}

		RHOOK_INFO("[SMART FUNCTION HOOK] \"{:s}\" Unhooked {:p}, Previous detour: {:p}", m_Name, m_Target.Ptr(), m_Destination.Ptr());

		m_IsEnabled = false;

		if (m_PostHookDisableCallback)
			m_PostHookDisableCallback(this);

		return true;
	}

	bool SmartFunctionHook::Remove()
	{
		// Save away for logging
		auto target = m_Target;

		// Unhook.
		if (!Unhook()) {
			RHOOK_INFO("[SMART FUNCTION HOOK] \"{:s}\" Failed to remove hook: {:p}", m_Name.c_str(), target.Ptr());
			return false;
		}

		RHOOK_INFO("[SMART FUNCTION HOOK] \"{:s}\" Removed hook: {:p}", m_Name.c_str(), target.Ptr());

		// Invalidate the members.
		m_Target = nullptr;
		m_Destination = nullptr;
		m_Trampoline = nullptr;

		return true;
	}

	void SmartFunctionHook::Initialize(bool (*setup)(SmartFunctionHook* pThis))
	{
		RHOOK_INFO("[SMART FUNCTION HOOK] \"{:s}\" Setting up a smart hook on {:p}->{:p}", m_Name.c_str(), m_Target.Ptr(), m_Destination.Ptr());

		if (!setup(this)) {
			RHOOK_ERROR("[SMART FUNCTION HOOK] \"{:s}\" Failed to enclose the target function on {:p}->{:p}", m_Name.c_str(), m_Target.Ptr(), m_Destination.Ptr());
			return;
		}
	}

	bool SmartFunctionHook::InitializeClosure(const size_t argc, void (*fun)(void*, void*, void**, void*))
	{
		std::scoped_lock _{ m_HookMutex };

		auto& ppArgs = (ffi_type**&)m_ppArgs;
		auto& pCif = (ffi_cif*&)m_pCif;
		auto& bindingFn = (void (*&)(ffi_cif*, void*, void**, void*))fun;
		auto& pClosure = (ffi_closure*&)m_pClosure;

		ppArgs = new ffi_type* [argc] { nullptr };
		for (size_t i = 0; i < argc; i++) {
			ppArgs[i] = &ffi_type_pointer;
		}

		pCif = new ffi_cif{};
		pClosure = (ffi_closure*)ffi_closure_alloc(sizeof(ffi_closure), &m_pBinding);

		if (m_pClosure == nullptr)
			return false;

		if (ffi_prep_cif(pCif, FFI_DEFAULT_ABI, argc, &ffi_type_pointer, ppArgs) != FFI_OK)
			return false;

		if (ffi_prep_closure_loc(pClosure, pCif, bindingFn, this, m_pBinding) != FFI_OK)
			return false;

		return true;
	}

}