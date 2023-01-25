#include "WindowsMessageHook.hpp"

#include "Log/Logging.hpp"

using namespace std;

static WindowsMessageHook* g_WindowsMessageHook{ nullptr };
std::recursive_mutex g_ProcMutex{};

thread_local size_t g_WMSGCallDepthWindowProc = {};
LRESULT WINAPI WindowsMessageHook::WindowProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
    std::lock_guard _{ g_ProcMutex };
 
    static WindowProcParameters_t tmpParams = { hWnd, Msg, wParam, lParam };
    static LRESULT tmpResult = {};

    tmpParams = { hWnd, Msg, wParam, lParam };

    if (g_WMSGCallDepthWindowProc == 0) {
		s_pWindowProcParams = &tmpParams;
		s_pWindowProcResult = &tmpResult;
	}

	g_WMSGCallDepthWindowProc++;

    if (g_WindowsMessageHook == nullptr) {
        return 0;
    }

    if (g_WindowsMessageHook->m_OnPreMessage) {
        g_WindowsMessageHook->m_OnPreMessage(*g_WindowsMessageHook);
    }

	// Call the original message procedure if user wants to
	if (m_ExecuteOriginal) {
		tmpResult = CallWindowProc(g_WindowsMessageHook->m_OriginalProc, hWnd, Msg, wParam, lParam);
	}
	else {
		tmpResult = DefWindowProc(hWnd, Msg, wParam, lParam);
		m_ExecuteOriginal = true;
	}

	if (g_WindowsMessageHook->m_OnPostMessage) {
        g_WindowsMessageHook->m_OnPostMessage(*g_WindowsMessageHook);
	}

    if (g_WMSGCallDepthWindowProc == 0) {
        s_pWindowProcResult = nullptr;
        s_pWindowProcParams = nullptr;
    }

	g_WMSGCallDepthWindowProc--;

    return tmpResult;
}

WindowsMessageHook::WindowsMessageHook(HWND hWnd)
    : m_hWnd{ hWnd }
{
    RH_RHOOK_INFO("[WINDOWS MESSAGE HOOK] Initializing WindowsMessageHook!");

    g_WindowsMessageHook = this;

    // Save the original window procedure.
    m_OriginalProc = (WNDPROC)GetWindowLongPtr(m_hWnd, GWLP_WNDPROC);

    // Set it to our "hook" procedure.
    SetWindowLongPtr(m_hWnd, GWLP_WNDPROC, (LONG_PTR)&WindowProc);

    RH_RHOOK_INFO("[WINDOWS MESSAGE HOOK] Hooked Windows message handler!");
}

WindowsMessageHook::~WindowsMessageHook() {
    std::lock_guard _{ g_ProcMutex };

    Remove();
    g_WindowsMessageHook = nullptr;
}

bool WindowsMessageHook::Remove() {
    // Don't attempt to restore invalid original window procedures.
    if (m_OriginalProc == nullptr || m_hWnd == nullptr) {
        return true;
    }

    // Restore the original window procedure.
    SetWindowLongPtr(m_hWnd, GWLP_WNDPROC, (LONG_PTR)m_OriginalProc);

    // Invalidate this message hook.
    m_hWnd = nullptr;
    m_OriginalProc = nullptr;

    return true;
}