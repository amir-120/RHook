#include "FunctionHook.hpp"
#include "Log/Logging.hpp"

#include <detours.h>

namespace RHook {
	FunctionHook::FunctionHook(Address target, Address destination)
	{
		RH_RHOOK_INFO("[FUNCTION HOOK] Setting up a hook on {:p}->{:p}", target.Ptr(), destination.Ptr());

		// Create the hook. Call create afterwards to prevent race conditions accessing FunctionHook before it leaves its constructor.
		m_Target = target;
		m_Destination = destination;
	}


	FunctionHook::FunctionHook(Address target, Address destination, std::string_view name)
		: m_Name{ name }
	{
		RH_RHOOK_INFO("[FUNCTION HOOK] \"{:s}\" Setting up a hook on {:p}->{:p}", m_Name.empty() ? "Unnamed" : m_Name.c_str(), target.Ptr(), destination.Ptr());

		// Create the hook. Call create afterwards to prevent race conditions accessing FunctionHook before it leaves its constructor.
		m_Target = target;
		m_Destination = destination;
	}

	FunctionHook::~FunctionHook() {
		Remove();
	}

	bool FunctionHook::Create() {
		if (m_Target == 0 || m_Destination == 0 || m_Original != 0) {
			RH_RHOOK_ERROR("[FUNCTION HOOK] \"{:s}\" Hook not initialized", m_Name.empty() ? "Unnamed" : m_Name.c_str());
			return false;
		}

		if (auto status = DetourTransactionBegin(); status != NO_ERROR) {
			RH_RHOOK_ERROR("[FUNCTION HOOK] \"{:s}\" Failed to hook {:p}: 0x{:x} on DetourTransactionBegin()", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, status);

			m_Destination = 0;
			m_Target = 0;
			m_Original = 0;
			return false;
		}

		if (auto status = DetourUpdateThread(GetCurrentThread()); status != NO_ERROR) {
			RH_RHOOK_ERROR("[FUNCTION HOOK] \"{:s}\" Failed to hook {:p}: 0x{:x} on DetourUpdateThread()", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, status);

			m_Destination = 0;
			m_Target = 0;
			m_Original = 0;

			if (auto status = DetourTransactionCommit(); status != NO_ERROR) {
				RH_RHOOK_ERROR("[FUNCTION HOOK] \"{:s}\" Failed to hook {:p}: 0x{:x} on DetourTransactionCommit()", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, status);
			}

			return false;
		}

		m_Original = m_Target;

		if (auto status = DetourAttach(&m_Original, m_Destination); status != NO_ERROR) {
			RH_RHOOK_ERROR("[FUNCTION HOOK] \"{:s}\" Failed to hook {:p}: 0x{:x} on DetourAttach()", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, status);

			m_Destination = 0;
			m_Target = 0;
			m_Original = 0;

			if (auto status = DetourTransactionCommit(); status != NO_ERROR) {
				RH_RHOOK_ERROR("[FUNCTION HOOK] \"{:s}\" Failed to hook {:p}: 0x{:x} on DetourTransactionCommit()", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, status);
			}

			return false;
		}

		if (auto status = DetourTransactionCommit(); status != NO_ERROR) {
			RH_RHOOK_ERROR("[FUNCTION HOOK] \"{:s}\" Failed to hook {:p}: 0x{:x} on DetourTransactionCommit()", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, status);

			m_Destination = 0;
			m_Target = 0;
			m_Original = 0;
			return false;
		}

		RH_RHOOK_INFO("[FUNCTION HOOK] \"{:s}\" Hooked {:p}->{:p}", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, m_Destination);
		return true;
	}


	bool FunctionHook::Unhook()
	{
		// Don't try to remove invalid hooks.
		if (m_Target == 0 || m_Destination == 0 || m_Original == 0 || m_Original == m_Target) {
			return true;
		}

		if (auto status = DetourTransactionBegin(); status != NO_ERROR) {
			RH_RHOOK_ERROR("[FUNCTION HOOK] \"{:s}\" Failed to unhook {:p}: 0x{:x} on DetourTransactionBegin()", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, status);

			return false;
		}

		if (auto status = DetourUpdateThread(GetCurrentThread()); status != NO_ERROR) {
			RH_RHOOK_ERROR("[FUNCTION HOOK] \"{:s}\" Failed to unhook {:p}: 0x{:x} on DetourUpdateThread()", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, status);

			if (auto status = DetourTransactionCommit(); status != NO_ERROR) {
				RH_RHOOK_ERROR("[FUNCTION HOOK] \"{:s}\" Failed to unhook {:p}: 0x{:x} on DetourTransactionCommit()", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, status);
			}

			return false;
		}

		if (auto status = DetourDetach(&m_Original, m_Destination); status != NO_ERROR) {
			RH_RHOOK_ERROR("[FUNCTION HOOK] \"{:s}\" Failed to unhook {:p}: 0x{:x} on DetourDetach()", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, status);

			if (auto status = DetourTransactionCommit(); status != NO_ERROR) {
				RH_RHOOK_ERROR("[FUNCTION HOOK] \"{:s}\" Failed to unhook {:p}: 0x{:x} on DetourTransactionCommit()", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, status);
			}

			return false;
		}

		if (auto status = DetourTransactionCommit(); status != NO_ERROR) {
			RH_RHOOK_ERROR("[FUNCTION HOOK] \"{:s}\" Failed to unhook {:p}: 0x{:x} on DetourTransactionCommit()", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, status);

			return false;
		}

		m_Original = 0;

		RH_RHOOK_INFO("[FUNCTION HOOK] \"{:s}\" Unhooked {:p}, Previous detour: {:p}", m_Name.empty() ? "Unnamed" : m_Name.c_str(), m_Target, m_Destination);
		return true;
	}

	bool FunctionHook::Remove() {
		// Save away for logging
		auto target = m_Target;

		// Unhook.
		if (!Unhook()) {
			RH_RHOOK_INFO("[FUNCTION HOOK] \"{:s}\" Failed to remove hook: {:p}", m_Name.empty() ? "Unnamed" : m_Name.c_str(), target);
			return false;
		}

		RH_RHOOK_INFO("[FUNCTION HOOK] \"{:s}\" Removed hook: {:p}", m_Name.empty() ? "Unnamed" : m_Name.c_str(), target);

		// Invalidate the members.
		m_Target = 0;
		m_Destination = 0;

		return true;
	}
}