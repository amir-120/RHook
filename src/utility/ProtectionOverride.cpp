#include <stdexcept>

#include <windows.h>
#include "Log/Logging.hpp"

#include "ProtectionOverride.hpp"

namespace RHook {
    ProtectionOverride::ProtectionOverride(void* address, size_t size, uint32_t protection)
        : m_Address{ address },
        m_Size{ size }
    {
        if (!VirtualProtect(address, size, protection, (DWORD*)&m_Old)) {
            RH_RHOOK_ERROR("[POINTER HOOK] VirtualProtect failed. Address: {:p}", address);
            throw std::runtime_error("VirtualProtect failed");
        }
    }

    ProtectionOverride::~ProtectionOverride() {
        VirtualProtect(m_Address, m_Size, m_Old, (DWORD*)&m_Old);
    }
}
