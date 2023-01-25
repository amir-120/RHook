#pragma once

#include "D3D9Hook.hpp"
#include "DXGIHook.hpp"
#include "D3D10Hook.hpp"
#include "D3D11Hook.hpp"
#include "D3D12Hook.hpp"
#include "OpenGLHook.hpp"
#include "VulkanHook.hpp"

#include <mutex>
#include <vector>
#include <string>
#include <functional>

namespace RHook {
	enum class APIType {
		Unknown = 0,
		Failed,
		D3D9,
		D3D10,
		D3D11,
		D3D12,
		OpenGL,
		Vulkan,
	};

	class PresentHook
	{
	public:
		enum class PresentType {
			D3D9 = 0,
			DXGI,
			OpenGL,
			Vulkan,
		};

		typedef std::function<void(APIType)> CallbackFn;

		PresentHook();
		PresentHook(const PresentHook& other) = delete;
		PresentHook(PresentHook&& other) = delete;
		virtual ~PresentHook();

		const auto& GetAPIType() const { return m_GraphicsAPI; }
		static const auto& IsHooked() { return s_Hooked; };

		void SetCallback(CallbackFn fn) { m_Callback = fn; }

		PresentHook& operator=(const PresentHook& other) = delete;
		PresentHook& operator=(PresentHook&& other) = delete;

	private:
		void ListAllModules();
		bool HookPresents();
		bool UnhookDetectionHooks();

		bool HookD3D9();
		bool HookDXGI();
		bool HookOpenGL();
		bool HookVulkan();

	private:
		APIType m_GraphicsAPI{ APIType::Unknown };
		inline static bool s_Hooked{ false };
		std::vector<std::string> m_ModuleNameList{};

		std::recursive_mutex m_HookMonitorMutex{};

		CallbackFn m_Callback{ nullptr };

		bool m_D3D9Loaded{ false };
		bool m_DXGILoaded{ false };
		bool m_D3D10Loaded{ false };
		bool m_D3D11Loaded{ false };
		bool m_D3D12Loaded{ false };
		bool m_OpenGLLoaded{ false };
		bool m_VulkanLoaded{ false };

		std::unique_ptr<D3D9Hook> m_D3D9Hook{};
		std::unique_ptr<D3D10Hook> m_D3D10Hook{};
		std::unique_ptr<D3D11Hook> m_D3D11Hook{};
		std::unique_ptr<D3D12Hook> m_D3D12Hook{};
		std::unique_ptr<OpenGLHook> m_OpenGLHook{};
		std::unique_ptr<VulkanHook> m_VulkanHook{};

		std::recursive_mutex m_FrameMutex{};
		std::recursive_mutex m_VkCreateInstanceMutex{};

	private:
		static void OnFrame(const PresentType& presentType);
		static void VulkanInstanceCreation();
	};
}