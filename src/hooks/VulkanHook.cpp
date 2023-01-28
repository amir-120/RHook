#include "VulkanHook.hpp"

#include "Log/Logging.hpp"

namespace RHook {
	static VulkanHook* g_VulkanHook = nullptr;

	VulkanHook::VulkanHook(std::recursive_mutex* hookMutex)
		: m_HookMutex(hookMutex)
	{}

	VulkanHook::~VulkanHook()
	{
		Unhook();
		g_VulkanHook = nullptr;
	}

	bool VulkanHook::Hook()
	{
		RH_RHOOK_INFO("Hooking Vulkan");

		g_VulkanHook = this;

		auto vulkanModule = GetModuleHandleA("vulkan-1.dll");
		if (!vulkanModule) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vulkan-1.dll.");
			return false;
		}

		// Loader exports
		auto realVkGetDeviceProcAddrFn = (decltype(vkGetDeviceProcAddr)*)GetProcAddress(vulkanModule, "vkGetDeviceProcAddr");
		if (realVkGetDeviceProcAddrFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkGetDeviceProcAddr() export.");
			return false;
		}

		auto realVkGetInstanceProcAddrFn = (decltype(vkGetInstanceProcAddr)*)GetProcAddress(vulkanModule, "vkGetInstanceProcAddr");
		if (realVkGetInstanceProcAddrFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkGetInstanceProcAddr() export.");
			return false;
		}

		// Global proc addresses
		auto realVkCreateInstanceFn = (decltype(vkCreateInstance)*)GetProcAddress(vulkanModule, "vkCreateInstance");
		if (realVkCreateInstanceFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkCreateInstance() export.");
			return false;
		}

		auto realVkCreateDeviceFn = (decltype(vkCreateDevice)*)GetProcAddress(vulkanModule, "vkCreateDevice");
		if (realVkCreateDeviceFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkCreateDevice() export.");
			return false;
		}

		auto realVkCreateFenceFn = (decltype(vkCreateFence)*)GetProcAddress(vulkanModule, "vkCreateFence");
		if (realVkCreateFenceFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkCreateFence() export.");
			return false;
		}

		auto realVkCreateSemaphoreFn = (decltype(vkCreateSemaphore)*)GetProcAddress(vulkanModule, "vkCreateSemaphore");
		if (realVkCreateSemaphoreFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkCreateSemaphore() export.");
			return false;
		}

		auto realVkCreateEventFn = (decltype(vkCreateEvent)*)GetProcAddress(vulkanModule, "vkCreateEvent");
		if (realVkCreateEventFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkCreateEvent() export.");
			return false;
		}

		auto realVkCreateQueryPoolFn = (decltype(vkCreateQueryPool)*)GetProcAddress(vulkanModule, "vkCreateQueryPool");
		if (realVkCreateQueryPoolFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkCreateQueryPool() export.");
			return false;
		}

		auto realVkCreateBufferFn = (decltype(vkCreateBuffer)*)GetProcAddress(vulkanModule, "vkCreateBuffer");
		if (realVkCreateBufferFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkCreateBuffer() export.");
			return false;
		}

		auto realVkCreateBufferViewFn = (decltype(vkCreateBufferView)*)GetProcAddress(vulkanModule, "vkCreateBufferView");
		if (realVkCreateBufferViewFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkCreateBufferView() export.");
			return false;
		}

		auto realVkCreateImageFn = (decltype(vkCreateImage)*)GetProcAddress(vulkanModule, "vkCreateImage");
		if (realVkCreateImageFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkCreateImage() export.");
			return false;
		}

		auto realVkCreateImageViewFn = (decltype(vkCreateImageView)*)GetProcAddress(vulkanModule, "vkCreateImageView");
		if (realVkCreateImageViewFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkCreateImageView() export.");
			return false;
		}

		auto realVkCreateGraphicsPipelinesFn = (decltype(vkCreateGraphicsPipelines)*)GetProcAddress(vulkanModule, "vkCreateGraphicsPipelines");
		if (realVkCreateGraphicsPipelinesFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkCreateGraphicsPipelines() export.");
			return false;
		}

		auto realVkCreateFramebufferFn = (decltype(vkCreateFramebuffer)*)GetProcAddress(vulkanModule, "vkCreateFramebuffer");
		if (realVkCreateFramebufferFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkCreateFramebuffer() export.");
			return false;
		}

		auto realVkCreateDescriptorPoolFn = (decltype(vkCreateDescriptorPool)*)GetProcAddress(vulkanModule, "vkCreateDescriptorPool");
		if (realVkCreateDescriptorPoolFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkCreateDescriptorPool() export.");
			return false;
		}

		auto realVkCreateWin32SurfaceKHRFn = (decltype(vkCreateWin32SurfaceKHR)*)GetProcAddress(vulkanModule, "vkCreateWin32SurfaceKHR");
		if (realVkCreateWin32SurfaceKHRFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkCreateWin32SurfaceKHR() export.");
			return false;
		}

		auto realVkCreateSwapchainKHRFn = (decltype(vkCreateSwapchainKHR)*)GetProcAddress(vulkanModule, "vkCreateSwapchainKHR");
		if (realVkCreateSwapchainKHRFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkCreateSwapchainKHR() export.");
			return false;
		}

