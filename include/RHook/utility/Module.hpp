#pragma once

#include <stdint.h>
#include <optional>
#include "./Address.hpp"

namespace RHook {
	IMAGE_DOS_HEADER* GetAppModuleHandle();
	void* GetModuleEntryPoint(PIMAGE_DOS_HEADER dosHeader);

	std::optional<HMODULE> GetModuleWithin(Address address);
	std::optional<uintptr_t> GetDLLImageBase(Address dll);
	std::optional<uintptr_t> GetImagebaseVAFromPtr(Address dll, Address base, void* ptr);
	std::optional<std::string> GetModulePath(HMODULE module);
	std::optional<std::wstring> GetModulePathW(HMODULE module);
	std::optional<std::string> GetModuleDirectory(HMODULE module);
	std::optional<std::wstring> GetModuleDirectoryW(HMODULE module);

	HMODULE LoadModuleFromCurrentDirectory(const std::wstring& module);
	std::vector<uint8_t> ReadModuleFromDisk(HMODULE module);
	std::optional<std::vector<uint8_t>> GetOriginalBytes(HMODULE module, Address address);
	HMODULE GetExecutable();
	std::optional<uintptr_t> PtrFromRva(uint8_t* dll, uintptr_t rva);
}