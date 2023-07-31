#include <fstream>
#include <filesystem>

#include <shlwapi.h>
#include <windows.h>
#include <winternl.h>

#include "String.hpp"
#include "Module.hpp"

namespace RHook {
	IMAGE_DOS_HEADER* GetAppModuleHandle() {
#if defined _M_AMD64
		auto peb = (void*)__readgsqword(0x60);
		auto loaderData = *(void**)((uintptr_t)peb + 0x18);
		auto ldrTableEntry = *(void**)((uintptr_t)loaderData + 0x10);
		return *(IMAGE_DOS_HEADER**)((uintptr_t)ldrTableEntry + 0x30);
#elif defined _M_IX86
		auto peb = (void*)__readfsdword(0x30);
		auto loaderData = *(void**)((uintptr_t)peb + 0x0c);
		auto ldrTableEntry = *(void**)((uintptr_t)loaderData + 0x0c);
		return *(IMAGE_DOS_HEADER**)((uintptr_t)ldrTableEntry + 0x18);
#endif  
	}

	void* GetModuleEntryPoint(PIMAGE_DOS_HEADER pidh)
	{
		const auto pinh = (PIMAGE_NT_HEADERS)((uintptr_t)pidh + pidh->e_lfanew);
		const auto pioh = (PIMAGE_OPTIONAL_HEADER)&pinh->OptionalHeader;

		return (void*)(pioh->ImageBase + pioh->AddressOfEntryPoint);
	}


	std::optional<HMODULE> GetModuleWithin(Address address) {
		HMODULE module = nullptr;
		if (GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, address.As<LPCSTR>(), &module)) {
			return module;
		}

		return {};
	}

	std::optional<uintptr_t> GetDLLImageBase(Address dll) {
		if (dll == nullptr) {
			return {};
		}

		// Get the dos header and verify that it seems valid.
		auto dosHeader = dll.As<PIMAGE_DOS_HEADER>();

		if (dosHeader->e_magic != IMAGE_DOS_SIGNATURE) {
			return {};
		}

		// Get the nt headers and verify that they seem valid.
		auto ntHeaders = (PIMAGE_NT_HEADERS)((uintptr_t)dosHeader + dosHeader->e_lfanew);

		if (ntHeaders->Signature != IMAGE_NT_SIGNATURE) {
			return {};
		}

		return ntHeaders->OptionalHeader.ImageBase;
	}

	std::optional<uintptr_t> GetImagebaseVAFromPtr(Address dll, Address base, void* ptr) {
		auto fileImagebase = GetDLLImageBase(dll);

		if (!fileImagebase) {
			return {};
		}

		return *fileImagebase + ((uintptr_t)ptr - base.As<uintptr_t>());
	}


	std::optional<std::string> GetModulePath(HMODULE module) {
		wchar_t filename[MAX_PATH]{ 0 };
		if (GetModuleFileNameW(module, filename, MAX_PATH) >= MAX_PATH) {
			return {};
		}

		return RHook::Narrow(filename);
	}

	std::optional<std::wstring> GetModulePathW(HMODULE module) {
		wchar_t filename[MAX_PATH]{ 0 };
		if (GetModuleFileNameW(module, filename, MAX_PATH) >= MAX_PATH) {
			return {};
		}

		return filename;
	}

	std::optional<std::string> GetModuleDirectory(HMODULE module) {
		wchar_t filename[MAX_PATH]{ 0 };
		if (GetModuleFileNameW(module, filename, MAX_PATH) >= MAX_PATH) {
			return {};
		}

		PathRemoveFileSpecW(filename);

		return RHook::Narrow(filename);
	}

	std::optional<std::wstring> GetModuleDirectoryW(HMODULE module) {
		wchar_t filename[MAX_PATH]{ 0 };
		if (GetModuleFileNameW(module, filename, MAX_PATH) >= MAX_PATH) {
			return {};
		}

		PathRemoveFileSpecW(filename);

		return filename;
	}

	HMODULE LoadModuleFromCurrentDirectory(const std::wstring& module) {
		const auto currentPath = GetModuleDirectoryW(GetExecutable());

		if (!currentPath) {
			return nullptr;
		}

		auto fspath = std::filesystem::path{ *currentPath } / module;

		return LoadLibraryW(fspath.c_str());
	}

	std::vector<uint8_t> ReadModuleFromDisk(HMODULE module) {
		auto path = GetModulePath(module);

		if (!path) {
			return {};
		}

		// read using std utilities like ifstream and tellg, etc.
		auto file = std::ifstream{ path->c_str(), std::ios::binary | std::ios::ate };

		if (!file.is_open()) {
			return {};
		}

		auto size = file.tellg();
		file.seekg(0, std::ios::beg);

		// don't brace initialize std::vector because it won't
		// call the right constructor.
		auto data = std::vector<uint8_t>((size_t)size);
		file.read((char*)data.data(), size);

		return data;
	}

	std::optional<std::vector<uint8_t>> GetOriginalBytes(Address address) {
		auto moduleWithin = GetModuleWithin(address);

		if (!moduleWithin) {
			return {};
		}

		return GetOriginalBytes(*moduleWithin, address);
	}

	std::optional<std::vector<uint8_t>> GetOriginalBytes(HMODULE module, Address address) {
		auto diskData = ReadModuleFromDisk(module);

		if (diskData.empty()) {
			return std::nullopt;
		}

		auto moduleBase = GetDLLImageBase(module);

		if (!moduleBase) {
			return std::nullopt;
		}

		auto moduleRVA = address.As<uintptr_t>() - *moduleBase;

		// obtain the file offset of the address now
		auto diskPtr = PtrFromRva(diskData.data(), moduleRVA);

		if (!diskPtr) {
			return std::nullopt;
		}

		auto originalBytes = std::vector<uint8_t>{};

		auto moduleBytes = address.As<uint8_t*>();
		auto diskBytes = (uint8_t*)*diskPtr;

		// copy the bytes from the disk data to the original bytes
		// copy only until the bytes start to match eachother
		for (auto i = 0; ; ++i) {
			if (moduleBytes[i] == diskBytes[i]) {
				bool actuallyMatches = true;

				// Lookahead 4 bytes to check if any other part is different before breaking out.
				for (auto j = 1; j <= 4; ++j) {
					if (moduleBytes[i + j] != diskBytes[i + j]) {
						actuallyMatches = false;
						break;
					}
				}

				if (actuallyMatches) {
					break;
				}
			}

			originalBytes.push_back(diskBytes[i]);
		}

		if (originalBytes.empty()) {
			return std::nullopt;
		}

		return originalBytes;
	}

	HMODULE GetExecutable() {
		return GetModuleHandle(nullptr);
	}

	std::optional<uintptr_t> PtrFromRva(uint8_t* dll, uintptr_t rva) {
		// Get the first section.
		auto dosHeader = (PIMAGE_DOS_HEADER)&dll[0];
		auto ntHeaders = (PIMAGE_NT_HEADERS)&dll[dosHeader->e_lfanew];
		auto section = IMAGE_FIRST_SECTION(ntHeaders);

		// Go through each section searching for where the rva lands.
		for (uint16_t i = 0; i < ntHeaders->FileHeader.NumberOfSections; ++i, ++section) {
			auto size = section->Misc.VirtualSize;

			if (size == 0) {
				size = section->SizeOfRawData;
			}

			if (rva >= section->VirtualAddress && rva < ((uintptr_t)section->VirtualAddress + size)) {
				auto delta = section->VirtualAddress - section->PointerToRawData;

				return (uintptr_t)(dll + (rva - delta));
			}
		}

		return {};
	}
}