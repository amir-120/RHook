#pragma once

#include <assert.h>
#include <functional>
#include <array>
#include <memory>
#include <mutex>
#include <optional>
#include <algorithm>

#pragma comment(lib, "Vulkan-1.Lib")

#define VK_USE_PLATFORM_WIN32_KHR
#include <vulkan/vulkan.h>

#include "../utility/SmartFunctionHook.hpp"

#define VULKANHOOK_INTERNAL(X) RHook::VulkanHook::SkipDetours([&]() X)

namespace RHook {
	class VkInstanceCommandsMap {
	public:
		VkInstanceCommandsMap() = default;
		~VkInstanceCommandsMap() = default;

		template <typename CType>
		void Map(VkInstance hInstance, const char* pCommandName, CType* icdCommand, SmartFunctionHook** ppActiveHook, CType* detour = nullptr) {
			// ICD Command to instance handle map
			{
				if (!m_ICDCommandToInstanceHandleMap.contains((uintptr_t)icdCommand)) {
					m_ICDCommandToInstanceHandleMap.insert({ (uintptr_t)icdCommand, hInstance });
				}
			}

			// Instance handle to ICD command hooks map
			if (detour != nullptr) {
				auto& instanceMap = m_InstanceHandleToICDCommandHooksMap[hInstance];
				if (!instanceMap.contains(pCommandName)) {
					instanceMap.insert({ pCommandName, std::make_unique<SmartFunctionHook>(icdCommand, detour, ppActiveHook) });
				}
			}

			// Instance handle to ICD command map
			{
				auto& instanceMap = m_InstanceHandleToICDCommandsMap[hInstance];
				if (!instanceMap.contains(pCommandName)) {
					instanceMap.insert({ pCommandName, icdCommand });
				}
			}
		}

		bool HookAll() {
			bool hooked = true;
			for (const auto& instanceHooks : m_InstanceHandleToICDCommandHooksMap) {
				for (const auto& hook : instanceHooks.second) {
					hooked = hooked && hook.second->Create();
				}
			}

			return hooked;
		}

		bool UnhookAll() {
			bool unhooked = true;
			for (const auto& instanceHooks : m_InstanceHandleToICDCommandHooksMap) {
				for (const auto& hook : instanceHooks.second) {
					unhooked = unhooked && hook.second->Unhook();
				}
			}

			return unhooked;
		}

		bool RemoveAllHooks() {
			bool removed = true;
			for (const auto& instanceHooks : m_InstanceHandleToICDCommandHooksMap) {
				for (const auto& hook : instanceHooks.second) {
					removed = removed && hook.second->Remove();
				}
			}

			return removed;
		}

		bool RemoveInstance(VkInstance hInstance) {
			const auto instanceDT = *(uintptr_t*)hInstance;

			if (!m_InstanceHandleToICDCommandsMap.contains(hInstance)) {
				return false;
			}

			for (const auto& icdCommand : m_InstanceHandleToICDCommandsMap.at(hInstance)) {
				m_ICDCommandToInstanceHandleMap.erase(icdCommand.second);
			}
			m_InstanceHandleToICDCommandsMap.erase(hInstance);

			// User can have no hooks set up for the command
			if (m_InstanceHandleToICDCommandHooksMap.contains(hInstance)) {
				m_InstanceHandleToICDCommandHooksMap.erase(hInstance);
			}

			return true;
		}

		void Clear() {
			m_ICDCommandToInstanceHandleMap.clear();
			m_InstanceHandleToICDCommandHooksMap.clear();
			m_InstanceHandleToICDCommandsMap.clear();
		}

		inline auto& UnsafeGetCommandHookFromInstanceHandle(VkInstance hInstance, const char* pName) {
			return m_InstanceHandleToICDCommandHooksMap.at(hInstance).at(pName);
		}

		std::optional<std::reference_wrapper<std::unique_ptr<SmartFunctionHook>>> GetCommandHookFromInstanceHandle(VkInstance hInstance, const char* pName) {
			if (!m_InstanceHandleToICDCommandHooksMap.contains(hInstance)) {
				return {};
			}

			if (!m_InstanceHandleToICDCommandHooksMap.at(hInstance).contains(pName)) {
				return {};
			}

			return m_InstanceHandleToICDCommandHooksMap.at(hInstance).at(pName);
		}

