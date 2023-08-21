#include <stdexcept>

#include <windows.h>
#include <log/Logging.hpp>

#include <RHook/utility/ProtectionOverride.hpp>
#include <RHook/utility/PointerHook.hpp>

namespace RHook {
    PointerHook::PointerHook(void** oldPtr, void* newPtr)
        : m_ReplacePtr{ oldPtr },
        m_Destination{ newPtr }
    {
        if (oldPtr == nullptr) {
            RHOOK_ERROR("[POINTER HOOK] oldPtr is nullptr");
            throw std::invalid_argument("oldPtr cannot be nullptr");
        }

        if (IsBadReadPtr(oldPtr, sizeof(void*))) {
            RHOOK_ERROR("[POINTER HOOK] oldPtr is not readable");
            throw std::invalid_argument("oldPtr is not readable");
        }

        ProtectionOverride overrider{ oldPtr, sizeof(void*), PAGE_EXECUTE_READWRITE };

        RHOOK_INFO("[POINTER HOOK] Hooking {:x}->{:x} to {:x}!", (uintptr_t)oldPtr, (uintptr_t)*oldPtr, (uintptr_t)newPtr);

        m_Original = *oldPtr;
        *oldPtr = newPtr;
    }

    PointerHook::~PointerHook() {
        Remove();
    }

    bool PointerHook::Remove() {
        if (m_ReplacePtr != nullptr && !IsBadReadPtr(m_ReplacePtr, sizeof(void*)) && *m_ReplacePtr == m_Destination) {
            try {
                ProtectionOverride overrider{ m_ReplacePtr, sizeof(void*), PAGE_EXECUTE_READWRITE };
                *m_ReplacePtr = m_Original;
            }
            catch (std::exception& e) {
                RHOOK_ERROR("[POINTER HOOK] Exception Thrown: {}", e.what());
                return false;
            }
        }

        return true;
    }

    bool PointerHook::Restore() {
        if (m_ReplacePtr != nullptr && !IsBadReadPtr(m_ReplacePtr, sizeof(void*)) && *m_ReplacePtr != m_Destination) {
            try {
                ProtectionOverride overrider{ m_ReplacePtr, sizeof(void*), PAGE_EXECUTE_READWRITE };
                *m_ReplacePtr = m_Destination;
            }
            catch (std::exception& e) {
                RHOOK_ERROR("[POINTER HOOK] Exception Thrown: {}", e.what());
                return false;
            }
        }

        return true;
    }
}
