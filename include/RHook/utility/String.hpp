#pragma once

#include <string>
#include <string_view>

namespace RHook {
    //
    // String utilities.
    //

    // Conversion functions for UTF8<->UTF16.
    std::string Narrow(std::wstring_view std);
    std::wstring Widen(std::string_view std);

    std::string FormatString(const char* format, va_list args);
    
    // FNV-1a
    static constexpr auto Hash(std::string_view data) {
        size_t result = 0xcbf29ce484222325;

        for (char c : data) {
            result ^= c;
            result *= (size_t)1099511628211;
        }

        return result;
    }
}

consteval auto operator "" _fnv(const char* s, size_t) {
    return RHook::Hash(s);
}