		inline auto& UnsafeGetCommandFromInstanceHandle(VkInstance instance, const char* pName) {
			return m_InstanceHandleToICDCommandsMap.at(instance).at(pName);
		}

		Address GetCommandFromInstanceHandle(VkInstance hInstance, const char* pName) {
			if (!m_InstanceHandleToICDCommandsMap.contains(hInstance)) {
				return nullptr;
			}

			if (!m_InstanceHandleToICDCommandsMap.at(hInstance).contains(pName)) {
				return nullptr;
			}

			return m_InstanceHandleToICDCommandsMap.at(hInstance).at(pName);
		}

		inline auto& UnsafeGetInstanceHandleFromCommand(Address icdCommand) {
			return m_ICDCommandToInstanceHandleMap.at(icdCommand);
		}

		VkInstance GetInstanceHandleFromCommand(Address icdCommand) {
			if (!m_ICDCommandToInstanceHandleMap.contains(icdCommand)) {
				return NULL;
			}

			return m_ICDCommandToInstanceHandleMap.at(icdCommand);
		}

	private:
		std::unordered_map<uintptr_t, VkInstance> m_ICDCommandToInstanceHandleMap{};

		std::unordered_map<VkInstance, std::unordered_map<std::string_view, std::unique_ptr<SmartFunctionHook>>> m_InstanceHandleToICDCommandHooksMap{};
		std::unordered_map<VkInstance, std::unordered_map<std::string_view, Address>> m_InstanceHandleToICDCommandsMap{};
	};

	class VkDeviceCommandsMap {
	public:
		VkDeviceCommandsMap() = default;
		~VkDeviceCommandsMap() = default;

		template <typename CType>
		void Map(VkDevice hDevice, const char* pCommandName, CType* icdCommand, SmartFunctionHook** ppActiveHook, CType* detour = nullptr) {
			// ICD Command to device handle map
			{
				if (!m_ICDCommandToDeviceHandleMap.contains((uintptr_t)icdCommand)) {
					m_ICDCommandToDeviceHandleMap.insert({ (uintptr_t)icdCommand, hDevice });
				}
			}

			// Device handle to ICD command hooks map
			if (detour != nullptr) {
				auto& deviceMap = m_DeviceHandleToICDCommandHooksMap[hDevice];
				if (!deviceMap.contains(pCommandName)) {
					deviceMap.insert({ pCommandName, std::make_unique<SmartFunctionHook>(icdCommand, detour, ppActiveHook) });
				}
			}

			// Device handle to ICD command map
			{
				auto& deviceMap = m_DeviceHandleToICDCommandsMap[hDevice];
				if (!deviceMap.contains(pCommandName)) {
					deviceMap.insert({ pCommandName, icdCommand });
				}
			}
		}

		bool HookAll() {
			bool hooked = true;
			for (const auto& deviceHooks : m_DeviceHandleToICDCommandHooksMap) {
				for (const auto& hook : deviceHooks.second) {
					hooked = hooked && hook.second->Create();
				}
			}

			return hooked;
		}

		bool UnhookAll() {
			bool unhooked = true;
			for (const auto& deviceHooks : m_DeviceHandleToICDCommandHooksMap) {
				for (const auto& hook : deviceHooks.second) {
					unhooked = unhooked && hook.second->Unhook();
				}
			}

			return unhooked;
		}

		bool RemoveAllHooks() {
			bool removed = true;
			for (const auto& deviceHooks : m_DeviceHandleToICDCommandHooksMap) {
				for (const auto& hook : deviceHooks.second) {
					removed = removed && hook.second->Remove();
				}
			}

			return removed;
		}

		bool RemoveDevice(VkDevice hDevice) {
			const auto deviceDT = *(uintptr_t*)hDevice;

			if (!m_DeviceHandleToICDCommandsMap.contains(hDevice)) {
				return false;
			}

			for (const auto& icdCommand : m_DeviceHandleToICDCommandsMap.at(hDevice)) {
				m_ICDCommandToDeviceHandleMap.erase(icdCommand.second);
			}
			m_DeviceHandleToICDCommandsMap.erase(hDevice);

			// User can have no hooks set up for the command
			if (m_DeviceHandleToICDCommandHooksMap.contains(hDevice)) {
				m_DeviceHandleToICDCommandHooksMap.erase(hDevice);
			}

			return true;
		}

