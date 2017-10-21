#pragma once

#include <boost/fusion/adapted.hpp>
#include <boost/spirit/home/x3.hpp>

#include <imdexlib/option.hpp>

BOOST_FUSION_ADAPT_STRUCT(Fvector, x, y, z)

enum class XrSkipWs;
enum class XrNoSkip;

template <typename T, typename Parser, typename Skipper = XrNoSkip>
imdex::option<T> xrParse(const std::string_view str, const Parser& parser, Skipper = Skipper()) {
    using namespace boost::spirit::x3;
    using namespace imdex;

    T res;
    if constexpr (std::is_same_v<Skipper, XrSkipWs>) {
        if (!phrase_parse(str.begin(), str.end(), parser, ascii::space, res)) return none();
    } else {
        if (!parse(str.begin(), str.end(), parser, res)) return none();
    }

    return res;
}

inline imdex::option<double> xrParseDouble(const std::string_view str) {
    return xrParse<double>(str, boost::spirit::x3::double_);
}

inline imdex::option<float> xrParseFloat(const std::string_view str) {
    return xrParse<float>(str, boost::spirit::x3::float_);
}

inline imdex::option<std::uint8_t> xrParseUint8(const std::string_view str) {
    return xrParse<std::uint8_t>(str, boost::spirit::x3::uint8);
}

inline imdex::option<std::uint16_t> xrParseUint16(const std::string_view str) {
    return xrParse<std::uint16_t>(str, boost::spirit::x3::uint16);
}

inline imdex::option<std::uint32_t> xrParseUint32(const std::string_view str) {
    return xrParse<std::uint32_t>(str, boost::spirit::x3::uint32);
}

inline imdex::option<std::uint64_t> xrParseUint64(const std::string_view str) {
    return xrParse<std::uint64_t>(str, boost::spirit::x3::uint64);
}

inline imdex::option<std::int8_t> xrParseInt8(const std::string_view str) {
    return xrParse<std::int8_t>(str, boost::spirit::x3::int8);
}

inline imdex::option<std::int16_t> xrParseInt16(const std::string_view str) {
    return xrParse<std::int16_t>(str, boost::spirit::x3::int16);
}

inline imdex::option<std::int32_t> xrParseInt32(const std::string_view str) {
    return xrParse<std::int32_t>(str, boost::spirit::x3::int32);
}

inline imdex::option<std::int64_t> xrParseInt64(const std::string_view str) {
    return xrParse<std::int64_t>(str, boost::spirit::x3::int64);
}

inline imdex::option<Fvector> xrParseFVector(const std::string_view str) {
    using namespace boost::spirit::x3;
    static const auto parser = float_ >> omit[char_(',')] >>
                               float_ >> omit[char_(',')] >>
                               float_;
    return xrParse<Fvector>(str, parser, XrSkipWs());
}

template <typename T>
imdex::option<T> xrParse(const std::string_view str) {
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
    } else if constexpr (std::is_same_v<T, Fvector>) {
        return xrParseFVector(str);
    } else {
        static_assert(false, "Type is unsupported");
        return std::declval<T>();
    }
}
