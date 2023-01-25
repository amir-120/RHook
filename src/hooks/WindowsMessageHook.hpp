#pragma once

#include <type_traits>
#include <functional>
#include <windows.h>
#include <assert.h>

// This type of hook replaces a windows message procedure so that it can intercept
// messages sent to the window.
class WindowsMessageHook {
public:
    typedef std::function<void(WindowsMessageHook&)> OnMessageFn;

    WindowsMessageHook() = delete;
    WindowsMessageHook(const WindowsMessageHook& other) = delete;
    WindowsMessageHook(WindowsMessageHook&& other) = delete;
    WindowsMessageHook(HWND hWnd);
    virtual ~WindowsMessageHook();

    auto& GetWNDPROCParams() { 
        assert(s_pWindowProcParams != nullptr, "Tried to access hook parameters outside call!"); 
        return *s_pWindowProcParams; 
    }

    auto& GetWNDPROCResult() {
		assert(s_pWindowProcResult != nullptr, "Tried to access hook result outside hook call!");
		return *s_pWindowProcResult;
    }

    void SignalExecuteOriginalProcedure(const bool& execute) { m_ExecuteOriginal = execute; }

    void OnPreMessage(OnMessageFn fn) { m_OnPreMessage = fn; }
    void OnPostMessage(OnMessageFn fn) { m_OnPostMessage = fn; }

    // This gets called automatically by the destructor but you can call it
    // explicitly if you need to remove the message hook for some reason.
    bool Remove();

    auto IsValid() const {
        return m_OriginalProc != nullptr;
    }

    auto GetOriginal() const {
        return m_OriginalProc;
    }

    WindowsMessageHook& operator=(const WindowsMessageHook& other) = delete;
    WindowsMessageHook& operator=(const WindowsMessageHook&& other) = delete;

private:
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

	struct WindowProcParameters_t {
        RWrapper<HWND> hWnd;
        RWrapper<UINT> Msg;
        RWrapper<WPARAM> wParam;
        RWrapper<LPARAM> lParam;
	};

    OnMessageFn m_OnPreMessage{ nullptr }, m_OnPostMessage{ nullptr };

    inline static WindowProcParameters_t* s_pWindowProcParams{ nullptr };
    inline static LRESULT* s_pWindowProcResult{ nullptr };

    HWND m_hWnd{ nullptr };
    WNDPROC m_OriginalProc{ nullptr };
    inline static bool m_ExecuteOriginal{ true };

    static LRESULT WINAPI WindowProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
};