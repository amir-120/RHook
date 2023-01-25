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

}