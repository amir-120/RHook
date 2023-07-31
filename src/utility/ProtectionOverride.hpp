#pragma once
#include <stdint.h>

namespace RHook {
    struct ProtectionOverride {
        ProtectionOverride(void* address, size_t size, uint32_t protection);
        virtual ~ProtectionOverride();

        void* m_Address{};
        size_t m_Size{};
        uint32_t m_Old{};
    };
}
