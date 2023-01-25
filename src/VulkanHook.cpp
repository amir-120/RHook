#include "VulkanHook.hpp"

#include "../Log/Logging.hpp"

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
#define ADD_HOOK(SYMBOL, NAME) s_HookList[(size_t)HIdx::SYMBOL] = std::make_unique<FunctionHook>(real##SYMBOL##Fn, (uintptr_t)&VulkanHook::SYMBOL, NAME);

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

		// Set the active hooks
		for (size_t i = 0; i < s_HookList.size(); i++) {
			if (s_HookList[i]->Create()) {
				m_ActiveHookList[i] = s_HookList[i].get();
			}
			else {
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
				s_InstanceCommandMap.Map(instance, NAME, result, (uintptr_t)&VulkanHook::ICD##SYMBOL);																				\
																																													\
				const auto& commandHook = s_InstanceCommandMap.GetCommandHookFromInstanceHandle(instance, NAME);																	\
				if (commandHook.has_value() && !commandHook.value().get()->IsValid()) {																								\
					commandHook.value().get()->SetName("ICD - " LOGNAME);																											\
					if (commandHook.value().get()->Create()) {																														\
						RH_RHOOK_INFO("[VULKAN HOOK] Hooked ICD " LOGNAME " at {:p} for device: {:p}", (void*)result, (void*)instance);													\
					}																																								\
					else {																																							\
						RH_RHOOK_ERROR("[VULKAN HOOK] Failed to hook " LOGNAME " at {:p} obtained from vkGetInstanceProcAddr(). Instance = {:p}", (void*)result, (void*)instance);		\
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
				s_DeviceCommandMap.Map(device, NAME, result, (uintptr_t)&VulkanHook::ICD##SYMBOL);																					\
																																													\
				const auto& commandHook = s_DeviceCommandMap.GetCommandHookFromDeviceHandle(device, NAME);																			\
				if (commandHook.has_value() && !commandHook.value().get()->IsValid()) {																								\
					commandHook.value().get()->SetName("ICD - " LOGNAME);																											\
					if (commandHook.value().get()->Create()) {																														\
						RH_RHOOK_INFO("[VULKAN HOOK] Hooked ICD " LOGNAME " at {:p} for device: {:p}", (void*)result, (void*)device);														\
					}																																								\
					else {																																							\
						RH_RHOOK_ERROR("[VULKAN HOOK] Failed to hook " LOGNAME " at {:p} obtained from vkGetDeviceProcAddr(). Device = {:p}", (void*)result, (void*)device);				\
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

	// ICD Hook Definitions
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::ICDVkCreateFence(VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateFence];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateFence] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkCreateFence").get();
		auto res = VulkanHook::VkCreateFence(device, pCreateInfo, pAllocator, pFence);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateFence] = hookBack;
		return res;
	}

	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::ICDVkCreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateSemaphore];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateSemaphore] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkCreateSemaphore").get();
		auto res = VulkanHook::VkCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateSemaphore] = hookBack;
		return res;
	}

	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::ICDVkCreateEvent(VkDevice device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateEvent];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateEvent] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkCreateEvent").get();
		auto res = VulkanHook::VkCreateEvent(device, pCreateInfo, pAllocator, pEvent);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateEvent] = hookBack;
		return res;
	}

	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::ICDVkCreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateQueryPool];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateQueryPool] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkCreateQueryPool").get();
		auto res = VulkanHook::VkCreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateQueryPool] = hookBack;
		return res;
	}

	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::ICDVkCreateBuffer(VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateBuffer];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateBuffer] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkCreateBuffer").get();
		auto res = VulkanHook::VkCreateBuffer(device, pCreateInfo, pAllocator, pBuffer);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateBuffer] = hookBack;
		return res;
	}

	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::ICDVkCreateBufferView(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateBufferView];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateBufferView] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkCreateBufferView").get();
		auto res = VulkanHook::VkCreateBufferView(device, pCreateInfo, pAllocator, pView);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateBufferView] = hookBack;
		return res;
	}

	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::ICDVkCreateImage(VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateImage];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateImage] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkCreateImage").get();
		auto res = VulkanHook::VkCreateImage(device, pCreateInfo, pAllocator, pImage);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateImage] = hookBack;
		return res;
	}

	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::ICDVkCreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateImageView];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateImageView] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkCreateImageView").get();
		auto res = VulkanHook::VkCreateImageView(device, pCreateInfo, pAllocator, pView);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateImageView] = hookBack;
		return res;
	}

	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::ICDVkCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateGraphicsPipelines];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateGraphicsPipelines] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkCreateGraphicsPipelines").get();
		auto res = VulkanHook::VkCreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateGraphicsPipelines] = hookBack;
		return res;
	}

	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::ICDVkCreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateFramebuffer];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateFramebuffer] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkCreateFramebuffer").get();
		auto res = VulkanHook::VkCreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateFramebuffer] = hookBack;
		return res;
	}

	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::ICDVkCreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateDescriptorPool];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateDescriptorPool] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkCreateDescriptorPool").get();
		auto res = VulkanHook::VkCreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateDescriptorPool] = hookBack;
		return res;
	}

	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::ICDVkCreateWin32SurfaceKHR(VkInstance instance, const VkWin32SurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateWin32SurfaceKHR];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateWin32SurfaceKHR] = s_InstanceCommandMap.UnsafeGetCommandHookFromInstanceHandle(instance, "vkCreateWin32SurfaceKHR").get();
		auto res = VulkanHook::VkCreateWin32SurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateWin32SurfaceKHR] = hookBack;
		return res;
	}

	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::ICDVkCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateSwapchainKHR];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateSwapchainKHR] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkCreateSwapchainKHR").get();
		auto res = VulkanHook::VkCreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateSwapchainKHR] = hookBack;
		return res;
	}

	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::ICDVkCreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateRenderPass];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateRenderPass] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkCreateRenderPass").get();
		auto res = VulkanHook::VkCreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCreateRenderPass] = hookBack;
		return res;
	}



	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::ICDVkAllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkAllocateCommandBuffers];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkAllocateCommandBuffers] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkAllocateCommandBuffers").get();
		auto res = VulkanHook::VkAllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkAllocateCommandBuffers] = hookBack;
		return res;
	}

	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::ICDVkBeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkBeginCommandBuffer];
		const auto& device = s_QueueMap.UnsafeGetParentHandleFromObjectHandle((VkQueue)commandBuffer);//s_CMDBufferMap.UnsafeGetParentHandleFromObjectHandle(commandBuffer);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkBeginCommandBuffer] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkBeginCommandBuffer").get();
		auto res = VulkanHook::VkBeginCommandBuffer(commandBuffer, pBeginInfo);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkBeginCommandBuffer] = hookBack;
		return res;
	}

	VKAPI_ATTR void VKAPI_CALL VulkanHook::ICDVkCmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCmdBeginRenderPass];
		const auto& device = s_QueueMap.UnsafeGetParentHandleFromObjectHandle((VkQueue)commandBuffer);//s_CMDBufferMap.UnsafeGetParentHandleFromObjectHandle(commandBuffer);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCmdBeginRenderPass] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkCmdBeginRenderPass").get();
		VulkanHook::VkCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCmdBeginRenderPass] = hookBack;
	}



	VKAPI_ATTR void VKAPI_CALL VulkanHook::ICDVkGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkGetDeviceQueue];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkGetDeviceQueue] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkGetDeviceQueue").get();
		VulkanHook::VkGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkGetDeviceQueue] = hookBack;
	}

	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::ICDVkAcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkAcquireNextImageKHR];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkAcquireNextImageKHR] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkAcquireNextImageKHR").get();
		auto res = VulkanHook::VkAcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkAcquireNextImageKHR] = hookBack;
		return res;
	}

	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::ICDVkQueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkQueueSubmit];
		const auto& device = s_QueueMap.UnsafeGetParentHandleFromObjectHandle(queue);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkQueueSubmit] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkQueueSubmit").get();
		auto res = VulkanHook::VkQueueSubmit(queue, submitCount, pSubmits, fence);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkQueueSubmit] = hookBack;
		return res;
	}


	
	VKAPI_ATTR void VKAPI_CALL VulkanHook::ICDVkCmdEndRenderPass(VkCommandBuffer commandBuffer)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCmdEndRenderPass];
		const auto& device = s_QueueMap.UnsafeGetParentHandleFromObjectHandle((VkQueue)commandBuffer);//s_CMDBufferMap.UnsafeGetParentHandleFromObjectHandle(commandBuffer);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCmdEndRenderPass] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkCmdEndRenderPass").get();
		VulkanHook::VkCmdEndRenderPass(commandBuffer);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkCmdEndRenderPass] = hookBack;
	}

	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::ICDVkEndCommandBuffer(VkCommandBuffer commandBuffer)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkEndCommandBuffer];
		const auto& device = s_QueueMap.UnsafeGetParentHandleFromObjectHandle((VkQueue)commandBuffer);//s_CMDBufferMap.UnsafeGetParentHandleFromObjectHandle(commandBuffer);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkEndCommandBuffer] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkEndCommandBuffer").get();
		auto res = VulkanHook::VkEndCommandBuffer(commandBuffer);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkEndCommandBuffer] = hookBack;
		return res;
	}

	VKAPI_ATTR void VKAPI_CALL VulkanHook::ICDVkFreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkFreeCommandBuffers];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkFreeCommandBuffers] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkFreeCommandBuffers").get();
		VulkanHook::VkFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkFreeCommandBuffers] = hookBack;
	}



	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::ICDVkQueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkQueuePresentKHR];
		const auto& device = s_QueueMap.UnsafeGetParentHandleFromObjectHandle(queue);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkQueuePresentKHR] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkQueuePresentKHR").get();
		auto res = VulkanHook::VkQueuePresentKHR(queue, pPresentInfo);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkQueuePresentKHR] = hookBack;
		return res;
	}

	VKAPI_ATTR void VKAPI_CALL VulkanHook::ICDVkDestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyRenderPass];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyRenderPass] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkDestroyRenderPass").get();
		VulkanHook::VkDestroyRenderPass(device, renderPass, pAllocator);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyRenderPass] = hookBack;
	}


	VKAPI_ATTR void VKAPI_CALL VulkanHook::ICDVkDestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroySwapchainKHR];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroySwapchainKHR] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkDestroySwapchainKHR").get();
		VulkanHook::VkDestroySwapchainKHR(device, swapchain, pAllocator);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroySwapchainKHR] = hookBack;
	}

	VKAPI_ATTR void VKAPI_CALL VulkanHook::ICDVkDestroySurfaceKHR(VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroySurfaceKHR];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroySurfaceKHR] = s_InstanceCommandMap.UnsafeGetCommandHookFromInstanceHandle(instance, "vkDestroySurfaceKHR").get();
		VulkanHook::VkDestroySurfaceKHR(instance, surface, pAllocator);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroySurfaceKHR] = hookBack;
	}

	VKAPI_ATTR void VKAPI_CALL VulkanHook::ICDVkDestroyDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyDescriptorPool];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyDescriptorPool] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkDestroyDescriptorPool").get();
		VulkanHook::VkDestroyDescriptorPool(device, descriptorPool, pAllocator);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyDescriptorPool] = hookBack;
	}

	VKAPI_ATTR void VKAPI_CALL VulkanHook::ICDVkDestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyFramebuffer];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyFramebuffer] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkDestroyFramebuffer").get();
		VulkanHook::VkDestroyFramebuffer(device, framebuffer, pAllocator);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyFramebuffer] = hookBack;
	}

	VKAPI_ATTR void VKAPI_CALL VulkanHook::ICDVkDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyPipeline];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyPipeline] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkDestroyPipeline").get();
		VulkanHook::VkDestroyPipeline(device, pipeline, pAllocator);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyPipeline] = hookBack;
	}

	VKAPI_ATTR void VKAPI_CALL VulkanHook::ICDVkDestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyImageView];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyImageView] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkDestroyImageView").get();
		VulkanHook::VkDestroyImageView(device, imageView, pAllocator);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyImageView] = hookBack;
	}

	VKAPI_ATTR void VKAPI_CALL VulkanHook::ICDVkDestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyImage];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyImage] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkDestroyImage").get();
		VulkanHook::VkDestroyImage(device, image, pAllocator);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyImage] = hookBack;
	}

	VKAPI_ATTR void VKAPI_CALL VulkanHook::ICDVkDestroyBufferView(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyBufferView];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyBufferView] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkDestroyBufferView").get();
		VulkanHook::VkDestroyBufferView(device, bufferView, pAllocator);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyBufferView] = hookBack;
	}

	VKAPI_ATTR void VKAPI_CALL VulkanHook::ICDVkDestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyBuffer];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyBuffer] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkDestroyBuffer").get();
		VulkanHook::VkDestroyBuffer(device, buffer, pAllocator);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyBuffer] = hookBack;
	}

	VKAPI_ATTR void VKAPI_CALL VulkanHook::ICDVkDestroyQueryPool(VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyQueryPool];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyQueryPool] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkDestroyQueryPool").get();
		VulkanHook::VkDestroyQueryPool(device, queryPool, pAllocator);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyQueryPool] = hookBack;
	}

	VKAPI_ATTR void VKAPI_CALL VulkanHook::ICDVkDestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyEvent];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyEvent] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkDestroyEvent").get();
		VulkanHook::VkDestroyEvent(device, event, pAllocator);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyEvent] = hookBack;
	}

	VKAPI_ATTR void VKAPI_CALL VulkanHook::ICDVkDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroySemaphore];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroySemaphore] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkDestroySemaphore").get();
		VulkanHook::VkDestroySemaphore(device, semaphore, pAllocator);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroySemaphore] = hookBack;
	}

	VKAPI_ATTR void VKAPI_CALL VulkanHook::ICDVkDestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyFence];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyFence] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkDestroyFence").get();
		VulkanHook::VkDestroyFence(device, fence, pAllocator);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyFence] = hookBack;
	}

	VKAPI_ATTR void VKAPI_CALL VulkanHook::ICDVkDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyDevice];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyDevice] = s_DeviceCommandMap.UnsafeGetCommandHookFromDeviceHandle(device, "vkDestroyDevice").get();
		VulkanHook::VkDestroyDevice(device, pAllocator);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyDevice] = hookBack;
	}

	VKAPI_ATTR void VKAPI_CALL VulkanHook::ICDVkDestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator)
	{
		const auto hookBack = g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyInstance];

		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyInstance] = s_InstanceCommandMap.UnsafeGetCommandHookFromInstanceHandle(instance, "vkDestroyInstance").get();
		VulkanHook::VkDestroyInstance(instance, pAllocator);
		g_VulkanHook->m_ActiveHookList[(uint64_t)HIdx::VkDestroyInstance] = hookBack;
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

		//Add the device to the list
		if (result == VK_SUCCESS) {
			s_ActiveDevices.push_back(*pDevice);
		}

		// Map the VkQueues of the device
		{
			uint32_t count;
			vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &count, NULL);
			
			for (size_t i = 0; i < pCreateInfo->queueCreateInfoCount; i++) {
				for (size_t j = 0; j < pCreateInfo->pQueueCreateInfos[i].queueCount; j++) {
					VkQueue queue;
					vkGetDeviceQueue(*pDevice, pCreateInfo->pQueueCreateInfos[i].queueFamilyIndex, j, &queue);

					s_QueueMap.Map(queue, *pDevice);
				}
			}
		}

		return result;
	}

	thread_local size_t g_VKCallDepthVkCreateFence = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateFence(VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateFence, device, pCreateInfo, pAllocator, pFence);

		// Map the created VkFence
		if (result == VK_SUCCESS) {
			s_FenceMap.Map(*pFence, device);
		}

		return result;
	}

	thread_local size_t g_VKCallDepthVkCreateSemaphore = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateSemaphore, device, pCreateInfo, pAllocator, pSemaphore);

		// Map the created VkSemaphore
		if (result == VK_SUCCESS) {
			s_SemaphoreMap.Map(*pSemaphore, device);
		}

		return result;
	}

	thread_local size_t g_VKCallDepthVkCreateEvent = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateEvent(VkDevice device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateEvent, device, pCreateInfo, pAllocator, pEvent);

		// Map the created VkEvent
		if (result == VK_SUCCESS) {
			s_EventMap.Map(*pEvent, device);
		}

		return result;
	}

	thread_local size_t g_VKCallDepthVkCreateQueryPool = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateQueryPool, device, pCreateInfo, pAllocator, pQueryPool);

		// Map the created VkQueryPool
		if (result == VK_SUCCESS) {
			s_QueryPoolMap.Map(*pQueryPool, device);
		}

		return result;
	}

	thread_local size_t g_VKCallDepthVkCreateBuffer = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateBuffer(VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateBuffer, device, pCreateInfo, pAllocator, pBuffer);

		// Map the created VkBuffer
		if (result == VK_SUCCESS) {
			s_BufferMap.Map(*pBuffer, device);
		}

		return result;
	}

	thread_local size_t g_VKCallDepthVkCreateBufferView = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateBufferView(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateBufferView, device, pCreateInfo, pAllocator, pView);

		// Map the created VkBufferView
		if (result == VK_SUCCESS) {
			s_BufferViewMap.Map(*pView, device);
		}

		return result;
	}

	thread_local size_t g_VKCallDepthVkCreateImage = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateImage(VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateImage, device, pCreateInfo, pAllocator, pImage);

		// Map the created VkImage
		if (result == VK_SUCCESS) {
			s_ImageMap.Map(*pImage, device);
		}

		return result;
	}

	thread_local size_t g_VKCallDepthVkCreateImageView = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateImageView, device, pCreateInfo, pAllocator, pView);

		// Map the created VkImageView
		if (result == VK_SUCCESS) {
			s_ImageViewMap.Map(*pView, device);
		}

		return result;
	}

	thread_local size_t g_VKCallDepthVkCreateGraphicsPipelines = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateGraphicsPipelines, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

		// Map the created VkPipeLines
		if (result == VK_SUCCESS) {
			for (size_t i = 0; i < createInfoCount; i++) {
				s_PipelineMap.Map(pPipelines[i], device);
			}
		}

		return result;
	}

	thread_local size_t g_VKCallDepthVkCreateFramebuffer = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateFramebuffer, device, pCreateInfo, pAllocator, pFramebuffer);

		// Map the created VkFramebuffer
		if (result == VK_SUCCESS) {
			s_FramebufferMap.Map(*pFramebuffer, device);
		}

		return result;
	}

	thread_local size_t g_VKCallDepthVkCreateDescriptorPool = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateDescriptorPool, device, pCreateInfo, pAllocator, pDescriptorPool);

		// Map the created VkDescriptorPool
		if (result == VK_SUCCESS) {
			s_DescriptorPoolMap.Map(*pDescriptorPool, device);
		}

		return result;
	}

	thread_local size_t g_VKCallDepthVkCreateWin32SurfaceKHR = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateWin32SurfaceKHR(VkInstance instance, const VkWin32SurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateWin32SurfaceKHR, instance, pCreateInfo, pAllocator, pSurface);

		// Map the created VkSurface
		if (result == VK_SUCCESS) {
			s_SurfaceKHRMap.Map(*pSurface, instance);
		}

		return result;
	}

	thread_local size_t g_VKCallDepthVkCreateSwapchainKHR = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateSwapchainKHR, device, pCreateInfo, pAllocator, pSwapchain);

		// Map the created VkSwapchainKHR
		if (result == VK_SUCCESS) {
			s_SwapchainKHRMap.Map(*pSwapchain, device);
		}

		return result;
	}

	thread_local size_t g_VKCallDepthVkCreateRenderPass = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkCreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		static VkResult result = {};
		DETOUR_RETURN(result, VkCreateRenderPass, device, pCreateInfo, pAllocator, pRenderPass);

		// Map the created VkRenderPass
		if (result == VK_SUCCESS) {
			s_RenderPassMap.Map(*pRenderPass, device);
		}

		return result;
	}



	thread_local size_t g_VKCallDepthVkAllocateCommandBuffers = 0;
	VKAPI_ATTR VkResult VKAPI_CALL VulkanHook::VkAllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		static VkResult result = {};
		DETOUR_RETURN(result, VkAllocateCommandBuffers, device, pAllocateInfo, pCommandBuffers);

		// Map the created VkCommandBuffers
		if (result == VK_SUCCESS) {
			for (size_t i = 0; i < pAllocateInfo->commandBufferCount; i++) {
				s_QueueMap.Map((VkQueue)pCommandBuffers[i], device); //s_CMDBufferMap.Map(pCommandBuffers[i], device);
			}
		}

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

		// Remove the destroyed VkCommandBuffers from the map
		for (size_t i = 0; i < commandBufferCount; i++) {
			s_QueueMap.RemoveObject((VkQueue)pCommandBuffers[i]); //s_CMDBufferMap.RemoveObject(pCommandBuffers[i]);
		}
	}



	thread_local size_t g_VKCallDepthVkDestroyRenderPass = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		DETOUR_VOID(VkDestroyRenderPass, device, renderPass, pAllocator);

		// Remove the destroyed VkRenderPass from the map
		s_RenderPassMap.RemoveObject(renderPass);
	}

	thread_local size_t g_VKCallDepthVkDestroySwapchainKHR = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		DETOUR_VOID(VkDestroySwapchainKHR, device, swapchain, pAllocator);

		// Remove the destroyed VkSwapchainKHR from the map
		s_SwapchainKHRMap.RemoveObject(swapchain);
	}

	thread_local size_t g_VKCallDepthVkDestroySurfaceKHR = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroySurfaceKHR(VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		DETOUR_VOID(VkDestroySurfaceKHR, instance, surface, pAllocator);

		// Remove the destroyed VkSurface from the map
		s_SurfaceKHRMap.RemoveObject(surface);
	}

	thread_local size_t g_VKCallDepthVkDestroyDescriptorPool = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroyDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		DETOUR_VOID(VkDestroyDescriptorPool, device, descriptorPool, pAllocator);

		// Remove the destroyed VkDescriptorPool from the map
		s_DescriptorPoolMap.RemoveObject(descriptorPool);
	}

	thread_local size_t g_VKCallDepthVkDestroyFramebuffer = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		DETOUR_VOID(VkDestroyFramebuffer, device, framebuffer, pAllocator);

		// Remove the destroyed VkFramebuffer from the map
		s_FramebufferMap.RemoveObject(framebuffer);
	}

	thread_local size_t g_VKCallDepthVkDestroyPipeline = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		DETOUR_VOID(VkDestroyPipeline, device, pipeline, pAllocator);

		// Remove the destroyed VkPipeline from the map
		s_PipelineMap.RemoveObject(pipeline);
	}

	thread_local size_t g_VKCallDepthVkDestroyImageView = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		DETOUR_VOID(VkDestroyImageView, device, imageView, pAllocator);

		// Remove the destroyed VkImageView from the map
		s_ImageViewMap.RemoveObject(imageView);
	}

	thread_local size_t g_VKCallDepthVkDestroyImage = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		DETOUR_VOID(VkDestroyImage, device, image, pAllocator);

		// Remove the destroyed VkImage from the map
		s_ImageMap.RemoveObject(image);
	}

	thread_local size_t g_VKCallDepthVkDestroyBufferView = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroyBufferView(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		DETOUR_VOID(VkDestroyBufferView, device, bufferView, pAllocator);

		// Remove the destroyed VkBufferView from the map
		s_BufferViewMap.RemoveObject(bufferView);
	}

	thread_local size_t g_VKCallDepthVkDestroyBuffer = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		DETOUR_VOID(VkDestroyBuffer, device, buffer, pAllocator);

		// Remove the destroyed VkBuffer from the map
		s_BufferMap.RemoveObject(buffer);
	}

	thread_local size_t g_VKCallDepthVkDestroyQueryPool = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroyQueryPool(VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		DETOUR_VOID(VkDestroyQueryPool, device, queryPool, pAllocator);

		// Remove the destroyed VkQueryPool from the map
		s_QueryPoolMap.RemoveObject(queryPool);
	}

	thread_local size_t g_VKCallDepthVkDestroyEvent = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		DETOUR_VOID(VkDestroyEvent, device, event, pAllocator);

		// Remove the destroyed VkEvent from the map
		s_EventMap.RemoveObject(event);
	}

	thread_local size_t g_VKCallDepthVkDestroySemaphore = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		DETOUR_VOID(VkDestroySemaphore, device, semaphore, pAllocator);

		// Remove the destroyed VkSemaphore from the map
		s_SemaphoreMap.RemoveObject(semaphore);
	}

	thread_local size_t g_VKCallDepthVkDestroyFence = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		DETOUR_VOID(VkDestroyFence, device, fence, pAllocator);

		// Remove the destroyed VkFence from the map
		s_FenceMap.RemoveObject(fence);
	}

	thread_local size_t g_VKCallDepthVkDestroyDevice = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		DETOUR_VOID(VkDestroyDevice, device, pAllocator);

		// Remove the destroyed VkDevice from the maps and the active device list
		RemoveDeviceFromMaps(device);
	}

	thread_local size_t g_VKCallDepthVkDestroyInstance = 0;
	VKAPI_ATTR void VKAPI_CALL VulkanHook::VkDestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator)
	{
		std::scoped_lock _{ *g_VulkanHook->m_HookMutex };
		DETOUR_VOID(VkDestroyInstance, instance, pAllocator);

		// Remove the destroyed VkInstance from the maps and the active instance list
		RemoveInstanceFromMaps(instance);
	}
}