		void Clear() {
			m_ICDCommandToDeviceHandleMap.clear();
			m_DeviceHandleToICDCommandHooksMap.clear();
			m_DeviceHandleToICDCommandsMap.clear();
		}

		inline auto& UnsafeGetCommandHookFromDeviceHandle(VkDevice hDevice, const char* pName) {
			return m_DeviceHandleToICDCommandHooksMap.at(hDevice).at(pName);
		}

		std::optional<std::reference_wrapper<std::unique_ptr<SmartFunctionHook>>> GetCommandHookFromDeviceHandle(VkDevice hDevice, const char* pName) {
			if (!m_DeviceHandleToICDCommandHooksMap.contains(hDevice)) {
				return {};
			}

			if (!m_DeviceHandleToICDCommandHooksMap.at(hDevice).contains(pName)) {
				return {};
			}

			return m_DeviceHandleToICDCommandHooksMap.at(hDevice).at(pName);
		}

		inline auto& UnsafeGetCommandFromDeviceHandle(VkDevice device, const char* pName) {
			return m_DeviceHandleToICDCommandsMap.at(device).at(pName);
		}

		Address GetCommandFromDeviceHandle(VkDevice hDevice, const char* pName) {
			if (!m_DeviceHandleToICDCommandsMap.contains(hDevice)) {
				return nullptr;
			}

			if (!m_DeviceHandleToICDCommandsMap.at(hDevice).contains(pName)) {
				return nullptr;
			}

			return m_DeviceHandleToICDCommandsMap.at(hDevice).at(pName);
		}

		inline auto& UnsafeGetDeviceHandleFromCommand(Address icdCommand) {
			return m_ICDCommandToDeviceHandleMap.at(icdCommand);
		}

		VkDevice GetDeviceHandleFromCommand(Address icdCommand) {
			if (!m_ICDCommandToDeviceHandleMap.contains(icdCommand)) {
				return NULL;
			}

			return m_ICDCommandToDeviceHandleMap.at(icdCommand);
		}

	private:
		std::unordered_map<uintptr_t, VkDevice> m_ICDCommandToDeviceHandleMap{};

		std::unordered_map<VkDevice, std::unordered_map<std::string_view, std::unique_ptr<SmartFunctionHook>>> m_DeviceHandleToICDCommandHooksMap{};
		std::unordered_map<VkDevice, std::unordered_map<std::string_view, Address>> m_DeviceHandleToICDCommandsMap{};
	};

	template<typename T, typename U>
	class VkObjectHandleMap {
	public:
		VkObjectHandleMap() = default;
		~VkObjectHandleMap() = default;

		void Map(T hObject, U hParent) {
			// Object handle to parent handle map
			{
				if (!m_ObjectHandleToParentHandleMap.contains(hObject)) {
					m_ObjectHandleToParentHandleMap.insert({ hObject, hParent });
				}
			}

			// Parent handle to object handles map
			{
				auto& deviceMap = m_ParentHandleToObjectHandlesMap[hParent];
				if (std::find(deviceMap.begin(), deviceMap.end(), hObject) == deviceMap.end()) {
					deviceMap.push_back(hObject);
				}
			}
		}

		bool RemoveObject(T hObject) {
			if (!m_ObjectHandleToParentHandleMap.contains(hObject)) {
				return false;
			}

			const auto& hParent = m_ObjectHandleToParentHandleMap.at(hObject);

			if (!m_ParentHandleToObjectHandlesMap.contains(hParent)) {
				return false;
			}

			auto& parentObjects = m_ParentHandleToObjectHandlesMap.at(hParent);
			
			for (const auto& match = std::find(parentObjects.begin(), parentObjects.end(), hObject); match != parentObjects.end();) {
				parentObjects.erase(match);
			}
		}

		bool RemoveParent(U hParent) {
			if (!m_ParentHandleToObjectHandlesMap.contains(hParent)) {
				return false;
			}

			for (const auto& hObject : m_ParentHandleToObjectHandlesMap.at(hParent)) {
				m_ObjectHandleToParentHandleMap.erase(hObject);
			}

			m_ParentHandleToObjectHandlesMap.erase(hParent);

			return true;
		}

		void Clear() {
			m_ObjectHandleToParentHandleMap.clear();
			m_ParentHandleToObjectHandlesMap.clear();
		}