		auto realVkCreateRenderPassFn = (decltype(vkCreateRenderPass)*)GetProcAddress(vulkanModule, "vkCreateRenderPass");
		if (realVkCreateRenderPassFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkCreateRenderPass() export.");
			return false;
		}



		auto realVkAllocateCommandBuffersFn = (decltype(vkAllocateCommandBuffers)*)GetProcAddress(vulkanModule, "vkAllocateCommandBuffers");
		if (realVkAllocateCommandBuffersFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkAllocateCommandBuffers() export.");
			return false;
		}

		auto realVkBeginCommandBufferFn = (decltype(vkBeginCommandBuffer)*)GetProcAddress(vulkanModule, "vkBeginCommandBuffer");
		if (realVkBeginCommandBufferFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkBeginCommandBuffer() export.");
			return false;
		}

		auto realVkCmdBeginRenderPassFn = (decltype(vkCmdBeginRenderPass)*)GetProcAddress(vulkanModule, "vkCmdBeginRenderPass");
		if (realVkCmdBeginRenderPassFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkCmdBeginRenderPass() export.");
			return false;
		}

		

		auto realVkGetDeviceQueueFn = (decltype(vkGetDeviceQueue)*)GetProcAddress(vulkanModule, "vkGetDeviceQueue");
		if (realVkGetDeviceQueueFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkGetDeviceQueue() export.");
			return false;
		}

		auto realVkAcquireNextImageKHRFn = (decltype(vkAcquireNextImageKHR)*)GetProcAddress(vulkanModule, "vkAcquireNextImageKHR");
		if (realVkAcquireNextImageKHRFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkAcquireNextImageKHR() export.");
			return false;
		}

		auto realVkQueueSubmitFn = (decltype(vkQueueSubmit)*)GetProcAddress(vulkanModule, "vkQueueSubmit");
		if (realVkQueueSubmitFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkQueueSubmit() export.");
			return false;
		}

		auto realVkQueuePresentKHRFn = (decltype(vkQueuePresentKHR)*)GetProcAddress(vulkanModule, "vkQueuePresentKHR");
		if (realVkQueuePresentKHRFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkQueuePresentKHR() export.");
			return false;
		}


		
		auto realVkCmdEndRenderPassFn = (decltype(vkCmdEndRenderPass)*)GetProcAddress(vulkanModule, "vkCmdEndRenderPass");
		if (realVkCmdEndRenderPassFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkCmdEndRenderPass() export.");
			return false;
		}

		auto realVkEndCommandBufferFn = (decltype(vkEndCommandBuffer)*)GetProcAddress(vulkanModule, "vkEndCommandBuffer");
		if (realVkEndCommandBufferFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkEndCommandBuffer() export.");
			return false;
		}

		auto realVkFreeCommandBuffersFn = (decltype(vkFreeCommandBuffers)*)GetProcAddress(vulkanModule, "vkFreeCommandBuffers");
		if (realVkFreeCommandBuffersFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkFreeCommandBuffers() export.");
			return false;
		}



		auto realVkDestroyRenderPassFn = (decltype(vkDestroyRenderPass)*)GetProcAddress(vulkanModule, "vkDestroyRenderPass");
		if (realVkDestroyRenderPassFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkDestroyRenderPass() export.");
			return false;
		}

		auto realVkDestroySwapchainKHRFn = (decltype(vkDestroySwapchainKHR)*)GetProcAddress(vulkanModule, "vkDestroySwapchainKHR");
		if (realVkDestroySwapchainKHRFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkDestroySwapchainKHR() export.");
			return false;
		}

		auto realVkDestroySurfaceKHRFn = (decltype(vkDestroySurfaceKHR)*)GetProcAddress(vulkanModule, "vkDestroySurfaceKHR");
		if (realVkDestroySurfaceKHRFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkDestroySurfaceKHR() export.");
			return false;
		}

		auto realVkDestroyDescriptorPoolFn = (decltype(vkDestroyDescriptorPool)*)GetProcAddress(vulkanModule, "vkDestroyDescriptorPool");
		if (realVkDestroyDescriptorPoolFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkDestroyDescriptorPool() export.");
			return false;
		}

		auto realVkDestroyFramebufferFn = (decltype(vkDestroyFramebuffer)*)GetProcAddress(vulkanModule, "vkDestroyFramebuffer");
		if (realVkDestroyFramebufferFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkDestroyFramebuffer() export.");
			return false;
		}

		auto realVkDestroyPipelineFn = (decltype(vkDestroyPipeline)*)GetProcAddress(vulkanModule, "vkDestroyPipeline");
		if (realVkDestroyPipelineFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkDestroyPipeline() export.");
			return false;
		}

		auto realVkDestroyImageViewFn = (decltype(vkDestroyImageView)*)GetProcAddress(vulkanModule, "vkDestroyImageView");
		if (realVkDestroyImageViewFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkDestroyImageView() export.");
			return false;
		}

