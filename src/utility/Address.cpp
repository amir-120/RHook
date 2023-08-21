#include <cstdio>

#include <RHook/utility/Address.hpp>

namespace RHook {
    Address::Address()
        : m_Ptr(nullptr)
    {}

    Address::Address(void* ptr)
        : m_Ptr(ptr)
    {}

    Address::Address(uintptr_t addr)
        : m_Ptr((void*)addr)
    {}
}