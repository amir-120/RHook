#include "Include/RenderHook.hpp"
#include "Log/Logging.hpp"
#include <detours.h>

namespace RHook {
	bool g_IsMSDetoursInitilized{ false };
	
	BOOL IsHelperProcess() {
		return DetourIsHelperProcess();
	}
}