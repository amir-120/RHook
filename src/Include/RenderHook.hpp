#pragma once

#ifndef EXCLUDE_RHOOK_D3D9
#include "../hooks/D3D9Hook.hpp"
#endif

#ifndef EXCLUDE_RHOOK_D3D10
#include "../hooks/D3D10Hook.hpp"
#endif

#ifndef EXCLUDE_RHOOK_D3D11
#include "../hooks/D3D11Hook.hpp"
#endif

#ifndef EXCLUDE_RHOOK_D3D12
#include "../hooks/D3D12Hook.hpp"
#endif

#ifndef EXCLUDE_RHOOK_OGL
#include "../hooks/OpenGLHook.hpp"
#endif

#ifndef EXCLUDE_RHOOK_VULKAN
#include "../hooks/VulkanHook.hpp"
#endif

#ifndef EXCLUDE_RHOOK_PRESENTHOOK
#include "../hooks/PresentHook.hpp"
#endif

#ifndef EXCLUDE_RHOOK_WINMSGHOOK
#include "../hooks/WindowsMessageHook.hpp"
#endif

#ifndef EXCLUDE_RHOOK_UTILITY
#include "../utility/Address.hpp"
#include "../utility/FunctionHook.hpp"
#include "../utility/Module.hpp"
#include "../utility/PointerHook.hpp"
#include "../utility/VtableHook.hpp"
#endif

namespace RHook {
	// Check if the current process is a helper process, this is needed for dlls for MS Detours to work. \
	Should return TRUE inside DLLMain() before the rest of the code if the call return true
	bool IsHelperProcess();

	// Initialize the RenderHooks library
	void Init();
}