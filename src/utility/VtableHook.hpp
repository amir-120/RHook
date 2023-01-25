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
            return m_vtablePtr;
        }

        // Access to original methods.
        Address GetMethod(uint32_t index) {
            if (index < m_vtableSize && m_oldVTable && m_newVTable) {
                return m_oldVTable.As<Address*>()[index];
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
        Address m_vtablePtr;
        Address* m_newVTable;
        Address m_oldVTable;
        size_t m_vtableSize;

        size_t get_vtable_size(Address vtable);
    };
}
