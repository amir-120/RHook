#include <RHook/utility/MidFunctionHook.hpp>


#define NOMINMAX
#include <windows.h>
#include <detours.h>

#include <log/Logging.hpp>

extern bool g_IsMSDetoursInitialized;

namespace RHook {

	inline size_t AlignUp(size_t value, size_t align) { return value + align - 1 & ~(align - 1); }
	inline size_t AlignDown(size_t value, size_t align) { return value & ~(align - 1); }

	MidHookCodeBlock::~MidHookCodeBlock()
	{
		// Deallocate the code
		if(m_Address != nullptr)
			::VirtualFree(m_Address, 0, MEM_RELEASE);

		// Free the argument memory
		if (m_ppArguments != nullptr)
			delete m_ppArguments;

		// Free the return value
		if (m_pReturnValue != nullptr)
			delete m_pReturnValue.As<void*>();
	}

	void MidHookCodeBlock::AllocateCode(Address closeTo /*= nullptr*/, size_t align /*= 0*/)
	{
		::SYSTEM_INFO sysInfo{};
		::GetSystemInfo(&sysInfo);

		const auto allocationSize = AlignUp(sizeof(s_ShellCode), align == 0 ? sysInfo.dwAllocationGranularity : align);

		auto searchStart = sysInfo.lpMinimumApplicationAddress;
		auto searchEnd = sysInfo.lpMaximumApplicationAddress;
		Address wantedAddress = AlignUp(closeTo, sysInfo.dwAllocationGranularity);

		MEMORY_BASIC_INFORMATION mbi{};

		// Backwards search from the wanted address
		for (auto pCurrent = wantedAddress.As<uint8_t*>(); pCurrent > searchStart && pCurrent < searchEnd;
			pCurrent = (uint8_t*)AlignDown(Address(mbi.AllocationBase).Get(-1), sysInfo.dwAllocationGranularity)) {

			if (::VirtualQuery(pCurrent, &mbi, sizeof(mbi)) == 0) 
				break;

			if (mbi.State != MEM_FREE)
				continue;

			auto allocated = ::VirtualAlloc(pCurrent, allocationSize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

			if (allocated != nullptr) {
				// Copy the code in place
				memcpy(allocated, s_ShellCode, sizeof(s_ShellCode));

				// Fill in the members
				m_Address = allocated;
				m_Start = m_Address.Get(4 * sizeof(size_t)); // The code starts after the 4 offsets at the beginning
				m_End = m_Address.Get(allocationSize);

				// Done allocating, return
				return;
			}
		}

		// Forward search from the wanted address
		for (auto pCurrent = wantedAddress.As<uint8_t*>(); pCurrent > searchStart && pCurrent < searchEnd; pCurrent += mbi.RegionSize) {
			
			if (::VirtualQuery(pCurrent, &mbi, sizeof(mbi)) == 0)
				break;

			if (mbi.State != MEM_FREE)
				continue;

			auto allocated = ::VirtualAlloc(pCurrent, allocationSize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

			if (allocated != nullptr) {
				// Copy the code in place
				memcpy(allocated, s_ShellCode, sizeof(s_ShellCode));

				// Fill in the members
				m_Address = allocated;
				m_Start = m_Address.Get(4 * sizeof(size_t)); // The code starts after the 4 offsets at the beginning
				m_End = m_Address.Get(allocationSize);

				// Done allocating, return
				return;
			}
		}
	}

	bool MidHookCodeBlock::LoadShellCodeVariableAddresses()
	{
		using Offset_t = size_t;

		// Make sure we have a valid allocation of the code
		if (!m_Address)
			return false;

		// Array of 4 offsets at the beginning of the allocated block
		auto offsets = m_Address.As<Offset_t*>();

		// 0->contextOffset
		// 1->thisPtrOffset
		// 2->callWrapperOffset
		// 3->trampolineOffset

		m_ppContext			= m_Start.Get(offsets[0]).As<decltype(m_ppContext)>();
		m_ppThis			= m_Start.Get(offsets[1]).As<decltype(m_ppThis)>();
		m_pFnCallWrapper	= m_Start.Get(offsets[2]).As<decltype(m_pFnCallWrapper)>();
		m_ppTrampoline		= m_Start.Get(offsets[3]).As<decltype(m_ppTrampoline)>();

		return m_ppContext != nullptr && m_ppThis != nullptr && m_pFnCallWrapper != nullptr && m_ppTrampoline != nullptr;
	}

#ifdef _M_X64
	void MidHookCodeBlock::DefaultX64DecideArg(Context* pContext, Address* ppArguments, size_t index, bool vectorRegister) {
		switch (index) {
		case 0:
			if (vectorRegister) {
				ppArguments[0].Set(&pContext->XMM0);
			}
			else {
				ppArguments[0].Set(&pContext->RCX);
			}
			break;

		case 1:
			if (vectorRegister) {
				ppArguments[1].Set(&pContext->XMM1);
			}
			else {
				ppArguments[1].Set(&pContext->RDX);
			}
			break;

		case 2:
			if (vectorRegister) {
				ppArguments[2].Set(&pContext->XMM2);
			}
			else {
				ppArguments[2].Set(&pContext->R8);
			}
			break;

		case 3:
			if (vectorRegister) {
				ppArguments[3].Set(&pContext->XMM3);
			}
			else {
				ppArguments[3].Set(&pContext->R9);
			}
			break;

		default:
		{
			size_t i = index - 4;
			auto pushedArgs = (Address*)pContext->RSP;
			ppArguments[index] = pushedArgs[i];
		}
		break;
		}
	}
#else
#endif

	MidFunctionHook::~MidFunctionHook()
	{
		Unhook();
	}

	bool MidFunctionHook::Hook()
	{
		if (!m_Code->IsValid()) {
			RHOOK_WARN("[MID-FUNCTION HOOK] \"{:s}\" .Hook() called while while shell code is not allocated!", m_Name);
			return true;
		}

		if (m_Trampoline.Ptr() != nullptr) {
			RHOOK_WARN("[MID-FUNCTION HOOK] \"{:s}\" .Hook() called while the detour is already in place!", m_Name);
			return true;
		}

		std::scoped_lock _{ m_HookMutex };

		if (m_PreHookEnableCallback)
			m_PreHookEnableCallback(this);

		if (auto status = DetourTransactionBegin(); status != NO_ERROR) {
			RHOOK_ERROR("[MID-FUNCTION HOOK] \"{:s}\" Failed to hook {:p}: 0x{:x} on DetourTransactionBegin()", m_Name, m_Target.Ptr(), status);

			m_Destination.Set(nullptr);
			m_Target.Set(nullptr);
			m_Trampoline.Set(nullptr);
			return false;
		}

		if (auto status = DetourUpdateThread(GetCurrentThread()); status != NO_ERROR) {
			RHOOK_ERROR("[MID-FUNCTION HOOK] \"{:s}\" Failed to hook {:p}: 0x{:x} on DetourUpdateThread()", m_Name, m_Target.Ptr(), status);

			m_Destination.Set(nullptr);
			m_Target.Set(nullptr);
			m_Trampoline.Set(nullptr);

			if (auto status = DetourTransactionCommit(); status != NO_ERROR) {
				RHOOK_ERROR("[MID-FUNCTION HOOK] \"{:s}\" Failed to hook {:p}: 0x{:x} on DetourTransactionCommit()", m_Name, m_Target.Ptr(), status);
			}

			return false;
		}

		m_Trampoline = m_Target;

		if (auto status = DetourAttach(&m_Trampoline.As<LPVOID>(), m_Code->GetCodeAddress().As<LPVOID>()); status != NO_ERROR) {
			RHOOK_ERROR("[MID-FUNCTION HOOK] \"{:s}\" Failed to hook {:p}: 0x{:x} on DetourAttach()", m_Name, m_Target.Ptr(), status);

			m_Destination.Set(nullptr);
			m_Target.Set(nullptr);
			m_Trampoline.Set(nullptr);

			if (auto status = DetourTransactionCommit(); status != NO_ERROR) {
				RHOOK_ERROR("[MID-FUNCTION HOOK] \"{:s}\" Failed to hook {:p}: 0x{:x} on DetourTransactionCommit()", m_Name, m_Target.Ptr(), status);
			}

			return false;
		}

		if (auto status = DetourTransactionCommit(); status != NO_ERROR) {
			RHOOK_ERROR("[MID-FUNCTION HOOK] \"{:s}\" Failed to hook {:p}: 0x{:x} on DetourTransactionCommit()", m_Name, m_Target.Ptr(), status);

			m_Destination.Set(nullptr);
			m_Target.Set(nullptr);
			m_Trampoline.Set(nullptr);
			return false;
		}

		RHOOK_INFO("[MID-FUNCTION HOOK] \"{:s}\" Hooked {:p}->{:p}", m_Name, m_Target.Ptr(), m_Destination.Ptr());

		m_IsEnabled = true;

		if (m_PostHookEnableCallback)
			m_PostHookEnableCallback(this);

		return true;
	}

	bool MidFunctionHook::Create()
	{
		std::scoped_lock _{ m_HookMutex };

		if (!m_Code->IsValid()) {
			RHOOK_ERROR("[MID-FUNCTION HOOK] \"{:s}\" .Create() called while shell code is not allocated!", m_Name.c_str());

			return false;
		}

		if (!g_IsMSDetoursInitialized) {
			if (DetourIsHelperProcess() == TRUE) {
				if (DetourRestoreAfterWith() == TRUE) {
					RHOOK_INFO("[MID-FUNCTION HOOK] MS Detours initialized successfully.");
				}
				else {
					RHOOK_ERROR("[MID-FUNCTION HOOK] MS Detours failed to initiliaze.");

					return false;
				}
			}

			g_IsMSDetoursInitialized = true;
			RHOOK_INFO("[MID-FUNCTION HOOK] MS Detours initialized successfully.");
		}

		if (m_Target == nullptr || m_Destination == nullptr || m_Trampoline != nullptr) {
			RHOOK_ERROR("[MID-FUNCTION HOOK] \"{:s}\" Detour not initialized!", m_Name.c_str());
			return false;
		}

		RHOOK_INFO("[MID-FUNCTION HOOK] \"{:s}\" Detour added {:p}->{:p}", m_Name.c_str(), m_Target.Ptr(), m_Destination.Ptr());

		return true;
	}

	bool MidFunctionHook::Unhook()
	{
		if (!m_Code->IsValid()) {
			RHOOK_WARN("[MID-FUNCTION HOOK] \"{:s}\" .Unhook() called while while shell code is not allocated!", m_Name);
			return true;
		}

		if (m_Trampoline.Ptr() == nullptr) {
			RHOOK_WARN("[MID-FUNCTION HOOK] \"{:s}\" .Hook() called while the detour is not placed!", m_Name);
			return true;
		}

		std::scoped_lock _{ m_HookMutex };

		if (m_PreHookDisableCallback)
			m_PreHookDisableCallback(this);

		// Don't try to remove invalid hooks.
		if (m_Target == nullptr || m_Destination == nullptr || m_Target == nullptr) {
			return true;
		}

		if (auto status = DetourTransactionBegin(); status != NO_ERROR) {
			RHOOK_ERROR("[MID-FUNCTION HOOK] \"{:s}\" Failed to unhook {:p}: 0x{:x} on DetourTransactionBegin()", m_Name, m_Target.Ptr(), status);

			return false;
		}

		if (auto status = DetourUpdateThread(GetCurrentThread()); status != NO_ERROR) {
			RHOOK_ERROR("[MID-FUNCTION HOOK] \"{:s}\" Failed to unhook {:p}: 0x{:x} on DetourUpdateThread()", m_Name, m_Target.Ptr(), status);

			if (auto status = DetourTransactionCommit(); status != NO_ERROR) {
				RHOOK_ERROR("[MID-FUNCTION HOOK] \"{:s}\" Failed to unhook {:p}: 0x{:x} on DetourTransactionCommit()", m_Name, m_Target.Ptr(), status);
			}

			return false;
		}

		if (auto status = DetourDetach(&m_Trampoline.As<LPVOID>(), m_Code->GetCodeAddress().As<LPVOID>()); status != NO_ERROR) {
			RHOOK_ERROR("[MID-FUNCTION HOOK] \"{:s}\" Failed to unhook {:p}: 0x{:x} on DetourDetach()", m_Name, m_Target.Ptr(), status);

			if (auto status = DetourTransactionCommit(); status != NO_ERROR) {
				RHOOK_ERROR("[MID-FUNCTION HOOK] \"{:s}\" Failed to unhook {:p}: 0x{:x} on DetourTransactionCommit()", m_Name, m_Target.Ptr(), status);
			}

			return false;
		}

		if (auto status = DetourTransactionCommit(); status != NO_ERROR) {
			RHOOK_ERROR("[MID-FUNCTION HOOK] \"{:s}\" Failed to unhook {:p}: 0x{:x} on DetourTransactionCommit()", m_Name, m_Target.Ptr(), status);

			return false;
		}

		m_Trampoline.Set(nullptr);

		RHOOK_INFO("[MID-FUNCTION HOOK] \"{:s}\" Unhooked {:p}, Previous detour: {:p}", m_Name, m_Target.Ptr(), m_Destination.Ptr());

		m_IsEnabled = false;

		if (m_PostHookDisableCallback)
			m_PostHookDisableCallback(this);

		return true;
	}

	bool MidFunctionHook::Toggle()
	{
		return Toggle(!m_IsEnabled);
	}

	bool MidFunctionHook::Toggle(bool state)
	{
		if (state)
			Hook();
		else
			Unhook();

		return m_IsEnabled;
	}

	void MidFunctionHook::Initialize()
	{
		RHOOK_INFO("[MID-FUNCTION HOOK] \"{:s}\" Setting up a hook on {:p}->{:p}", m_Name.c_str(), m_Target.Ptr(), m_Destination.Ptr());

		// Initialize the hook and place the detour
		if (Create()) {
			Hook();
		}

		// Copy the trampoline address into our shellcode we allocate
		m_Code->SetTrampoline(m_Trampoline);

		if (m_Code->IsReadyToExecute())
		{
			RHOOK_INFO("[MID-FUNCTION HOOK] \"{:s}\" Shellcode ready to be executed {:p}", m_Name.c_str(), m_Code->GetCodeAddress().Ptr());
		}
		else
		{
			RHOOK_INFO("[MID-FUNCTION HOOK] \"{:s}\" Failed to ready the shellcode for execution!", m_Name.c_str());

			return;
		}
	}

}