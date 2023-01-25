#pragma once

#include "./DXGIHook.hpp"

#include <functional>
#include <memory>
#include <mutex>

#pragma comment(lib, "d3d10.lib")
#pragma comment(lib, "dxgi")

#include <d3d10_1.h>
#include <dxgi.h>

#include "../utility/FunctionHook.hpp"

#define D3D10HOOK_INTERNAL(X) RHook::D3D10Hook::SkipDetours([&]() X)

namespace RHook {
	class D3D10Hook : public DXGIHook {
	public:
		D3D10Hook() = delete;
		D3D10Hook(const D3D10Hook& other) = delete;
		D3D10Hook(D3D10Hook&& other) = delete;
		D3D10Hook(std::recursive_mutex* hookMutex);
		virtual ~D3D10Hook();

		bool Hook();
		bool Unhook();

		static const auto& IsHooked() { return s_Hooked; }

		D3D10Hook& operator=(const D3D10Hook& other) = delete;
		D3D10Hook& operator=(D3D10Hook&& other) = delete;

	private:
		inline static bool s_Hooked{ false };
	};
}