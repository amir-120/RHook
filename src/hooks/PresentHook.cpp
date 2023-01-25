#include "PresentHook.hpp"

#include "Log/Logging.hpp"

#include <wrl.h>
#include <Psapi.h>
#include <Oleacc.h>

namespace RHook {
	PresentHook* g_PresentHook{ nullptr };

	PresentHook::PresentHook()
	{
		RH_RHOOK_INFO("Hooking Presents to detect graphical api!");

		// Load the list of all modules loaded in the process 
		// to know what graphical APIs can be possibly in use
		ListAllModules();

		// Hook presentation functions of all APIs
		if (HookPresents()) {
			RH_RHOOK_INFO("All presentation function succesfully hooked for api detection!");
			s_Hooked = true;
		}
		else {
			g_PresentHook->m_GraphicsAPI = APIType::Failed;
			if (UnhookDetectionHooks()) {
				s_Hooked = false;
			}
			RH_RHOOK_ERROR("Failed to hook all presentation function for api detection!");
		}

		g_PresentHook = this;
	}

	PresentHook::~PresentHook()
	{
		m_D3D9Hook.reset();
		m_D3D10Hook.reset();
		m_D3D11Hook.reset();
		m_D3D12Hook.reset();
		m_OpenGLHook.reset();
		m_VulkanHook.reset();
		s_Hooked = false;
		g_PresentHook = nullptr;
	}

	void PresentHook::OnFrame(const PresentType& presentType)
	{
		std::scoped_lock _{ g_PresentHook->m_FrameMutex };

		RH_RHOOK_INFO("API detection Present hook called!");

		if (g_PresentHook->m_GraphicsAPI != APIType::Unknown) {
			RH_RHOOK_ERROR("API detection hook detour has been called again!");
			return;
		}

		switch (presentType) {
			// D3D9 has called the presentation function
		case PresentType::D3D9:
		{
			RH_RHOOK_INFO("Present type: D3D9");

			const auto& params = g_PresentHook->m_D3D9Hook->GetPresentParams();

			ComPtr<IDirect3DDevice9> pDummyDevice;
			if (params.device.get()->QueryInterface(IID_PPV_ARGS(&pDummyDevice)) != E_NOINTERFACE) {
				RH_RHOOK_INFO("Graphics API Detected: DirectX9");
				g_PresentHook->m_GraphicsAPI = APIType::D3D9;
			}
		}
		break;

		// A DXGI presentation function has been called
		case PresentType::DXGI:
		{
			RH_RHOOK_INFO("Present type: DXGI");

			IDXGISwapChain* pSwapChain = nullptr;

			// For this we try D3D10 11 and 12
			// First we need to get the DXGI SwapChain
			if (g_PresentHook->m_D3D10Hook) {
				// Our initial dummy hook was D3D10 so we get the SwapChain from it
				const auto& params = g_PresentHook->m_D3D10Hook->GetPresentParams();

				pSwapChain = params.swapChain.get();
			}
			else if (g_PresentHook->m_D3D11Hook) {
				// Our initial dummy hook was D3D11 so we get the SwapChain from it
				const auto& params = g_PresentHook->m_D3D11Hook->GetPresentParams();

				pSwapChain = params.swapChain.get();
			}
			else if (g_PresentHook->m_D3D12Hook) {
				// Our initial dummy hook was D3D12 so we get the SwapChain from it
				const auto& params = g_PresentHook->m_D3D12Hook->GetPresentParams();

				pSwapChain = params.swapChain.get();
			}

			// Make sure we did get a SwapChain pointer
			if (pSwapChain != nullptr) {
				// Make sure that it is a valid SwapChain pointer
				ComPtr<IDXGISwapChain> pDummySwapCahin;
				if (pSwapChain->QueryInterface(IID_PPV_ARGS(&pDummySwapCahin)) == E_NOINTERFACE) {
					RH_RHOOK_ERROR("DXGI Present SwapChain pointer is invalid!");
				}

				// D3D10
				{
					ComPtr<ID3D10Device> pDummyDevice;
					if (pSwapChain->GetDevice(IID_PPV_ARGS(&pDummyDevice)) != E_NOINTERFACE) {
						RH_RHOOK_INFO("Graphics API Detected: DirectX10");
						g_PresentHook->m_GraphicsAPI = APIType::D3D10;
					}
				}

				// D3D11
				{
					ComPtr<ID3D11Device> pDummyDevice;
					if (pSwapChain->GetDevice(IID_PPV_ARGS(&pDummyDevice)) != E_NOINTERFACE) {
						RH_RHOOK_INFO("Graphics API Detected: DirectX11");
						g_PresentHook->m_GraphicsAPI = APIType::D3D11;
					}
				}

				// D3D12
				{
					ComPtr<ID3D12Device> pDummyDevice;
					if (pSwapChain->GetDevice(IID_PPV_ARGS(&pDummyDevice)) != E_NOINTERFACE) {
						RH_RHOOK_INFO("Graphics API Detected: DirectX12");
						g_PresentHook->m_GraphicsAPI = APIType::D3D12;
					}
				}
			}
		}
		break;

		// OpenGL has called the presentation function
		case PresentType::OpenGL:
		{
			RH_RHOOK_INFO("Graphics API Detected: OpenGL");
			g_PresentHook->m_GraphicsAPI = APIType::OpenGL;
		}
		break;

		// Vulkan has called the presentation function
		case PresentType::Vulkan:
		{
			RH_RHOOK_INFO("Graphics API Detected: Vulkan");
			g_PresentHook->m_GraphicsAPI = APIType::Vulkan;
		}
		break;

		default:
			RH_RHOOK_ERROR("Unknown present type has been called!");
			break;

		}

		if (g_PresentHook->UnhookDetectionHooks()) {
			s_Hooked = false;
			if (g_PresentHook->m_Callback != nullptr)
				g_PresentHook->m_Callback(g_PresentHook->m_GraphicsAPI);
		}
		else {
			RH_RHOOK_ERROR("Failed to unhook api detection present hooks!");
		}
	}

