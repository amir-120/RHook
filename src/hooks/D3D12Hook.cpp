#include "D3D12Hook.hpp"
#include "D3DDXGIVMTIndices.hpp"

#include "Log/Logging.hpp"

namespace RHook {
    static D3D12Hook* g_D3D12Hook = nullptr;

    D3D12Hook::D3D12Hook(std::recursive_mutex* hookMutex)
        : DXGIHook(hookMutex)
    {}

    D3D12Hook::~D3D12Hook() {
        Unhook();
        g_D3D12Hook = nullptr;
    }

    bool D3D12Hook::Hook() {
        RH_RHOOK_INFO("Hooking D3D12");

        g_D3D12Hook = this;

        ComPtr<ID3D12Device> pDevice{};

        D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_11_0;

        // Manually get D3D12CreateDevice export because the user may be running Windows 7
        const auto d3d12Module = LoadLibrary("d3d12.dll");
        if (d3d12Module == nullptr) {
            RH_RHOOK_ERROR("D3D12: Failed to load d3d12.dll.");
            return false;
        }
        auto d3d12CreateDevice = (decltype(D3D12CreateDevice)*)GetProcAddress(d3d12Module, "D3D12CreateDevice");

        if (d3d12CreateDevice == nullptr) {
            RH_RHOOK_ERROR("D3D12: Failed to get D3D12CreateDevice export.");
            return false;
        }

        RH_RHOOK_INFO("D3D12: Creating Dummy Device");

        if (auto hr = d3d12CreateDevice(nullptr, featureLevel, IID_PPV_ARGS(&pDevice)); FAILED(hr)) {
            RH_RHOOK_ERROR("D3D12: Failed to create Dummy Device. ERROR: {:s}", WINCOM_ERROR(hr));
            return false;
        }

        // Manually get CreateDXGIFactory export because the user may be running Windows 7
        const auto dxgiModule = LoadLibrary("dxgi.dll");
        if (dxgiModule == nullptr) {
            RH_RHOOK_ERROR("D3D12: Failed to load dxgi.dll");
            return false;
        }

        auto createDXGIFactory = (decltype(CreateDXGIFactory)*)GetProcAddress(dxgiModule, "CreateDXGIFactory");

        if (createDXGIFactory == nullptr) {
            RH_RHOOK_ERROR("D3D12: Failed to get CreateDXGIFactory export.");
            return false;
        }

        RH_RHOOK_INFO("D3D12: Creating Dummy DXGI Factory.");

        ComPtr<IDXGIFactory4> pFactory{};
        if (auto hr = createDXGIFactory(IID_PPV_ARGS(&pFactory)); FAILED(hr)) {
            RH_RHOOK_ERROR("D3D12: Failed to create Dummy DXGI Factory. ERROR: {:s}", WINCOM_ERROR(hr));
            return false;
        }

        D3D12_COMMAND_QUEUE_DESC queueDesc;
        queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
        queueDesc.Priority = 0;
        queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
        queueDesc.NodeMask = 0;

        RH_RHOOK_INFO("D3D12: Creating Dummy CommandQueue.");

        ComPtr<ID3D12CommandQueue> pCommandQueue{};
        if (auto hr = pDevice->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&pCommandQueue)); FAILED(hr)) {
            RH_RHOOK_ERROR("D3D12: Failed to create Dummy CommandQueue. ERROR: {:s}", WINCOM_ERROR(hr));
            return false;
        }

        if (!HookDXGI(pCommandQueue.Get())) {
            RH_RHOOK_ERROR("D3D12: Failed to hook DXGI.");
            return false;
        }

        const auto pSwapChain = m_PSwapChain.Get();

        RH_RHOOK_INFO("D3D12: Finding CommandQueue offset.");

        // Find the command queue offset in the swapchain
        //m_commandQueueOffset = (uintptr_t)std::find((uintptr_t*)swapChain, (uintptr_t*)((uintptr_t)swapChain + 512), (uintptr_t)commandQueue) - (uintptr_t)swapChain; //1 byte aigned search

        m_CommandQueueOffsetList.reserve(5);

        if (pSwapChain == nullptr) {
            RH_RHOOK_ERROR("D3D12: Invalid dummy SwapChain.");
            return false;
        }

        for (size_t i = 0; i < 512 * sizeof(void*); i += sizeof(void*)) { //8 byte aligned search for x64 and 4 for x86
            const auto base = (uintptr_t)pSwapChain + i;

            // reached the end
            if (IsBadReadPtr((void*)base, sizeof(void*))) {
                break;
            }

            auto data = *(ID3D12CommandQueue**)base;

            if (data == pCommandQueue.Get()) {
                m_CommandQueueOffsetList.push_back(i);
                RH_RHOOK_INFO("D3D12: Found CommandQueue offset: {:x}", i);
            }
        }

        // Scan throughout the swapchain for a valid pointer to scan through
        // this is usually only necessary for Proton
        if (m_CommandQueueOffsetList.empty()) {
            for (uintptr_t base = 0; base < 512 * sizeof(void*); base += sizeof(void*)) { //8 byte aligned search
                const auto preScanBase = (uintptr_t)pSwapChain + base;

                // reached the end
                if (IsBadReadPtr((void*)preScanBase, sizeof(void*))) {
                    break;
                }

                const auto scanBase = *(uintptr_t*)preScanBase;

                if (scanBase == 0 || IsBadReadPtr((void*)scanBase, sizeof(void*))) {
                    continue;
                }

                for (size_t i = 0; i < 512 * sizeof(void*); i += sizeof(void*)) {
                    const auto preData = scanBase + i;

                    if (IsBadReadPtr((void*)preData, sizeof(void*))) {
                        break;
                    }

                    auto data = *(ID3D12CommandQueue**)preData;

                    if (data == pCommandQueue.Get()) {
                        m_IsUsingProtonSwapChain = true;
                        m_CommandQueueOffsetList.push_back(i);
                        m_ProtonSwapchainOffset = base;

                        RH_RHOOK_INFO("D3D12: Proton potentially detected.");
                        RH_RHOOK_INFO("D3D12: Found command queue offset: {:x}", i);
                    }
                }

                if (m_IsUsingProtonSwapChain) {
                    break;
                }
            }
        }

        pDevice.Reset();
        pCommandQueue.Reset();
        ReleaseDXGI();

        s_Hooked = s_IsDXGIHooked;//&& m_createSwapChainHook->Create()'

        if (!s_Hooked) {
            // Call unhook just to be sure all hooks are removed.
            Unhook();

            return false;
        }

        return s_Hooked;
    }

    bool D3D12Hook::Unhook() {
        return UnhookDXGI();
    }

    ID3D12CommandQueue* D3D12Hook::ReloadCommandQueue(IDXGISwapChain* swapChain) {
        const auto& d3d12 = g_D3D12Hook;

        // Get the CommandQueue that is being used by the application we want to hook
        {
            ID3D12Device4* device = nullptr;
            swapChain->GetDevice(IID_PPV_ARGS(&device));


            if (device != nullptr) {
                if (d3d12->m_IsUsingProtonSwapChain) {
                    const auto realSwapChain = *(uintptr_t*)((uintptr_t)swapChain + d3d12->m_ProtonSwapchainOffset);

                    if (d3d12->m_CommandQueue == nullptr) {
                        for (const auto& cmdQueueOffset : d3d12->m_CommandQueueOffsetList) {
                            if (const auto cmdQueueTmp = *(ID3D12CommandQueue**)(realSwapChain + cmdQueueOffset); !IsBadReadPtr(cmdQueueTmp, sizeof(cmdQueueTmp)))
                            {
                                d3d12->m_CommandQueueOffset = cmdQueueOffset;
                                RH_RHOOK_INFO("D3D12: Using Proton CommandQueue offset: {:x}", d3d12->m_CommandQueueOffset);

                                break;
                            }
                        }
                    }

                    d3d12->m_CommandQueue = *(ID3D12CommandQueue**)(realSwapChain + d3d12->m_CommandQueueOffset);
                }
                else {
                    if (d3d12->m_CommandQueue == nullptr) {
                        for (const auto& cmdQueueOffset : d3d12->m_CommandQueueOffsetList) {
                            if (const auto cmdQueueTmp = *(ID3D12CommandQueue**)((uintptr_t)swapChain + cmdQueueOffset); !IsBadReadPtr(cmdQueueTmp, sizeof(cmdQueueTmp)))
                            {
                                d3d12->m_CommandQueueOffset = cmdQueueOffset;
                                RH_RHOOK_INFO("D3D12: Using CommandQueue offset: {:x}", d3d12->m_CommandQueueOffset);

                                break;
                            }
                        }
                    }

                    d3d12->m_CommandQueue = *(ID3D12CommandQueue**)((uintptr_t)swapChain + d3d12->m_CommandQueueOffset);
                }
            }
        }

        return m_CommandQueue;
    }
}