		inline const auto& UnsafeGetObjectHandlesFromParentHandle(U hParent) {
			return m_ParentHandleToObjectHandlesMap.at(hParent);
		}

		std::optional<const std::reference_wrapper<std::vector<T>>> GetObjectHandlesFromParentHandle(U hParent) {
			if (!m_ParentHandleToObjectHandlesMap.contains(hParent)) {
				return {};
			}

			return m_ParentHandleToObjectHandlesMap.at(hParent);
		}

		inline auto& UnsafeGetParentHandleFromObjectHandle(T hObject) {
			return m_ObjectHandleToParentHandleMap.at(hObject);
		}

		U GetParentHandleFromObjectHandle(T hObject) {
			if (!m_ObjectHandleToParentHandleMap.contains(hObject)) {
				return NULL;
			}

			return m_ObjectHandleToParentHandleMap.at(hObject);
		}

	private:
		std::unordered_map<T, U> m_ObjectHandleToParentHandleMap{};
		std::unordered_map<U, std::vector<T>> m_ParentHandleToObjectHandlesMap{};
	};

	class VulkanHook {
	public:
		typedef std::function<void(VulkanHook&)> CallBackFn;

		VulkanHook() = delete;
		VulkanHook(const VulkanHook& other) = delete;
		VulkanHook(VulkanHook&& other) = delete;
		VulkanHook(std::recursive_mutex* hookMutex);
		virtual ~VulkanHook();

		bool Hook();
		bool Unhook();

		static const auto& IsHooked() { return s_Hooked; }

		static void SkipDetours(const std::function<void()>& code);

#define ADD_HOOK_METHODS(SYMBOL) auto& Get##SYMBOL##Params() const { assert(s_ParamList[(size_t)HIdx::SYMBOL] != nullptr,	\
		"Tried to access hook params outside call!");																		\
		return *(SYMBOL##Parameters_t*)s_ParamList[(size_t)HIdx::SYMBOL]; }													\
			static void Signal##SYMBOL##Detour(const bool& state) { s_DetourExecutionList[(size_t)HIdx::SYMBOL] = state; }	\
			void OnPre##SYMBOL(CallBackFn fn) { m_OnPreFunctionCallList[(size_t)HIdx::SYMBOL] = fn; }						\
			void OnPost##SYMBOL(CallBackFn fn) { m_OnPostFunctionCallList[(size_t)HIdx::SYMBOL] = fn; }	

		ADD_HOOK_METHODS(VkCreateInstance)
		ADD_HOOK_METHODS(VkCreateDevice)
		ADD_HOOK_METHODS(VkCreateFence)
		ADD_HOOK_METHODS(VkCreateSemaphore)
		ADD_HOOK_METHODS(VkCreateEvent)
		ADD_HOOK_METHODS(VkCreateQueryPool)
		ADD_HOOK_METHODS(VkCreateBuffer)
		ADD_HOOK_METHODS(VkCreateBufferView)
		ADD_HOOK_METHODS(VkCreateImage)
		ADD_HOOK_METHODS(VkCreateImageView)
		ADD_HOOK_METHODS(VkCreateGraphicsPipelines)
		ADD_HOOK_METHODS(VkCreateFramebuffer)
		ADD_HOOK_METHODS(VkCreateDescriptorPool)
		ADD_HOOK_METHODS(VkCreateWin32SurfaceKHR)
		ADD_HOOK_METHODS(VkCreateSwapchainKHR)
		ADD_HOOK_METHODS(VkCreateRenderPass)

		ADD_HOOK_METHODS(VkAllocateCommandBuffers)
		ADD_HOOK_METHODS(VkBeginCommandBuffer)
		ADD_HOOK_METHODS(VkCmdBeginRenderPass)

		ADD_HOOK_METHODS(VkGetDeviceQueue)
		ADD_HOOK_METHODS(VkAcquireNextImageKHR)
		ADD_HOOK_METHODS(VkQueueSubmit)
		ADD_HOOK_METHODS(VkQueuePresentKHR)
		

		ADD_HOOK_METHODS(VkCmdEndRenderPass)
		ADD_HOOK_METHODS(VkEndCommandBuffer)
		ADD_HOOK_METHODS(VkFreeCommandBuffers)

		ADD_HOOK_METHODS(VkDestroyRenderPass)
		ADD_HOOK_METHODS(VkDestroySwapchainKHR)
		ADD_HOOK_METHODS(VkDestroySurfaceKHR)
		ADD_HOOK_METHODS(VkDestroyDescriptorPool)
		ADD_HOOK_METHODS(VkDestroyFramebuffer)
		ADD_HOOK_METHODS(VkDestroyPipeline)
		ADD_HOOK_METHODS(VkDestroyImageView)
		ADD_HOOK_METHODS(VkDestroyImage)
		ADD_HOOK_METHODS(VkDestroyBufferView)
		ADD_HOOK_METHODS(VkDestroyBuffer)
		ADD_HOOK_METHODS(VkDestroyQueryPool)
		ADD_HOOK_METHODS(VkDestroyEvent)
		ADD_HOOK_METHODS(VkDestroySemaphore)
		ADD_HOOK_METHODS(VkDestroyFence)
		ADD_HOOK_METHODS(VkDestroyDevice)
		ADD_HOOK_METHODS(VkDestroyInstance)

#define ADD_RESULT_LOGIC(TYPE, SYMBOL) auto& Get##SYMBOL##Result() { assert(s_ResultList[(size_t)HIdx::SYMBOL] != nullptr, "Tried to access hook result outside call!"); \
			return *(TYPE*)s_ResultList[(size_t)HIdx::SYMBOL]; }