		auto realVkDestroyImageFn = (decltype(vkDestroyImage)*)GetProcAddress(vulkanModule, "vkDestroyImage");
		if (realVkDestroyImageFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkDestroyImage() export.");
			return false;
		}

		auto realVkDestroyBufferViewFn = (decltype(vkDestroyBufferView)*)GetProcAddress(vulkanModule, "vkDestroyBufferView");
		if (realVkDestroyBufferViewFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkDestroyBufferView() export.");
			return false;
		}

		auto realVkDestroyBufferFn = (decltype(vkDestroyBuffer)*)GetProcAddress(vulkanModule, "vkDestroyBuffer");
		if (realVkDestroyBufferFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkDestroyBuffer() export.");
			return false;
		}

		auto realVkDestroyQueryPoolFn = (decltype(vkDestroyQueryPool)*)GetProcAddress(vulkanModule, "vkDestroyQueryPool");
		if (realVkDestroyQueryPoolFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkDestroyQueryPool() export.");
			return false;
		}

		auto realVkDestroyEventFn = (decltype(vkDestroyEvent)*)GetProcAddress(vulkanModule, "vkDestroyEvent");
		if (realVkDestroyEventFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkDestroyEvent() export.");
			return false;
		}

		auto realVkDestroySemaphoreFn = (decltype(vkDestroySemaphore)*)GetProcAddress(vulkanModule, "vkDestroySemaphore");
		if (realVkDestroySemaphoreFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkDestroySemaphore() export.");
			return false;
		}

		auto realVkDestroyFenceFn = (decltype(vkDestroyFence)*)GetProcAddress(vulkanModule, "vkDestroyFence");
		if (realVkDestroyFenceFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkDestroyFence() export.");
			return false;
		}

		auto realVkDestroyDeviceFn = (decltype(vkDestroyDevice)*)GetProcAddress(vulkanModule, "vkDestroyDevice");
		if (realVkDestroyDeviceFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkDestroyDevice() export.");
			return false;
		}

		auto realVkDestroyInstanceFn = (decltype(vkDestroyInstance)*)GetProcAddress(vulkanModule, "vkDestroyInstance");
		if (realVkDestroyInstanceFn == nullptr) {
			RH_RHOOK_ERROR("[VULKAN HOOK] Failed to load vkDestroyInstance() export.");
			return false;
		}
#define ADD_HOOK(SYMBOL, NAME) s_HookList[(size_t)HIdx::SYMBOL] = std::make_unique<SmartFunctionHook>(real##SYMBOL##Fn, &VulkanHook::SYMBOL, &m_ActiveHookList[(size_t)HIdx::SYMBOL], NAME);
		
		// Loader exports
		ADD_HOOK(VkGetInstanceProcAddr, "vkGetInstanceProcAddr()");
		ADD_HOOK(VkGetDeviceProcAddr, "vkGetDeviceProcAddr()");

		// Global commands
		ADD_HOOK(VkCreateInstance, "vkCreateInstance()");
		ADD_HOOK(VkCreateDevice, "vkCreateDevice()");
		ADD_HOOK(VkCreateFence, "vkCreateFence()");
		ADD_HOOK(VkCreateSemaphore, "vkCreateSemaphore()");
		ADD_HOOK(VkCreateEvent, "vkCreateEvent()");
		ADD_HOOK(VkCreateQueryPool, "vkCreateQueryPool()");
		ADD_HOOK(VkCreateBuffer, "vkCreateBuffer()");
		ADD_HOOK(VkCreateBufferView, "vkCreateBufferView()");
		ADD_HOOK(VkCreateImage, "vkCreateImage()");
		ADD_HOOK(VkCreateImageView, "vkCreateImageView()");
		ADD_HOOK(VkCreateGraphicsPipelines, "vkCreateGraphicsPipelines()");
		ADD_HOOK(VkCreateFramebuffer, "vkCreateFramebuffer()");
		ADD_HOOK(VkCreateDescriptorPool, "vkCreateDescriptorPool()");
		ADD_HOOK(VkCreateWin32SurfaceKHR, "vkCreateWin32SurfaceKHR()");
		ADD_HOOK(VkCreateSwapchainKHR, "vkCreateSwapchainKHR()");
		ADD_HOOK(VkCreateRenderPass, "vkCreateRenderPass()");

		ADD_HOOK(VkAllocateCommandBuffers, "vkAllocateCommandBuffers()");
		ADD_HOOK(VkBeginCommandBuffer, "vkBeginCommandBuffer()");
		ADD_HOOK(VkCmdBeginRenderPass, "vkCmdBeginRenderPass()");

		ADD_HOOK(VkGetDeviceQueue, "vkGetDeviceQueue()");
		ADD_HOOK(VkAcquireNextImageKHR, "vkAcquireNextImageKHR()");
		ADD_HOOK(VkQueueSubmit, "vkQueueSubmit()");
		ADD_HOOK(VkQueuePresentKHR, "vkQueuePresentKHR()");

		ADD_HOOK(VkCmdEndRenderPass, "vkCmdEndRenderPass()");
		ADD_HOOK(VkEndCommandBuffer, "vkEndCommandBuffer()");
		ADD_HOOK(VkFreeCommandBuffers, "vkFreeCommandBuffers()");

