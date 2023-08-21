#include <RHook/RenderHook.hpp>
#include <Log/Logging.hpp>
#include <detours.h>

bool g_IsMSDetoursInitialized{ false };

namespace RHook {
	BOOL IsHelperProcess() {
		return DetourIsHelperProcess();
	}
}