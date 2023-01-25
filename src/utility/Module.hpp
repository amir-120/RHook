#pragma once

#include <Windows.h>
#include <stdint.h>

namespace RHook {
	IMAGE_DOS_HEADER* GetAppModuleHandle();
	void* GetModuleEntryPoint(PIMAGE_DOS_HEADER dosHeader);
}