		ADD_RESULT_LOGIC(VkResult, VkCreateInstance)
		ADD_RESULT_LOGIC(VkResult, VkCreateDevice)
		ADD_RESULT_LOGIC(VkResult, VkCreateFence)
		ADD_RESULT_LOGIC(VkResult, VkCreateSemaphore)
		ADD_RESULT_LOGIC(VkResult, VkCreateEvent)
		ADD_RESULT_LOGIC(VkResult, VkCreateQueryPool)
		ADD_RESULT_LOGIC(VkResult, VkCreateBuffer)
		ADD_RESULT_LOGIC(VkResult, VkCreateBufferView)
		ADD_RESULT_LOGIC(VkResult, VkCreateImage)
		ADD_RESULT_LOGIC(VkResult, VkCreateImageView)
		ADD_RESULT_LOGIC(VkResult, VkCreateGraphicsPipelines)
		ADD_RESULT_LOGIC(VkResult, VkCreateFramebuffer)
		ADD_RESULT_LOGIC(VkResult, VkCreateDescriptorPool)
		ADD_RESULT_LOGIC(VkResult, VkCreateWin32SurfaceKHR)
		ADD_RESULT_LOGIC(VkResult, VkCreateSwapchainKHR)
		ADD_RESULT_LOGIC(VkResult, VkCreateRenderPass)
		ADD_RESULT_LOGIC(VkResult, VkAllocateCommandBuffers)
		ADD_RESULT_LOGIC(VkResult, VkBeginCommandBuffer)
		ADD_RESULT_LOGIC(VkResult, VkAcquireNextImageKHR)
		ADD_RESULT_LOGIC(VkResult, VkQueueSubmit)
		ADD_RESULT_LOGIC(VkResult, VkQueuePresentKHR)
		ADD_RESULT_LOGIC(VkResult, VkEndCommandBuffer)

		VulkanHook& operator=(const VulkanHook& other) = delete;
		VulkanHook& operator=(VulkanHook&& other) = delete;

	protected:
		template<typename T>
		class RWrapper : public std::reference_wrapper<T> {
		public:
			RWrapper(T& val)
				: std::reference_wrapper<T>(val)
			{}

			void operator=(const T& rhs) { this->get() = rhs; }
			template<typename = std::enable_if_t<std::is_pointer_v<T>>>
			auto* operator->() { return this->get(); }

			operator T& () { return this->get(); }
			operator const T& () const { return this->get(); }
		};

		struct VkCreateInstanceParameters_t {
			RWrapper<const  VkInstanceCreateInfo*> pCreateInfo;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
			RWrapper<VkInstance*> pInstance;
		};

		struct VkCreateDeviceParameters_t {
			RWrapper<VkPhysicalDevice> physicalDevice;
			RWrapper<const  VkDeviceCreateInfo*> pCreateInfo;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
			RWrapper<VkDevice*> pDevice;
		};