		ADD_HOOK(VkDestroyRenderPass, "vkDestroyRenderPass()");
		ADD_HOOK(VkDestroySwapchainKHR, "vkDestroySwapchainKHR()");
		ADD_HOOK(VkDestroySurfaceKHR, "vkDestroySurfaceKHR()");
		ADD_HOOK(VkDestroyDescriptorPool, "vkDestroyDescriptorPool()");
		ADD_HOOK(VkDestroyFramebuffer, "vkDestroyFramebuffer()");
		ADD_HOOK(VkDestroyPipeline, "vkDestroyPipeline()");
		ADD_HOOK(VkDestroyImageView, "vkDestroyImageView()");
		ADD_HOOK(VkDestroyImage, "vkDestroyImage()");
		ADD_HOOK(VkDestroyBufferView, "vkDestroyBufferView()");
		ADD_HOOK(VkDestroyBuffer, "vkDestroyBuffer()");
		ADD_HOOK(VkDestroyQueryPool, "vkDestroyQueryPool()");
		ADD_HOOK(VkDestroyEvent, "vkDestroyEvent()");
		ADD_HOOK(VkDestroySemaphore, "vkDestroySemaphore()");
		ADD_HOOK(VkDestroyFence, "vkDestroyFence()");
		ADD_HOOK(VkDestroyDevice, "vkDestroyDevice()");
		ADD_HOOK(VkDestroyInstance, "vkDestroyInstance()");

		// Enable detours
		for (auto& execute : s_DetourExecutionList) {
			execute = true;
		}

		s_Hooked = true;

		// Enable the hooks
		for (size_t i = 0; i < s_HookList.size(); i++) {
			if (!s_HookList[i]->Create())
			{
				RH_RHOOK_ERROR("[VULKAN HOOK] Failed to hook {:s}", s_HookList[i]->GetName());
				s_Hooked = false;
			}
		}

		s_Hooked = s_Hooked && s_DeviceCommandMap.HookAll() && s_InstanceCommandMap.HookAll();

		if (!s_Hooked) {
			// If a problem occurred, reset the hook.
			// Call unhook just to be sure all hooks are removed.
			Unhook();
			
			for (auto& hook : s_HookList) {
				hook.reset();
			}

			g_VulkanHook = nullptr;

			return false;
		}

		return s_Hooked;
	}

	bool VulkanHook::Unhook()
	{
		bool unhooked = true;

		for (auto& hook : s_HookList) {
			if(hook) unhooked = unhooked && hook->Remove();
		}

		if (s_DeviceCommandMap.UnhookAll() && s_InstanceCommandMap.UnhookAll() && unhooked) {
			s_Hooked = false;
			return true;
		}

		return false;
	}

	void VulkanHook::SkipDetours(const std::function<void()>& code)
	{
		// A static array of false elements to use as detour disabling
		static std::array<bool, s_DetourExecutionList.size()> noDetourSwap = {false};
		
		s_DetourExecutionList.swap(noDetourSwap);

		code();

		s_DetourExecutionList.swap(noDetourSwap);
	}

#define DETOUR_NOINSERT_RETURN(RESULT, SYMBOL, ...) {																						\
				  auto& callDepth = g_VKCallDepth##SYMBOL;																					\
			const auto& hook = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::SYMBOL];														\
				  auto&	pResult = *(decltype(RESULT)**)&s_ResultList[(size_t)HIdx::SYMBOL];													\
																																			\
			/*This line must be called before calling our detour function because we might have to unhook the function inside our detour.	\
			*/auto originalFn = hook->GetOriginal<decltype(VulkanHook::SYMBOL)>();															\
			auto realFn = hook->GetTarget<decltype(VulkanHook::SYMBOL)>();																	\
																																			\
			if (callDepth == 0) {																											\
				pResult = &RESULT;																											\
			}																																\
																																			\
			callDepth++;																													\
																																			\
			if (g_VulkanHook != nullptr && hook->IsValid())																					\
				RESULT = originalFn( __VA_ARGS__ );																							\
			else																															\
				RESULT = realFn( __VA_ARGS__ ); 																							\
																																			\
			if (callDepth == 0) {																											\
				pResult = nullptr;																											\
			}																																\
																																			\
			callDepth--;																													\
		}

#define DETOUR_NOINSERT_VOID(NAME, ...) {																									\
			auto& callDepth = g_VKCallDepth##NAME;																							\
			const auto& hook = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::NAME];														\
																																			\
			/*This line must be called before calling our detour function because we might have to unhook the function inside our detour.	\
			*/auto originalFn = hook->GetOriginal<decltype(VulkanHook::NAME)>(); 															\
			auto realFn = hook->GetTarget<decltype(VulkanHook::NAME)>();;																	\
																																			\
			callDepth++; 																													\
																																			\
			if (g_VulkanHook != nullptr && hook->IsValid())																					\
				originalFn( __VA_ARGS__ );																									\
			else																															\
				realFn( __VA_ARGS__ );																										\
																																			\
			callDepth--; 																													\
		}

