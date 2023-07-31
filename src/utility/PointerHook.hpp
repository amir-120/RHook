#pragma once

namespace RHook {
    // A class to replace a pointer with a new pointer.
    class PointerHook {
    public:
        PointerHook(void** oldPtr, void* newPtr);
        virtual ~PointerHook();

        bool Remove();
        bool Restore();

        template<typename T>
        T GetOriginal() const {
            return (T)m_Original;
        }

    private:
        void** m_ReplacePtr{};
        void* m_Original{};
        void* m_Destination{};
    };
}