		struct VkCreateFenceParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<const  VkFenceCreateInfo*> pCreateInfo;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
			RWrapper<VkFence*> pFence;
		};

		struct VkCreateSemaphoreParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<const  VkSemaphoreCreateInfo*> pCreateInfo;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
			RWrapper<VkSemaphore*> pSemaphore;
		};

		struct VkCreateEventParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<const  VkEventCreateInfo*> pCreateInfo;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
			RWrapper<VkEvent*> pEvent;
		};

		struct VkCreateQueryPoolParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<const  VkQueryPoolCreateInfo*> pCreateInfo;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
			RWrapper<VkQueryPool*> pQueryPool;
		};

		struct VkCreateBufferParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<const  VkBufferCreateInfo*> pCreateInfo;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
			RWrapper<VkBuffer*> pBuffer;
		};

		struct VkCreateBufferViewParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<const  VkBufferViewCreateInfo*> pCreateInfo;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
			RWrapper<VkBufferView*> pView;
		};

		struct VkCreateImageParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<const  VkImageCreateInfo*> pCreateInfo;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
			RWrapper<VkImage*> pImage;
		};

		struct VkCreateImageViewParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<const  VkImageViewCreateInfo*> pCreateInfo;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
			RWrapper<VkImageView*> pView;
		};

		struct VkCreateGraphicsPipelinesParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<VkPipelineCache> pipelineCache;
			RWrapper<uint32_t> createInfoCount;
			RWrapper<const  VkGraphicsPipelineCreateInfo*> pCreateInfos;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
			RWrapper<VkPipeline*> pPipelines;
		};

		struct VkCreateFramebufferParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<const  VkFramebufferCreateInfo*> pCreateInfo;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
			RWrapper<VkFramebuffer*> pFramebuffer;
		};

		struct VkCreateDescriptorPoolParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<const  VkDescriptorPoolCreateInfo*> pCreateInfo;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
			RWrapper<VkDescriptorPool*> pDescriptorPool;
		};

		struct VkCreateWin32SurfaceKHRParameters_t {
			RWrapper<VkInstance> instance;
			RWrapper<const  VkWin32SurfaceCreateInfoKHR*> pCreateInfo;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
			RWrapper<VkSurfaceKHR*> pSurface;
		};

		struct VkCreateSwapchainKHRParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<const  VkSwapchainCreateInfoKHR*> pCreateInfo;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
			RWrapper<VkSwapchainKHR*> pSwapchain;
		};

		struct VkCreateRenderPassParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<const  VkRenderPassCreateInfo*> pCreateInfo;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
			RWrapper<VkRenderPass*> pRenderPass;
		};



		struct VkBeginCommandBufferParameters_t {
			RWrapper<VkCommandBuffer> commandBuffer;
			RWrapper<const  VkCommandBufferBeginInfo*> pBeginInfo;
		};

		struct VkCmdBeginRenderPassParameters_t {
			RWrapper<VkCommandBuffer> commandBuffer;
			RWrapper<const  VkRenderPassBeginInfo*> pRenderPassBegin;
			RWrapper<VkSubpassContents> contents;
		};

		struct VkAllocateCommandBuffersParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<const  VkCommandBufferAllocateInfo*> pAllocateInfo;
			RWrapper<VkCommandBuffer*> pCommandBuffers;
		};



		struct VkGetDeviceQueueParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<uint32_t> queueFamilyIndex;
			RWrapper<uint32_t> queueIndex;
			RWrapper<VkQueue*> pQueue;
		};

		struct VkAcquireNextImageKHRParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<VkSwapchainKHR> swapchain;
			RWrapper<uint64_t> timeout;
			RWrapper<VkSemaphore> semaphore;
			RWrapper<VkFence> fence;
			RWrapper<uint32_t*> pImageIndex;
		};

		struct VkQueueSubmitParameters_t {
			RWrapper<VkQueue> queue;
			RWrapper<uint32_t> submitCount;
			RWrapper<const  VkSubmitInfo*> pSubmits;
			RWrapper<VkFence> fence;
		};

		struct VkQueuePresentKHRParameters_t {
			RWrapper<VkQueue> queue;
			RWrapper<const  VkPresentInfoKHR*> pPresentInfo;
		};



		struct VkCmdEndRenderPassParameters_t {
			RWrapper<VkCommandBuffer> commandBuffer;
		};

		struct VkEndCommandBufferParameters_t {
			RWrapper<VkCommandBuffer> commandBuffer;
		};

		struct VkFreeCommandBuffersParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<VkCommandPool> commandPool;
			RWrapper<uint32_t> commandBufferCount;
			RWrapper<const  VkCommandBuffer*> pCommandBuffers;
		};



		struct VkDestroyRenderPassParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<VkRenderPass> renderPass;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
		};

		struct VkDestroySwapchainKHRParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<VkSwapchainKHR> swapchain;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
		};

		struct VkDestroySurfaceKHRParameters_t {
			RWrapper<VkInstance> instance;
			RWrapper<VkSurfaceKHR> surface;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
		};

		struct VkDestroyDescriptorPoolParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<VkDescriptorPool> descriptorPool;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
		};

		struct VkDestroyFramebufferParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<VkFramebuffer> framebuffer;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
		};

		struct VkDestroyPipelineParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<VkPipeline> pipeline;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
		};

		struct VkDestroyImageViewParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<VkImageView> imageView;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
		};

		struct VkDestroyImageParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<VkImage> image;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
		};

		struct VkDestroyBufferViewParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<VkBufferView> bufferView;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
		};

		struct VkDestroyBufferParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<VkBuffer> buffer;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
		};

		struct VkDestroyQueryPoolParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<VkQueryPool> queryPool;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
		};

		struct VkDestroyEventParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<VkEvent> event;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
		};

		struct VkDestroySemaphoreParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<VkSemaphore> semaphore;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
		};

		struct VkDestroyFenceParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<VkFence> fence;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
		};

		struct VkDestroyDeviceParameters_t {
			RWrapper<VkDevice> device;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
		};

		struct VkDestroyInstanceParameters_t {
			RWrapper<VkInstance> instance;
			RWrapper<const  VkAllocationCallbacks*> pAllocator;
		};

		// Hook indices enum
		enum class HIdx : size_t {
			// Loader hooks
			VkGetInstanceProcAddr = 0,
			VkGetDeviceProcAddr,

			// Global command hooks
			VkCreateInstance,
			VkCreateDevice,
			VkCreateFence,
			VkCreateSemaphore,
			VkCreateEvent,
			VkCreateQueryPool,
			VkCreateBuffer,
			VkCreateBufferView,
			VkCreateImage,
			VkCreateImageView,
			VkCreateGraphicsPipelines,
			VkCreateFramebuffer,
			VkCreateDescriptorPool,
			VkCreateWin32SurfaceKHR,
			VkCreateSwapchainKHR,
			VkCreateRenderPass,

			VkAllocateCommandBuffers,
			VkBeginCommandBuffer,
			VkCmdBeginRenderPass,

			VkGetDeviceQueue,
			VkAcquireNextImageKHR,
			VkQueueSubmit,
			VkQueuePresentKHR,

			VkCmdEndRenderPass,
			VkEndCommandBuffer,
			VkFreeCommandBuffers,

			VkDestroyRenderPass,
			VkDestroySwapchainKHR,
			VkDestroySurfaceKHR,
			VkDestroyDescriptorPool,
			VkDestroyFramebuffer,
			VkDestroyPipeline,
			VkDestroyImageView,
			VkDestroyImage,
			VkDestroyBufferView,
			VkDestroyBuffer,
			VkDestroyQueryPool,
			VkDestroyEvent,
			VkDestroySemaphore,
			VkDestroyFence,
			VkDestroyDevice,
			VkDestroyInstance,

			Size,
		};

		std::recursive_mutex* m_HookMutex{ nullptr };

		inline static bool s_Hooked{ false };

		// Active instance & device lists
		inline static std::vector<VkInstance> s_ActiveInstances{};
		inline static std::vector<VkDevice> s_ActiveDevices{};

		// ICD Command hook maps
		inline static VkDeviceCommandsMap s_DeviceCommandMap{};
		inline static VkInstanceCommandsMap s_InstanceCommandMap{};

		// Hooks
		inline static std::array<std::unique_ptr<SmartFunctionHook>, (size_t)HIdx::Size> s_HookList;
		inline static std::array<bool, (size_t)HIdx::Size> s_DetourExecutionList{};
		inline static std::array<void*, (size_t)HIdx::Size> s_ParamList{}, s_ResultList{};
		std::array<SmartFunctionHook*, (size_t)HIdx::Size> m_ActiveHookList{};

		// Callbacks to actually do work when the hooked functions get called.
		std::array<CallBackFn, (size_t)HIdx::Size> m_OnPreFunctionCallList{ nullptr }, m_OnPostFunctionCallList{ nullptr };

	// Detour functions
	protected:
		// Loader exports
		static VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL VkGetInstanceProcAddr(VkInstance instance, const char* pName);
		static VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL VkGetDeviceProcAddr(VkDevice device, const char* pName);

		// Global commands
		static VKAPI_ATTR VkResult VKAPI_CALL VkCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance);
		static VKAPI_ATTR VkResult VKAPI_CALL VkCreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDevice* pDevice);
		static VKAPI_ATTR VkResult VKAPI_CALL VkCreateFence(VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence);
		static VKAPI_ATTR VkResult VKAPI_CALL VkCreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore);
		static VKAPI_ATTR VkResult VKAPI_CALL VkCreateEvent(VkDevice device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent);
		static VKAPI_ATTR VkResult VKAPI_CALL VkCreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool);
		static VKAPI_ATTR VkResult VKAPI_CALL VkCreateBuffer(VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer);
		static VKAPI_ATTR VkResult VKAPI_CALL VkCreateBufferView(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView);
		static VKAPI_ATTR VkResult VKAPI_CALL VkCreateImage(VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage);
		static VKAPI_ATTR VkResult VKAPI_CALL VkCreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView);
		static VKAPI_ATTR VkResult VKAPI_CALL VkCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
		static VKAPI_ATTR VkResult VKAPI_CALL VkCreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer);
		static VKAPI_ATTR VkResult VKAPI_CALL VkCreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool);
		static VKAPI_ATTR VkResult VKAPI_CALL VkCreateWin32SurfaceKHR(VkInstance instance, const VkWin32SurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
		static VKAPI_ATTR VkResult VKAPI_CALL VkCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain);
		static VKAPI_ATTR VkResult VKAPI_CALL VkCreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);
		
		static VKAPI_ATTR VkResult VKAPI_CALL VkAllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers);
		static VKAPI_ATTR VkResult VKAPI_CALL VkBeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo);
		static VKAPI_ATTR void VKAPI_CALL VkCmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents);
		
		static VKAPI_ATTR void VKAPI_CALL VkGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue);
		static VKAPI_ATTR VkResult VKAPI_CALL VkAcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex);
		static VKAPI_ATTR VkResult VKAPI_CALL VkQueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence);
		static VKAPI_ATTR VkResult VKAPI_CALL VkQueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo);

		static VKAPI_ATTR void VKAPI_CALL VkCmdEndRenderPass(VkCommandBuffer commandBuffer);
		static VKAPI_ATTR VkResult VKAPI_CALL VkEndCommandBuffer(VkCommandBuffer commandBuffer);
		static VKAPI_ATTR void VKAPI_CALL VkFreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers);

		static VKAPI_ATTR void VKAPI_CALL VkDestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator);
		static VKAPI_ATTR void VKAPI_CALL VkDestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator);
		static VKAPI_ATTR void VKAPI_CALL VkDestroySurfaceKHR(VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator);
		static VKAPI_ATTR void VKAPI_CALL VkDestroyDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator);
		static VKAPI_ATTR void VKAPI_CALL VkDestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator);
		static VKAPI_ATTR void VKAPI_CALL VkDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator);
		static VKAPI_ATTR void VKAPI_CALL VkDestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator);
		static VKAPI_ATTR void VKAPI_CALL VkDestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator);
		static VKAPI_ATTR void VKAPI_CALL VkDestroyBufferView(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator);
		static VKAPI_ATTR void VKAPI_CALL VkDestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator);
		static VKAPI_ATTR void VKAPI_CALL VkDestroyQueryPool(VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator);
		static VKAPI_ATTR void VKAPI_CALL VkDestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator);
		static VKAPI_ATTR void VKAPI_CALL VkDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator);
		static VKAPI_ATTR void VKAPI_CALL VkDestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator);
		static VKAPI_ATTR void VKAPI_CALL VkDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator);
		static VKAPI_ATTR void VKAPI_CALL VkDestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator);
	};

}