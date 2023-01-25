#include "VtableHook.hpp"

namespace RHook {
    VtableHook::VtableHook()
        : m_rawData{},
        m_vtablePtr(),
        m_newVTable(nullptr),
        m_oldVTable(),
        m_vtableSize(0)
    {}

    VtableHook::VtableHook(Address target)
        : VtableHook()
    {
        Create(target);
    }

    VtableHook::VtableHook(VtableHook&& other)
        : m_rawData(move(other.m_rawData)),
        m_vtablePtr(other.m_vtablePtr),
        m_newVTable(other.m_newVTable),
        m_oldVTable(other.m_oldVTable),
        m_vtableSize(other.m_vtableSize)
    {
        other.m_vtablePtr = nullptr;
        other.m_newVTable = nullptr;
        other.m_oldVTable = nullptr;
        other.m_vtableSize = 0;
    }

    VtableHook::~VtableHook() {
        Remove();
    }

    bool VtableHook::Create(Address target) {
        if (!m_rawData.empty()) {
            Remove();
            m_rawData.clear();
        }

        m_vtablePtr = target;
        m_oldVTable = m_vtablePtr.To<Address>();
        m_vtableSize = get_vtable_size(m_oldVTable);
        // RTTI.
        m_rawData.resize(m_vtableSize + 1);
        m_newVTable = m_rawData.data() + 1;

        memcpy(m_rawData.data(), m_oldVTable.As<Address*>() - 1, sizeof(Address) * (m_vtableSize + 1));

        // At this point we have the address of the old vtable, and a copy of it
        // stored in m_new_vtable.  Set the target objects vtable
        // pointer to our copy of the original.
        *m_vtablePtr.As<Address*>() = m_newVTable;

        return true;
    }

    bool VtableHook::Recreate() {
        if (m_vtablePtr != nullptr) {
            *m_vtablePtr.As<Address*>() = m_newVTable;
            return true;
        }

        return false;
    }

    bool VtableHook::Remove() {
        // Can cause issues where we set the vtable/random memory of some other pointer.
        if (m_vtablePtr != nullptr && IsBadReadPtr(m_vtablePtr.Ptr(), sizeof(void*)) == FALSE && m_vtablePtr.To<void*>() == m_newVTable) {
            *m_vtablePtr.As<Address*>() = m_oldVTable;
            return true;
        }

        return false;
    }

    bool VtableHook::HookMethod(uint32_t index, Address newMethod) {
        if (m_oldVTable != nullptr && m_newVTable != nullptr && index < m_vtableSize) {
            m_newVTable[index] = newMethod;
            return true;
        }

        return false;
    }

    size_t VtableHook::get_vtable_size(Address vtable) {
        size_t i = 0;

        for (; vtable.As<Address*>()[i] != nullptr; ++i) {
            if (IsBadCodePtr(vtable.As<FARPROC*>()[i]) == TRUE) {
                break;
            }
        }

        return i;
    }
}