	void PresentHook::VulkanInstanceCreation()
	{
		std::scoped_lock _{ g_PresentHook->m_VkCreateInstanceMutex };

		RH_RHOOK_INFO("API detection Vulkan instance creation hook called!");

		RH_RHOOK_INFO("Graphics API Detected: Vulkan");
		g_PresentHook->m_GraphicsAPI = APIType::Vulkan;

		if (g_PresentHook->UnhookDetectionHooks()) {
			s_Hooked = false;
			if (g_PresentHook->m_Callback != nullptr)
				g_PresentHook->m_Callback(g_PresentHook->m_GraphicsAPI);
		}
		else {
			RH_RHOOK_ERROR("Failed to unhook api detection Vulkan instance creation hook!");
		}
	}

	void PresentHook::ListAllModules()
	{
		HMODULE hMods[1024];
		DWORD cbNeeded;


		// Get the handle to the process
		HANDLE hProcess = ::GetCurrentProcess();

		// Make sure the process handle is valid.
		if (hProcess == NULL) {
			RH_RHOOK_ERROR("Could not open the process handle for enumarating loaded modules!");
			return;
		}

		// Get a list of all the modules in this process.
		if (::EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
		{
			for (size_t i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
			{
				TCHAR szModName[MAX_PATH];

				// Get the full path to the module's file.
				if (::GetModuleFileNameEx(hProcess, hMods[i], szModName, sizeof(szModName) / sizeof(TCHAR)))
				{
					for (size_t j = 0; szModName[j] != 0; j++) {
						szModName[j] = ::tolower(szModName[j]);
					}

					// Add only the filanme of the module to the list.
					auto modNameStr = std::string(szModName);
					m_ModuleNameList.push_back(std::string(szModName).substr(modNameStr.find_last_of("/\\") + 1));
				}
			}
		}

		// Release the handle to the process.
		::CloseHandle(hProcess);
	}

	bool PresentHook::HookPresents()
	{
		{
			struct Compare
			{
				std::string key;
				Compare(const std::string& i) : key(i) {}

				bool operator()(const std::string& i) {
					return (i == key);
				}
			};

			const auto& ml = m_ModuleNameList;
			m_D3D9Loaded = std::any_of(ml.begin(), ml.end(), Compare{ "d3d9.dll" });
			m_D3D10Loaded = std::any_of(ml.begin(), ml.end(), Compare{ "d3d10.dll" });
			m_D3D11Loaded = std::any_of(ml.begin(), ml.end(), Compare{ "d3d11.dll" });
			m_D3D12Loaded = std::any_of(ml.begin(), ml.end(), Compare{ "d3d12.dll" });
			m_DXGILoaded = std::any_of(ml.begin(), ml.end(), Compare{ "dxgi.dll" });
			m_OpenGLLoaded = std::any_of(ml.begin(), ml.end(), Compare{ "opengl32.dll" });
			m_VulkanLoaded = std::any_of(ml.begin(), ml.end(), Compare{ "vulkan-1.dll" });
		}

		if (m_D3D9Loaded) {
			if (!HookD3D9()) {
				RH_RHOOK_ERROR("Hooking D3D9 Present failed!");
				UnhookDetectionHooks();
				return false;
			}
		}

		if (m_DXGILoaded && (m_D3D10Loaded || m_D3D11Loaded || m_D3D12Loaded)) {
			if (!HookDXGI()) {
				RH_RHOOK_ERROR("Hooking DXGI Present failed!");
				UnhookDetectionHooks();
				return false;
			}
		}

		if (m_OpenGLLoaded) {
			if (!HookOpenGL()) {
				RH_RHOOK_ERROR("Hooking OpenGL Present failed!");
				UnhookDetectionHooks();
				return false;
			}
		}

		if (m_VulkanLoaded) {
			if (!HookVulkan()) {
				RH_RHOOK_ERROR("Hooking Vulkan Present failed!");
				UnhookDetectionHooks();
				return false;
			}
		}

		return true;
	}

	bool PresentHook::UnhookDetectionHooks()
	{
		if (m_D3D9Hook) {
			if (!m_D3D9Hook->Unhook()) {
				return false;
			}
			RH_RHOOK_INFO("Unhooked D3D9 API detection");
		}

		if (m_D3D10Hook) {
			if (!m_D3D10Hook->Unhook()) {
				return false;
			}
			RH_RHOOK_INFO("Unhooked D3D10 DXGI API detection");
		}

		if (m_D3D11Hook) {
			if (!m_D3D11Hook->Unhook()) {
				return false;
			}
			RH_RHOOK_INFO("Unhooked D3D11 DXGI API detection");
		}

		if (m_D3D12Hook) {
			if (!m_D3D12Hook->Unhook()) {
				return false;
			}
			RH_RHOOK_INFO("Unhooked D3D12 DXGI API detection");
		}

		if (m_OpenGLHook) {
			if (!m_OpenGLHook->Unhook()) {
				return false;
			}
			RH_RHOOK_INFO("Unhooked OpenGL API detection");
		}

		if (m_VulkanHook) {
			if (!m_VulkanHook->Unhook()) {
				return false;
			}

			RH_RHOOK_INFO("Unhooked Vulkan API detection");
		}

		return true;
	}

	bool PresentHook::HookD3D9()
	{
		RH_RHOOK_INFO("Hooking D3D9 for api detection!");

		m_D3D9Hook.reset();
		m_D3D9Hook = std::make_unique<D3D9Hook>(&m_HookMonitorMutex);

		m_D3D9Hook->OnPrePresent([this](D3D9Hook&) { OnFrame(PresentType::D3D9); });

		if (!m_D3D9Hook->Hook()) {
			RH_RHOOK_INFO("Failed to hook D3D9 for initial api detection!");
			return false;
		}

		RH_RHOOK_INFO("Hooked D3D9 for api detection!");

		return true;
	}

	bool PresentHook::HookDXGI()
	{
		// D3D10 11 and 12 all call the same Present function in DXGI so hooking any 
		// of them if loaded as an imported dll starting with DX10 alone should give us the that Present

		// D3D10 Hook
		if (m_D3D10Loaded) {
			RH_RHOOK_INFO("Hooking D3D10 for api detection!");
			m_D3D10Hook.reset();
			m_D3D10Hook = std::make_unique<D3D10Hook>(&m_HookMonitorMutex);

			m_D3D10Hook->OnPrePresent([this](DXGIHook&) { OnFrame(PresentType::DXGI); });

			if (!m_D3D10Hook->Hook()) {
				RH_RHOOK_ERROR("Failed to hook D3D10 for initial api detection!");
				return false;
			}
			RH_RHOOK_INFO("Hooked D3D10 for api detection!");
		}
		else if (m_D3D11Loaded) {
			RH_RHOOK_INFO("Hooking D3D11 for api detection!");
			m_D3D11Hook.reset();
			m_D3D11Hook = std::make_unique<D3D11Hook>(&m_HookMonitorMutex);

			m_D3D11Hook->OnPrePresent([this](DXGIHook&) { OnFrame(PresentType::DXGI); });

			if (!m_D3D11Hook->Hook()) {
				RH_RHOOK_ERROR("Failed to hook D3D11 for initial api detection!");
				return false;
			}
			RH_RHOOK_INFO("Hooked D3D11 for api detection!");
		}
		else if (m_D3D12Loaded) {
			RH_RHOOK_INFO("Hooking D3D12 for api detection!");
			m_D3D12Hook.reset();
			m_D3D12Hook = std::make_unique<D3D12Hook>(&m_HookMonitorMutex);

			m_D3D12Hook->OnPrePresent([this](DXGIHook&) { OnFrame(PresentType::DXGI); });

			if (!m_D3D12Hook->Hook()) {
				RH_RHOOK_ERROR("Failed to hook D3D12 for initial api detection!");
				return false;
			}
			RH_RHOOK_INFO("Hooked D3D12 for api detection!");
		}
		else {
			RH_RHOOK_ERROR("Tried to hook DXGI but none of the APIs using it were hooked!");
			return false;
		}

		return true;
	}

	bool PresentHook::HookOpenGL()
	{
		RH_RHOOK_INFO("Hooking OpenGL for api detection!");

		m_OpenGLHook.reset();
		m_OpenGLHook = std::make_unique<OpenGLHook>(&m_HookMonitorMutex);

		m_OpenGLHook->OnPreSwapBuffers([this](OpenGLHook&) { OnFrame(PresentType::OpenGL); });

		if (!m_OpenGLHook->Hook()) {
			RH_RHOOK_ERROR("Failed to hook OpenGL for initial api detection!");
			return false;
		}

		RH_RHOOK_INFO("Hooked OpenGL for api detection!");
		return true;
	}

	bool PresentHook::HookVulkan()
	{
		RH_RHOOK_INFO("Hooking Vulkan for api detection!");

		m_VulkanHook.reset();
		m_VulkanHook = std::make_unique<VulkanHook>(&m_HookMonitorMutex);

		m_VulkanHook->OnPreVkCreateInstance([this](VulkanHook&) { VulkanInstanceCreation(); });

		m_VulkanHook->OnPreVkQueuePresentKHR([this](VulkanHook&) { OnFrame(PresentType::Vulkan); });

		if (!m_VulkanHook->Hook()) {
			RH_RHOOK_ERROR("Failed to hook Vulkan for initial api detection!");
			return false;
		}

		RH_RHOOK_INFO("Hooked Vulkan for api detection!");
		return true;
	}
}