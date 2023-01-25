#pragma once

#include "./DXGIHook.hpp"

#include <functional>
#include <memory>
#include <mutex>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi")

#include <d3d11.h>
#include <dxgi.h>

#include "../utility/FunctionHook.hpp"

#define D3D11HOOK_INTERNAL(X) RHook::D3D11Hook::SkipDetours([&]() X)

namespace RHook {
    class D3D11Hook : public DXGIHook {
    public:
        D3D11Hook() = delete;
        D3D11Hook(const D3D11Hook& other) = delete;
        D3D11Hook(D3D11Hook&& other) = delete;
        D3D11Hook(std::recursive_mutex* hookMutex);
        virtual ~D3D11Hook();

        bool Hook();
        bool Unhook();

        static const auto& IsHooked() { return s_Hooked; }

        D3D11Hook& operator=(const D3D11Hook& other) = delete;
        D3D11Hook& operator=(D3D11Hook&& other) = delete;

    protected:
        inline static bool s_Hooked{ false };
    };
}