#define DETOUR_RETURN(RESULT, SYMBOL, ...) {																								\
			const auto& executeDetour = s_DetourExecutionList[(size_t)HIdx::SYMBOL];														\
				  auto&	callDepth = g_VKCallDepth##SYMBOL;																					\
			const auto& hook = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::SYMBOL];														\
			const auto& preDetourFn = g_VulkanHook->m_OnPreFunctionCallList[(size_t)HIdx::SYMBOL];											\
			const auto& postDetourFn = g_VulkanHook->m_OnPostFunctionCallList[(size_t)HIdx::SYMBOL];										\
				  auto&	pParams = *(SYMBOL##Parameters_t**)&s_ParamList[(size_t)HIdx::SYMBOL];												\
				  auto&	pResult = *(decltype(RESULT)**)&s_ResultList[(size_t)HIdx::SYMBOL];													\
																																			\
			/*This line must be called before calling our detour function because we might have to unhook the function inside our detour.	\
			*/auto originalFn = hook->GetOriginal<decltype(VulkanHook::SYMBOL)>();															\
			auto realFn = hook->GetTarget<decltype(VulkanHook::SYMBOL)>();																	\
																																			\
			if (g_VulkanHook != nullptr && executeDetour && callDepth == 0) {																\
				static SYMBOL##Parameters_t tmpParams = { __VA_ARGS__ };																	\
				tmpParams = { __VA_ARGS__ };																								\
				pParams = &tmpParams;																										\
				pResult = &RESULT;																											\
				VulkanHook::SkipDetours([&]() {																								\
					if (preDetourFn) {																										\
						preDetourFn(*g_VulkanHook);																							\
					}																														\
				});																															\
			}																																\
																																			\
			callDepth++;																													\
																																			\
			if (g_VulkanHook != nullptr && hook->IsValid())																					\
				RESULT = originalFn( __VA_ARGS__ );																							\
			else																															\
				RESULT = realFn( __VA_ARGS__ ); 																							\
																																			\
			callDepth--;																													\
																																			\
			if (g_VulkanHook != nullptr && executeDetour && callDepth == 0) {																\
				VulkanHook::SkipDetours([&]() {																								\
					if (postDetourFn) {																										\
						postDetourFn(*g_VulkanHook);																						\
					}																														\
				});																															\
				pResult = nullptr;																											\
				pParams = nullptr;																											\
			}																																\
		}

#define DETOUR_VOID(SYMBOL, ...) {																											\
			const auto& executeDetour = s_DetourExecutionList[(size_t)HIdx::SYMBOL];														\
				  auto& callDepth = g_VKCallDepth##SYMBOL;																					\
			const auto& hook = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::SYMBOL];														\
			const auto& preDetourFn = g_VulkanHook->m_OnPreFunctionCallList[(size_t)HIdx::SYMBOL];											\
			const auto& postDetourFn = g_VulkanHook->m_OnPostFunctionCallList[(size_t)HIdx::SYMBOL];										\
				  auto&	pParams = *(SYMBOL##Parameters_t**)&s_ParamList[(size_t)HIdx::SYMBOL];												\
																																			\
			/*This line must be called before calling our detour function because we might have to unhook the function inside our detour.	\
			*/auto originalFn = hook->GetOriginal<decltype(VulkanHook::SYMBOL)>(); 															\
			auto realFn = hook->GetTarget<decltype(VulkanHook::SYMBOL)>();																	\
																																			\
			if (g_VulkanHook != nullptr && executeDetour && callDepth == 0) {																\
				static SYMBOL##Parameters_t tmpParams = { __VA_ARGS__ };																	\
				tmpParams = { __VA_ARGS__ };																								\
				pParams = &tmpParams;																											\
				VulkanHook::SkipDetours([&]() {																								\
					if (preDetourFn) {																										\
						preDetourFn(*g_VulkanHook);																							\
					}																														\
				}); 																														\
			}																																\
																																			\
			callDepth++; 																													\
																																			\
			if (g_VulkanHook != nullptr && hook->IsValid())																					\
				originalFn( __VA_ARGS__ ); 																									\
			else																															\
				realFn( __VA_ARGS__ ); 																										\
																																			\
			callDepth--; 																													\
																																			\
			if (g_VulkanHook != nullptr && executeDetour && callDepth == 0) {																\
				VulkanHook::SkipDetours([&]() {																								\
					if (postDetourFn) {																										\
						postDetourFn(*g_VulkanHook); 																						\
					}																														\
				}); 																														\
				pParams = nullptr;																											\
			}																																\
		}

	thread_local size_t g_VKCallDepthVkGetInstanceProcAddr = 0;
	VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL VulkanHook::VkGetInstanceProcAddr(VkInstance instance, const char* pName)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		static PFN_vkVoidFunction result = NULL;
		DETOUR_NOINSERT_RETURN(result, VkGetInstanceProcAddr, instance, pName);

