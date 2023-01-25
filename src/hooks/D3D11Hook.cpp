#include "D3D11Hook.hpp"
#include "D3DDXGIVMTIndices.hpp"

#include "Log/Logging.hpp"

namespace RHook {
    static D3D11Hook* g_d3d11Hook = nullptr;

    D3D11Hook::D3D11Hook(std::recursive_mutex* hookMutex)
        : DXGIHook(hookMutex)
    {}

    D3D11Hook::~D3D11Hook() {
        Unhook();
        g_d3d11Hook = nullptr;
    }

    bool D3D11Hook::Hook() {
        RH_RHOOK_INFO("Hooking D3D11");

        g_d3d11Hook = this;

        ComPtr<ID3D11Device> pDevice{};
        ComPtr<ID3D11DeviceContext> pContext{};

        D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_11_0;

        // Manually get D3D11CreateDeviceAndSwapChain export
        const auto d3d11Module = LoadLibrary("d3d11.dll");
        if (d3d11Module == nullptr) {
            RH_RHOOK_ERROR("D3D11: Failed to load d3d11.dll.");
            return false;
        }
        auto d3d11CreateDevice = (decltype(D3D11CreateDevice)*)GetProcAddress(d3d11Module, "D3D11CreateDevice");

        if (d3d11CreateDevice == nullptr) {
            RH_RHOOK_ERROR("D3D11: Failed to get the D3D11CreateDevice() export.");
            return false;
        }

        UINT createDeviceFlags = 0;
        //createDeviceFlags |= D3D10_CREATE_DEVICE_DEBUG;
        if (auto hr = d3d11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr,
            createDeviceFlags, &featureLevel, 1, D3D11_SDK_VERSION,
            &pDevice, nullptr, &pContext); FAILED(hr)) {
            RH_RHOOK_ERROR("D3D11: Failed to create D3D11 device. ERROR: {:s}", WINCOM_ERROR(hr));
            return false;
        }

        if (!HookDXGI(pDevice.Get())) {
            RH_RHOOK_ERROR("D3D11: Failed to hook DXGI.");
            return false;
        }

        pDevice.Reset();
        pContext.Reset();
        ReleaseDXGI();

        s_Hooked = s_IsDXGIHooked;

        if (!s_Hooked) {
            // Call unhook just to be sure all hooks are removed.
            Unhook();

            return false;
        }

        return s_Hooked;
    }

    bool D3D11Hook::Unhook() {
        return UnhookDXGI();
    }
}