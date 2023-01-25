#include "Include/RenderHook.hpp"
#include "Log/Logging.hpp"
#include <detours.h>

namespace RHook {
	bool IsHelperProcess() {
		return DetourIsHelperProcess();
	}

	void Init() {
		RHook::Log::Init();
		DetourRestoreAfterWith();
	}
}