#define ADD_INSTANCE_ICD_COMMAND_HOOK(SYMBOL, NAME, LOGNAME) if (!strcmp(pName, NAME) && result != (decltype(result))g_VulkanHook->s_HookList[(size_t)HIdx::SYMBOL]->GetTarget()) {	\
				s_InstanceCommandMap.Map(instance, NAME, (decltype(VulkanHook::SYMBOL)*)result, &g_VulkanHook->m_ActiveHookList[(size_t)HIdx::SYMBOL], &VulkanHook::SYMBOL);		\
																																													\
				const auto& commandHook = s_InstanceCommandMap.GetCommandHookFromInstanceHandle(instance, NAME);																	\
				if (commandHook.has_value() && !commandHook.value().get()->IsValid()) {																								\
					commandHook.value().get()->SetName("ICD - " LOGNAME);																											\
					if (commandHook.value().get()->Create()) {																														\
						RH_RHOOK_INFO("[VULKAN HOOK] Hooked ICD " LOGNAME " at {:p} for device: {:p}", (void*)result, (void*)instance);												\
					}																																								\
					else {																																							\
						RH_RHOOK_ERROR("[VULKAN HOOK] Failed to hook " LOGNAME " at {:p} obtained from vkGetInstanceProcAddr(). Instance = {:p}", (void*)result, (void*)instance);	\
					}																																								\
				}																																									\
			}

		if (result != NULL) {
			ADD_INSTANCE_ICD_COMMAND_HOOK(VkCreateWin32SurfaceKHR, "vkCreateWin32SurfaceKHR", "vkCreateWin32SurfaceKHR()")
			else ADD_INSTANCE_ICD_COMMAND_HOOK(VkDestroySurfaceKHR, "vkDestroySurfaceKHR", "vkDestroySurfaceKHR()")
			else ADD_INSTANCE_ICD_COMMAND_HOOK(VkDestroyInstance, "vkDestroyInstance", "vkDestroyInstance()")
		}

		return result;
	}

	thread_local size_t g_VKCallDepthVkGetDeviceProcAddr = 0;
	VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL VulkanHook::VkGetDeviceProcAddr(VkDevice device, const char* pName)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		static PFN_vkVoidFunction result = NULL;
		DETOUR_NOINSERT_RETURN(result, VkGetDeviceProcAddr, device, pName);

