#include <stdexcept>

#include <windows.h>
#include "Log/Logging.hpp"

#include "PointerHook.hpp"

namespace RHook {
    PointerHook::PointerHook(void** oldPtr, void* newPtr)
        : m_replacePtr{ oldPtr },
        m_destination{ newPtr }
    {
        if (oldPtr == nullptr) {
            RH_RHOOK_ERROR("[POINTER HOOK] old_ptr is nullptr");
            throw std::invalid_argument("old_ptr cannot be nullptr");
        }

        if (IsBadReadPtr(oldPtr, sizeof(void*))) {
            spdlog::error("[POINTER HOOK] old_ptr is not readable");
            throw std::invalid_argument("old_ptr is not readable");
        }

        ProtectionOverride overrider{ oldPtr, sizeof(void*), PAGE_EXECUTE_READWRITE };

        RH_RHOOK_INFO("[PointerHook] Hooking {:x}->{:x} to {:x}!", (uintptr_t)oldPtr, (uintptr_t)*oldPtr, (uintptr_t)newPtr);

        m_original = *oldPtr;
        *oldPtr = newPtr;
    }

    PointerHook::~PointerHook() {
        Remove();
    }

    bool PointerHook::Remove() {
        if (m_replacePtr != nullptr && !IsBadReadPtr(m_replacePtr, sizeof(void*)) && *m_replacePtr == m_destination) {
            try {
                ProtectionOverride overrider{ m_replacePtr, sizeof(void*), PAGE_EXECUTE_READWRITE };
                *m_replacePtr = m_original;
            }
            catch (std::exception& e) {
                RH_RHOOK_ERROR("[POINTER HOOK] Exception Thrown: {}", e.what());
                return false;
            }
        }

        return true;
    }

    bool PointerHook::Restore() {
        if (m_replacePtr != nullptr && !IsBadReadPtr(m_replacePtr, sizeof(void*)) && *m_replacePtr != m_destination) {
            try {
                ProtectionOverride overrider{ m_replacePtr, sizeof(void*), PAGE_EXECUTE_READWRITE };
                *m_replacePtr = m_destination;
            }
            catch (std::exception& e) {
                RH_RHOOK_ERROR("[POINTER HOOK] Exception Thrown: {}", e.what());
                return false;
            }
        }

        return true;
    }

    ProtectionOverride::ProtectionOverride(void* address, size_t size, uint32_t protection)
        : m_address{ address },
        m_size{ size }
    {
        if (!VirtualProtect(address, size, protection, (DWORD*)&m_old)) {
            RH_RHOOK_ERROR("[POINTER HOOK] VirtualProtect failed. Address: {:p}", address);
            throw std::runtime_error("VirtualProtect failed");
        }
    }

    ProtectionOverride::~ProtectionOverride() {
        VirtualProtect(m_address, m_size, m_old, (DWORD*)&m_old);
    }
}
