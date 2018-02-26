#pragma once

namespace imdex::mem_units {

constexpr size_t operator"" _KB(const size_t value) noexcept {
    return value * 1024;
}

constexpr size_t operator"" _MB(const size_t value) noexcept {
    return value * 1024 * 1024;
}

constexpr size_t operator"" _GB(const size_t value) noexcept {
    return value * 1024 * 1024 * 1024;
}

} // imdex::mem_units namespace
