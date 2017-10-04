#include "stdafx.h"
#include "conv.h"

namespace x3 = boost::spirit::x3;

template <typename T, typename Parser>
T parse(const std::string_view str, const Parser& parser, const T defaultValue) {
    T result = defaultValue;
    x3::phrase_parse(str.begin(), str.end(), parser, x3::ascii::space, result);
    return result;
}

XRCORE_API double xrParseDouble(const std::string_view str) {
    return parse(str, x3::double_, 0.0);
}

XRCORE_API float xrParseFloat(const std::string_view str) {
    return parse(str, x3::float_, 0.0f);
}

XRCORE_API std::uint8_t xrParseUint8(const std::string_view str) {
    return parse(str, x3::uint8, std::uint8_t(0));
}

XRCORE_API std::uint16_t xrParseUint16(const std::string_view str) {
    return parse(str, x3::uint16, std::uint16_t(0));
}

XRCORE_API std::uint32_t xrParseUint32(const std::string_view str) {
    return parse(str, x3::uint32, std::uint32_t(0));
}

XRCORE_API std::uint64_t xrParseUint64(const std::string_view str) {
    return parse(str, x3::uint64, std::uint64_t(0));
}

XRCORE_API std::int8_t xrParseInt8(const std::string_view str) {
    return parse(str, x3::int8, std::int8_t(0));
}

XRCORE_API std::int16_t xrParseInt16(const std::string_view str) {
    return parse(str, x3::int16, std::int16_t(0));
}

XRCORE_API std::int32_t xrParseInt32(const std::string_view str) {
    return parse(str, x3::int32, std::int32_t(0));
}

XRCORE_API std::int64_t xrParseInt64(const std::string_view str) {
    return parse(str, x3::int64, std::int64_t(0));
}
