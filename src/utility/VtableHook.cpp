#include <RHook/utility/VtableHook.hpp>

namespace RHook {
    VtableHook::VtableHook()
        : m_rawData{},
        m_VtablePtr(),
        m_NewVTable(nullptr),
        m_OldVTable(),
        m_VtableSize(0)
    {}

    VtableHook::VtableHook(Address target)
        : VtableHook()
    {
        Create(target);
    }

    VtableHook::VtableHook(VtableHook&& other)
        : m_rawData(move(other.m_rawData)),
        m_VtablePtr(other.m_VtablePtr),
        m_NewVTable(other.m_NewVTable),
        m_OldVTable(other.m_OldVTable),
        m_VtableSize(other.m_VtableSize)
    {
        other.m_VtablePtr = nullptr;
        other.m_NewVTable = nullptr;
        other.m_OldVTable = nullptr;
        other.m_VtableSize = 0;
    }

    VtableHook::~VtableHook() {
        Remove();
    }

    bool VtableHook::Create(Address target) {
        if (!m_rawData.empty()) {
            Remove();
            m_rawData.clear();
        }

        m_VtablePtr = target;
        m_OldVTable = m_VtablePtr.To<Address>();
        m_VtableSize = GetVTableSize(m_OldVTable);
        // RTTI.
        m_rawData.resize(m_VtableSize + 1);
        m_NewVTable = m_rawData.data() + 1;

        memcpy(m_rawData.data(), m_OldVTable.As<Address*>() - 1, sizeof(Address) * (m_VtableSize + 1));

        // At this point we have the address of the old vtable, and a copy of it
        // stored in m_new_vtable.  Set the target objects vtable
        // pointer to our copy of the original.
        *m_VtablePtr.As<Address*>() = m_NewVTable;

        return true;
    }

    bool VtableHook::Recreate() {
        if (m_VtablePtr != nullptr) {
            *m_VtablePtr.As<Address*>() = m_NewVTable;
            return true;
        }

        return false;
    }

    bool VtableHook::Remove() {
        // Can cause issues where we set the vtable/random memory of some other pointer.
        if (m_VtablePtr != nullptr && IsBadReadPtr(m_VtablePtr.Ptr(), sizeof(void*)) == FALSE && m_VtablePtr.To<void*>() == m_NewVTable) {
            *m_VtablePtr.As<Address*>() = m_OldVTable;
            return true;
        }

        return false;
    }

    bool VtableHook::HookMethod(uint32_t index, Address newMethod) {
        if (m_OldVTable != nullptr && m_NewVTable != nullptr && index < m_VtableSize) {
            m_NewVTable[index] = newMethod;
            return true;
        }

        return false;
    }

    size_t VtableHook::GetVTableSize(Address vtable) {
        size_t i = 0;

        for (; vtable.As<Address*>()[i] != nullptr; ++i) {
            if (IsBadCodePtr(vtable.As<FARPROC*>()[i]) == TRUE) {
                break;
            }
        }

        return i;
    }
}