#define ADD_DEVICE_ICD_COMMAND_HOOK(SYMBOL, NAME, LOGNAME) if (!strcmp(pName, NAME) && result != (decltype(result))g_VulkanHook->s_HookList[(size_t)HIdx::SYMBOL]->GetTarget()) {	\
				s_DeviceCommandMap.Map(device, NAME, (decltype(VulkanHook::SYMBOL)*)result, &g_VulkanHook->m_ActiveHookList[(size_t)HIdx::SYMBOL], &VulkanHook::SYMBOL);			\
																																													\
				const auto& commandHook = s_DeviceCommandMap.GetCommandHookFromDeviceHandle(device, NAME);																			\
				if (commandHook.has_value() && !commandHook.value().get()->IsValid()) {																								\
					commandHook.value().get()->SetName("ICD - " LOGNAME);																											\
					if (commandHook.value().get()->Create()) {																														\
						RH_RHOOK_INFO("[VULKAN HOOK] Hooked ICD " LOGNAME " at {:p} for device: {:p}", (void*)result, (void*)device);												\
					}																																								\
					else {																																							\
						RH_RHOOK_ERROR("[VULKAN HOOK] Failed to hook " LOGNAME " at {:p} obtained from vkGetDeviceProcAddr(). Device = {:p}", (void*)result, (void*)device);		\
					}																																								\
				}																																									\
			}

		if (result != NULL) {
			ADD_DEVICE_ICD_COMMAND_HOOK(VkCreateFence, "vkCreateFence", "vkCreateFence()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkCreateSemaphore, "vkCreateSemaphore", "vkCreateSemaphore()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkCreateEvent, "vkCreateEvent", "vkCreateEvent()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkCreateQueryPool, "vkCreateQueryPool", "vkCreateQueryPool()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkCreateBuffer, "vkCreateBuffer", "vkCreateBuffer()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkCreateBufferView, "vkCreateBufferView", "vkCreateBufferView()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkCreateImage, "vkCreateImage", "vkCreateImage()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkCreateImageView, "vkCreateImageView", "vkCreateImageView()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkCreateGraphicsPipelines, "vkCreateGraphicsPipelines", "vkCreateGraphicsPipelines()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkCreateFramebuffer, "vkCreateFramebuffer", "vkCreateFramebuffer()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkCreateDescriptorPool, "vkCreateDescriptorPool", "vkCreateDescriptorPool()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkCreateSwapchainKHR, "vkCreateSwapchainKHR", "vkCreateSwapchainKHR()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkCreateRenderPass, "vkCreateRenderPass", "vkCreateRenderPass()")
			
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkAllocateCommandBuffers, "vkAllocateCommandBuffers", "vkAllocateCommandBuffers()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkBeginCommandBuffer, "vkBeginCommandBuffer", "vkBeginCommandBuffer()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkCmdBeginRenderPass, "vkCmdBeginRenderPass", "vkCmdBeginRenderPass()")

			else ADD_DEVICE_ICD_COMMAND_HOOK(VkGetDeviceQueue, "vkGetDeviceQueue", "vkGetDeviceQueue()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkAcquireNextImageKHR, "vkAcquireNextImageKHR", "vkAcquireNextImageKHR()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkQueueSubmit, "vkQueueSubmit", "vkQueueSubmit()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkQueuePresentKHR, "vkQueuePresentKHR", "vkQueuePresentKHR()")

			else ADD_DEVICE_ICD_COMMAND_HOOK(VkCmdEndRenderPass, "vkCmdEndRenderPass", "vkCmdEndRenderPass()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkEndCommandBuffer, "vkEndCommandBuffer", "vkEndCommandBuffer()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkFreeCommandBuffers, "vkFreeCommandBuffers", "vkFreeCommandBuffers()")

			else ADD_DEVICE_ICD_COMMAND_HOOK(VkDestroyRenderPass, "vkDestroyRenderPass", "vkDestroyRenderPass()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkDestroySwapchainKHR, "vkDestroySwapchainKHR", "vkDestroySwapchainKHR()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkDestroyDescriptorPool, "vkDestroyDescriptorPool", "vkDestroyDescriptorPool()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkDestroyFramebuffer, "vkDestroyFramebuffer", "vkDestroyFramebuffer()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkDestroyPipeline, "vkDestroyPipeline", "vkDestroyPipeline()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkDestroyImageView, "vkDestroyImageView", "vkDestroyImageView()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkDestroyImage, "vkDestroyImage", "vkDestroyImage()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkDestroyBufferView, "vkDestroyBufferView", "vkDestroyBufferView()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkDestroyBuffer, "vkDestroyBuffer", "vkDestroyBuffer()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkDestroyQueryPool, "vkDestroyQueryPool", "vkDestroyQueryPool()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkDestroyEvent, "vkDestroyEvent", "vkDestroyEvent()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkDestroySemaphore, "vkDestroySemaphore", "vkDestroySemaphore()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkDestroyFence, "vkDestroyFence", "vkDestroyFence()")
			else ADD_DEVICE_ICD_COMMAND_HOOK(VkDestroyDevice, "vkDestroyDevice", "vkDestroyDevice()")
		}

		return result;
	}

	// Global Hook Definitions

	thread_local size_t g_VKCallDepthVkCreateInstance = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateInstance, pCreateInfo, pAllocator, pInstance);
		
		//Add the instance to the list
		if (result == VK_SUCCESS) {
			s_ActiveInstances.push_back(*pInstance);
		}

		return result;
	}

	thread_local size_t g_VKCallDepthVkCreateDevice = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDevice* pDevice)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateDevice, physicalDevice, pCreateInfo, pAllocator, pDevice);

		return result;
	}

	thread_local size_t g_VKCallDepthVkCreateFence = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateFence(VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateFence, device, pCreateInfo, pAllocator, pFence);

		return result;
	}

	thread_local size_t g_VKCallDepthVkCreateSemaphore = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateSemaphore, device, pCreateInfo, pAllocator, pSemaphore);

		return result;
	}

	thread_local size_t g_VKCallDepthVkCreateEvent = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateEvent(VkDevice device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateEvent, device, pCreateInfo, pAllocator, pEvent);

		return result;
	}

	thread_local size_t g_VKCallDepthVkCreateQueryPool = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateQueryPool, device, pCreateInfo, pAllocator, pQueryPool);

		return result;
	}

	thread_local size_t g_VKCallDepthVkCreateBuffer = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateBuffer(VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateBuffer, device, pCreateInfo, pAllocator, pBuffer);

		return result;
	}

	thread_local size_t g_VKCallDepthVkCreateBufferView = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateBufferView(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateBufferView, device, pCreateInfo, pAllocator, pView);

		return result;
	}

	thread_local size_t g_VKCallDepthVkCreateImage = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateImage(VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateImage, device, pCreateInfo, pAllocator, pImage);

		return result;
	}

	thread_local size_t g_VKCallDepthVkCreateImageView = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateImageView, device, pCreateInfo, pAllocator, pView);

		return result;
	}

	thread_local size_t g_VKCallDepthVkCreateGraphicsPipelines = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateGraphicsPipelines, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

		return result;
	}

	thread_local size_t g_VKCallDepthVkCreateFramebuffer = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateFramebuffer, device, pCreateInfo, pAllocator, pFramebuffer);

		return result;
	}

	thread_local size_t g_VKCallDepthVkCreateDescriptorPool = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateDescriptorPool, device, pCreateInfo, pAllocator, pDescriptorPool);

		return result;
	}

	thread_local size_t g_VKCallDepthVkCreateWin32SurfaceKHR = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateWin32SurfaceKHR(VkInstance instance, const VkWin32SurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateWin32SurfaceKHR, instance, pCreateInfo, pAllocator, pSurface);

		return result;
	}

	thread_local size_t g_VKCallDepthVkCreateSwapchainKHR = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateSwapchainKHR, device, pCreateInfo, pAllocator, pSwapchain);

		return result;
	}

	thread_local size_t g_VKCallDepthVkCreateRenderPass = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateRenderPass, device, pCreateInfo, pAllocator, pRenderPass);

		return result;
	}



	thread_local size_t g_VKCallDepthVkAllocateCommandBuffers = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkAllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		static VkResult result = {};
		DETOUR_RETURN(result, VkAllocateCommandBuffers, device, pAllocateInfo, pCommandBuffers);

		return result;
	}

	thread_local size_t g_VKCallDepthVkBeginCommandBuffer = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkBeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		static VkResult result = {};
		DETOUR_RETURN(result, VkBeginCommandBuffer, commandBuffer, pBeginInfo);

		return result;
	}

	thread_local size_t g_VKCallDepthVkCmdBeginRenderPass = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkCmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		DETOUR_VOID(VkCmdBeginRenderPass, commandBuffer, pRenderPassBegin, contents);
	}



	thread_local size_t g_VKCallDepthVkGetDeviceQueue = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		DETOUR_VOID(VkGetDeviceQueue, device, queueFamilyIndex, queueIndex, pQueue);
	}

	thread_local size_t g_VKCallDepthVkAcquireNextImageKHR = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkAcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		static VkResult result = {};
		DETOUR_RETURN(result, VkAcquireNextImageKHR, device, swapchain, timeout, semaphore, fence, pImageIndex);

		return result;
	}

	thread_local size_t g_VKCallDepthVkQueueSubmit = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkQueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		static VkResult result = {};
		DETOUR_RETURN(result, VkQueueSubmit, queue, submitCount, pSubmits, fence);

		return result;
	}

	thread_local size_t g_VKCallDepthVkQueuePresentKHR = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkQueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		static VkResult result = {};
		DETOUR_RETURN(result, VkQueuePresentKHR, queue, pPresentInfo);

		return result;
	}



	thread_local size_t g_VKCallDepthVkCmdEndRenderPass = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkCmdEndRenderPass(VkCommandBuffer commandBuffer)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		DETOUR_VOID(VkCmdEndRenderPass, commandBuffer);
	}

	thread_local size_t g_VKCallDepthVkEndCommandBuffer = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkEndCommandBuffer(VkCommandBuffer commandBuffer)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		static VkResult result = {};
		DETOUR_RETURN(result, VkEndCommandBuffer, commandBuffer);

		return result;
	}

	thread_local size_t g_VKCallDepthVkFreeCommandBuffers = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkFreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		DETOUR_VOID(VkFreeCommandBuffers, device, commandPool, commandBufferCount, pCommandBuffers);
	}



	thread_local size_t g_VKCallDepthVkDestroyRenderPass = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		DETOUR_VOID(VkDestroyRenderPass, device, renderPass, pAllocator);
	}

	thread_local size_t g_VKCallDepthVkDestroySwapchainKHR = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		DETOUR_VOID(VkDestroySwapchainKHR, device, swapchain, pAllocator);
	}

	thread_local size_t g_VKCallDepthVkDestroySurfaceKHR = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroySurfaceKHR(VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		DETOUR_VOID(VkDestroySurfaceKHR, instance, surface, pAllocator);
	}

	thread_local size_t g_VKCallDepthVkDestroyDescriptorPool = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroyDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		DETOUR_VOID(VkDestroyDescriptorPool, device, descriptorPool, pAllocator);
	}

	thread_local size_t g_VKCallDepthVkDestroyFramebuffer = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		DETOUR_VOID(VkDestroyFramebuffer, device, framebuffer, pAllocator);
	}

	thread_local size_t g_VKCallDepthVkDestroyPipeline = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		DETOUR_VOID(VkDestroyPipeline, device, pipeline, pAllocator);
	}

	thread_local size_t g_VKCallDepthVkDestroyImageView = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		DETOUR_VOID(VkDestroyImageView, device, imageView, pAllocator);
	}

	thread_local size_t g_VKCallDepthVkDestroyImage = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		DETOUR_VOID(VkDestroyImage, device, image, pAllocator);
	}

	thread_local size_t g_VKCallDepthVkDestroyBufferView = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroyBufferView(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		DETOUR_VOID(VkDestroyBufferView, device, bufferView, pAllocator);
	}

	thread_local size_t g_VKCallDepthVkDestroyBuffer = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		DETOUR_VOID(VkDestroyBuffer, device, buffer, pAllocator);
	}

	thread_local size_t g_VKCallDepthVkDestroyQueryPool = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroyQueryPool(VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		DETOUR_VOID(VkDestroyQueryPool, device, queryPool, pAllocator);
	}

	thread_local size_t g_VKCallDepthVkDestroyEvent = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		DETOUR_VOID(VkDestroyEvent, device, event, pAllocator);
	}

	thread_local size_t g_VKCallDepthVkDestroySemaphore = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		DETOUR_VOID(VkDestroySemaphore, device, semaphore, pAllocator);
	}

	thread_local size_t g_VKCallDepthVkDestroyFence = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		DETOUR_VOID(VkDestroyFence, device, fence, pAllocator);
	}

	thread_local size_t g_VKCallDepthVkDestroyDevice = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		DETOUR_VOID(VkDestroyDevice, device, pAllocator);
	}

	thread_local size_t g_VKCallDepthVkDestroyInstance = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };

		DETOUR_VOID(VkDestroyInstance, instance, pAllocator);
	}
}