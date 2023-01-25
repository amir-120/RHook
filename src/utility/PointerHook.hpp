#pragma once

namespace RHook {
    struct ProtectionOverride {
        ProtectionOverride(void* address, size_t size, uint32_t protection);
        virtual ~ProtectionOverride();

        void* m_address{};
        size_t m_size{};
        uint32_t m_old{};
    };

    // A class to replace a pointer with a new pointer.
    class PointerHook {
    public:
        PointerHook(void** old_ptr, void* new_ptr);
        virtual ~PointerHook();

        bool Remove();
        bool Restore();

        template<typename T>
        T GetOriginal() const {
            return (T)m_original;
        }

    private:
        void** m_replacePtr{};
        void* m_original{};
        void* m_destination{};
    };
}
