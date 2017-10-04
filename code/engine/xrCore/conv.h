#pragma once

XRCORE_API double xrParseDouble(const std::string_view str);
XRCORE_API float xrParseFloat(const std::string_view str);

XRCORE_API std::uint8_t xrParseUint8(const std::string_view str);
XRCORE_API std::uint16_t xrParseUint16(const std::string_view str);
XRCORE_API std::uint32_t xrParseUint32(const std::string_view str);
XRCORE_API std::uint64_t xrParseUint64(const std::string_view str);

XRCORE_API std::int8_t xrParseInt8(const std::string_view str);
XRCORE_API std::int16_t xrParseInt16(const std::string_view str);
XRCORE_API std::int32_t xrParseInt32(const std::string_view str);
XRCORE_API std::int64_t xrParseInt64(const std::string_view str);

template <typename T>
T xrParse(const std::string_view str) {
    if constexpr (std::is_same_v<T, double>) {
        return xrParseDouble(str);
    } else if constexpr (std::is_same_v<T, float>) {
        return xrParseFloat(str);
    } else if constexpr (std::is_same_v<T, std::uint8_t>) {
        return xrParseUint8(str);
    } else if constexpr (std::is_same_v<T, std::uint16_t>) {
        return xrParseUint16(str);
    } else if constexpr (std::is_same_v<T, std::uint32_t>) {
        return xrParseUint32(str);
    } else if constexpr (std::is_same_v<T, std::uint64_t>) {
        return xrParseUint64(str);
    } else if constexpr (std::is_same_v<T, std::int8_t>) {
        return xrParseInt8(str);
    } else if constexpr (std::is_same_v<T, std::int16_t>) {
        return xrParseInt16(str);
    } else if constexpr (std::is_same_v<T, std::int32_t>) {
        return xrParseInt32(str);
    } else if constexpr (std::is_same_v<T, std::int64_t>) {
        return xrParseInt64(str);
    } else {
        static_assert(false, "Type is unsupported");
        return std::declval<T>();
    }
}
