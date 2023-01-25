#pragma once

#include <string>
#include <cstdint>

// sizeof(Address) should always be sizeof(void*).
class Address {
public:
    Address();
    Address(void* ptr);
    Address(uintptr_t addr);

    void Set(void* ptr) {
        m_ptr = ptr;
    }

    template <typename T>
    Address Get(T offset) const {
        return Address((uintptr_t)m_ptr + offset);
    }

    template <typename T>
    Address Add(T offset) const {
        return Address((uintptr_t)m_ptr + offset);
    }

    template <typename T>
    Address Sub(T offset) const {
        return Address((uintptr_t)m_ptr - offset);
    }

    template <typename T>
    T As() const {
        return (T)m_ptr;
    }

    // To is like As but dereferences that shit.
    template <typename T>
    T To() const {
        return *(T*)m_ptr;
    }

    Address Deref() const {
        return To<void*>();
    }

    void* Ptr() const {
        return m_ptr;
    }

    operator uintptr_t() const {
        return (uintptr_t)m_ptr;
    }

    operator void*() const {
        return m_ptr;
    }

    bool operator ==(bool val) {
        return ((m_ptr && val) || (!m_ptr && !val));
    }

    bool operator !=(bool val) {
        return !(*this == val);
    }

    bool operator ==(uintptr_t val) {
        return ((uintptr_t)m_ptr == val);
    }

    bool operator !=(uintptr_t val) {
        return !(*this == val);
    }

    bool operator ==(void* val) {
        return (m_ptr == val);
    }

    bool operator !=(void* val) {
        return !(*this == val);
    }

private:
    void* m_ptr;
};

typedef Address Offset;
