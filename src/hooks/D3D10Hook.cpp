#include "D3D10Hook.hpp"
#include "D3DDXGIVMTIndices.hpp"

#include "Log/Logging.hpp"

namespace RHook {
	static D3D10Hook* g_D3D10Hook = nullptr;

	D3D10Hook::D3D10Hook(std::recursive_mutex* hookMutex)
		: DXGIHook(hookMutex)
	{}

	D3D10Hook::~D3D10Hook() {
		Unhook();
		g_D3D10Hook = nullptr;
	}

	bool D3D10Hook::Hook() {
		RH_RHOOK_INFO("Hooking D3D10");

		g_D3D10Hook = this;

		ComPtr<ID3D10Device> pDevice{};

		// Manually get D3D10CreateDeviceAndSwapChain export
		const auto d3d10Module = LoadLibrary("d3d10.dll");
		if (d3d10Module == nullptr) {
			RH_RHOOK_ERROR("D3D10: Failed to load d3d10.dll.");
			return false;
		}
		auto d3d10CreateDevice = (decltype(D3D10CreateDevice)*)GetProcAddress(d3d10Module, "D3D10CreateDevice");

		if (d3d10CreateDevice == nullptr) {
			RH_RHOOK_ERROR("D3D10: Failed to get D3D10CreateDevuce() export.");
			return false;
		}

		UINT createDeviceFlags = 0;
		//createDeviceFlags |= D3D10_CREATE_DEVICE_DEBUG;
		if (auto hr = d3d10CreateDevice(nullptr, D3D10_DRIVER_TYPE_HARDWARE, nullptr,
			createDeviceFlags, D3D10_SDK_VERSION, &pDevice); FAILED(hr)) {
			RH_RHOOK_ERROR("D3D10: Failed to create device. ERROR: {:s}", WINCOM_ERROR(hr));
			return false;
		}

		if (!HookDXGI(pDevice.Get())) {
			RH_RHOOK_ERROR("D3D10: Failed to hook DXGI.");
			return false;
		}

		pDevice.Reset();
		ReleaseDXGI();

		s_Hooked = s_IsDXGIHooked;

		if (!s_Hooked) {
			// Call unhook just to be sure all hooks are removed.
			Unhook();

			return false;
		}

		return s_Hooked;
	}

	bool D3D10Hook::Unhook() {
		return UnhookDXGI();
	}
}