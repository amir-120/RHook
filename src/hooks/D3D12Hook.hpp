#pragma once

#include "./DXGIHook.hpp"

#include <functional>
#include <memory>
#include <mutex>

#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dxgi")

#include <d3d12.h>
#include <dxgi1_4.h>

#include "../utility/FunctionHook.hpp"

#define D3D12HOOK_INTERNAL(X) RHook::D3D12Hook::SkipDetours([&]() X)

namespace RHook {
    class D3D12Hook : public DXGIHook {
    public:
        D3D12Hook() = delete;
        D3D12Hook(const D3D12Hook& other) = delete;
        D3D12Hook(D3D12Hook&& other) = delete;
        D3D12Hook(std::recursive_mutex* hookMutex);
        virtual ~D3D12Hook();

        bool Hook();
        bool Unhook();

        ID3D12CommandQueue* ReloadCommandQueue(IDXGISwapChain* swapChain);

        ID3D12CommandQueue* GetCommandQueue() const { return m_CommandQueue; }
        static const auto& IsHooked() { return s_Hooked; }

        bool IsProtonSwapchain() const { return m_IsUsingProtonSwapChain; }

        D3D12Hook& operator=(const D3D12Hook& other) = delete;
        D3D12Hook& operator=(D3D12Hook&& other) = delete;

    protected:
        ID3D12CommandQueue* m_CommandQueue{ nullptr };

        std::vector<uint64_t> m_CommandQueueOffsetList{};
        uint64_t m_CommandQueueOffset{ 0 };
        uint64_t m_ProtonSwapchainOffset{ 0 };

        bool m_IsUsingProtonSwapChain{ false };
        inline static bool s_Hooked{ false };
    };
}