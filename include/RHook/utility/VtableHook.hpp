#pragma once

#include <cstdint>
#include <vector>

#include <Windows.h>

#include "./Address.hpp"

namespace RHook {
    class VtableHook {
    public:
        VtableHook();
        VtableHook(Address target);
        VtableHook(const VtableHook& other) = delete;
        VtableHook(VtableHook&& other);

        virtual ~VtableHook();

        bool Create(Address target);
        bool Recreate();
        bool Remove();

        bool HookMethod(uint32_t index, Address newMethod);

        auto GetInstance() {
            return m_VtablePtr;
        }

        // Access to original methods.
        Address GetMethod(uint32_t index) {
            if (index < m_VtableSize && m_OldVTable && m_NewVTable) {
                return m_OldVTable.As<Address*>()[index];
            }
            else {
                return nullptr;
            }
        }

        template <typename T>
        T GetMethod(uint32_t index) {
            return (T)GetMethod(index).Ptr();
        }

    private:
        std::vector<Address> m_rawData;
        Address m_VtablePtr;
        Address* m_NewVTable;
        Address m_OldVTable;
        size_t m_VtableSize;

        size_t GetVTableSize(Address vtable);
    };
}
