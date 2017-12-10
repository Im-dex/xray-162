#pragma once

#include <boost/fusion/adapted.hpp>
#include <boost/fusion/adapted/std_tuple.hpp>
#include <boost/spirit/home/x3.hpp>

#include <imdexlib/option.hpp>

BOOST_FUSION_ADAPT_TPL_STRUCT(
    (T),
    (_vector2) (T),
    x, y
)

BOOST_FUSION_ADAPT_TPL_STRUCT(
    (T),
    (_vector3) (T),
    x, y, z
)

BOOST_FUSION_ADAPT_TPL_STRUCT(
    (T),
    (_vector4) (T),
    x, y, z, w
)

BOOST_FUSION_ADAPT_TPL_STRUCT(
    (T),
    (_color) (T),
    r, g, b, a
)

enum class XrSkipWs;
enum class XrNoSkip;

namespace conv_register {

#define REG_SIMPLE(Type, Parser)      \
    template <>                       \
    struct ParserFor<Type> {          \
        using Skipper = XrNoSkip;     \
        static const auto& parser() { \
            return Parser;            \
        }                             \
    };

template <typename T>
struct ParserFor;

REG_SIMPLE(std::int8_t, boost::spirit::x3::int8)
REG_SIMPLE(std::int16_t, boost::spirit::x3::int16)
REG_SIMPLE(std::int32_t, boost::spirit::x3::int32)
REG_SIMPLE(std::int64_t, boost::spirit::x3::int64)
REG_SIMPLE(std::uint8_t, boost::spirit::x3::uint8)
REG_SIMPLE(std::uint16_t, boost::spirit::x3::uint16)
REG_SIMPLE(std::uint32_t, boost::spirit::x3::uint32)
REG_SIMPLE(std::uint64_t, boost::spirit::x3::uint64)
REG_SIMPLE(float, boost::spirit::x3::float_)
REG_SIMPLE(double, boost::spirit::x3::double_)

template <typename T>
struct ParserFor<_vector2<T>> {
    using Skipper = XrSkipWs;
    static const auto& parser() {
        using namespace boost::spirit::x3;
        static const auto res = rule<class _vector2Parser, _vector2<T>>()
                              = ParserFor<T>::parser() >> ',' >> ParserFor<T>::parser();
        return res;
    }
};

template <typename T>
struct ParserFor<_vector3<T>> {
    using Skipper = XrSkipWs;
    static const auto& parser() {
        using namespace boost::spirit::x3;
        static const auto res = rule<class _vector3Parser, _vector3<T>>()
                              = ParserFor<T>::parser() >> ',' >>
                                ParserFor<T>::parser() >> ',' >>
                                ParserFor<T>::parser();
        return res;
    }
};

template <typename T>
struct ParserFor<_vector4<T>> {
    using Skipper = XrSkipWs;
    static const auto& parser() {
        using namespace boost::spirit::x3;
        static const auto res = rule<class _vector4Parser, _vector4<T>>()
                              = ParserFor<T>::parser() >> ',' >>
                                ParserFor<T>::parser() >> ',' >>
                                ParserFor<T>::parser() >> ',' >>
                                ParserFor<T>::parser();
        return res;
    }
};

template <typename T>
struct ParserFor<_color<T>> {
    using Skipper = XrSkipWs;
    static const auto& parser() {
        using namespace boost::spirit::x3;
        static const auto res = rule<class _colorParser, _color<T>>()
                              = ParserFor<T>::parser() >> ',' >>
                                ParserFor<T>::parser() >> ',' >>
                                ParserFor<T>::parser() >> ',' >>
                                ParserFor<T>::parser();
        return res;
    }
};

#undef REG_SIMPLE

} // conv_register namespace

template <typename T>
const auto& xrParserFor() {
    return conv_register::ParserFor<T>::parser();
}

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

template <typename T>
imdex::option<T> xrParse(const std::string_view str) {
    using ParserFor = conv_register::ParserFor<T>;
    return xrParse<T>(str, ParserFor::parser(), ParserFor::Skipper{});
}
