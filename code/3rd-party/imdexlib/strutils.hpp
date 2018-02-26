#pragma once

#include <string>
#include <string_view>
#include <numeric>
#include <cctype>
#include <wctype.h>

#include "fwd.hpp"
#include "traits.hpp"

namespace imdex::str {

template <typename Sequence,
          typename Char = char,
          typename Traits = std::char_traits<Char>>
std::basic_string<Char, Traits> join(const Sequence& seq,
                                     const std::basic_string_view<Char, Traits> delimiter = {}) {
    if constexpr (is_sequence_v<Sequence>) {
        using std::begin;
        using std::end;
        using std::empty;

        if (empty(seq)) {
            return {};
        }

        using element_type = remove_cvr_t<decltype(*begin(seq))>;
        if constexpr (std::is_convertible_v<element_type, std::basic_string_view<Char, Traits>>) {
            const auto dataLength = std::accumulate(begin(seq), end(seq), size_t(0u),
                                                    [](const size_t accum, const auto& str) {
                return accum + str.size();
            });

            const auto separatorsLength = delimiter.size() * (seq.size() - 1);
            const auto length = dataLength + separatorsLength;

            std::basic_string<Char, Traits> result;
            result.reserve(length);

            auto iter = begin(seq);
            auto nextIter = std::next(iter);

            while (nextIter != end(seq)) {
                result.append(*iter);
                result.append(delimiter);
                iter = nextIter++;
            }

            result.append(*iter);
            return result;
        } else {
            // ReSharper disable once CppStaticAssertFailure
            static_assert(false, "Unexpected element type");
            return {};
        }
    } else {
        // ReSharper disable once CppStaticAssertFailure
        static_assert(false, "Sequence expected");
        return {};
    }
}

inline std::string join(std::initializer_list<std::string_view> strs,
                        const std::string_view delimiter = {}) {
    return join<std::initializer_list<std::string_view>>(strs, delimiter);
}

inline std::wstring join(std::initializer_list<std::wstring_view> strs,
                         const std::wstring_view delimiter = {}) {
    return join<std::initializer_list<std::wstring_view>>(strs, delimiter);
}

namespace detail {

template <typename Traits, typename Str, typename Pattern>
bool starts_with(const Str& str, const Pattern& pattern) {
    using std::size;
    using std::data;
    return (size(str) >= size(pattern)) &&
           (Traits::compare(data(str), data(pattern), size(pattern)) == 0);
}

template <typename Traits, typename Str, typename Pattern>
bool ends_with(const Str& str, const Pattern& pattern) {
    using std::size;
    using std::data;
    const auto patSize = size(pattern);
    return (size(str) >= patSize) &&
           (Traits::compare(data(str) + (size(str) - patSize), data(pattern), patSize) == 0);
}

} // detail namespace

template <typename Char, typename Traits, typename Alloc>
bool starts_with(const std::basic_string<Char, Traits, Alloc>& str, const Char symbol) {
    return !str.empty() && str.front() == symbol;
}

template <typename Char, typename Traits, typename Alloc>
bool starts_with(const std::basic_string<Char, Traits, Alloc>& str,
                 const std::basic_string_view<Char, Traits> pattern) {
    return detail::starts_with<Traits>(str, pattern);
}

template <typename Char, typename Traits, typename Alloc1, typename Alloc2>
bool starts_with(const std::basic_string<Char, Traits, Alloc1>& str,
                 const std::basic_string<Char, Traits, Alloc2> pattern) {
    return detail::starts_with<Traits>(str, pattern);
}

template <typename Char, typename Traits>
bool starts_with(const std::basic_string_view<Char, Traits> str, const char symbol) {
    return !str.empty() && str.front() == symbol;
}

template <typename Char, typename Traits>
bool starts_with(const std::basic_string_view<Char, Traits> str,
                 const std::basic_string_view<Char, Traits> pattern) {
    return detail::starts_with<Traits>(str, pattern);
}

template <typename Char, typename Traits, typename Alloc>
bool starts_with(const std::basic_string_view<Char, Traits> str,
                 const std::basic_string<Char, Traits, Alloc> pattern) {
    return detail::starts_with<Traits>(str, pattern);
}

template <typename Char, typename Traits = std::char_traits<Char>>
bool starts_with(const Char* str, const Char symbol) {
    return starts_with(std::basic_string_view<Char>(str), symbol);
}

template <typename Char, typename Traits>
bool starts_with(const Char* str, const std::basic_string_view<Char, Traits> pattern) {
    return starts_with(std::basic_string_view<Char, Traits>(str), pattern);
}

template <typename Char, typename Traits, typename Alloc>
bool starts_with(const Char* str, const std::basic_string<Char, Traits, Alloc> pattern) {
    return starts_with(std::basic_string_view<Char, Traits>(str), pattern);
}

template <typename Char, typename Traits, typename Alloc>
bool ends_with(const std::basic_string<Char, Traits, Alloc>& str, const Char symbol) {
    return !str.empty() && str.back() == symbol;
}

template <typename Char, typename Traits, typename Alloc>
bool ends_with(const std::basic_string<Char, Traits, Alloc>& str,
               const std::basic_string_view<Char, Traits> pattern) {
    return detail::ends_with<Traits>(str, pattern);
}

template <typename Char, typename Traits, typename Alloc1, typename Alloc2>
bool ends_with(const std::basic_string<Char, Traits, Alloc1>& str,
               const std::basic_string<Char, Traits, Alloc2> pattern) {
    return detail::ends_with<Traits>(str, pattern);
}

template <typename Char, typename Traits>
bool ends_with(const std::basic_string_view<Char, Traits> str, const Char symbol) {
    return !str.empty() && str.back() == symbol;
}

template <typename Char, typename Traits>
bool ends_with(const std::basic_string_view<Char, Traits> str,
               const std::basic_string_view<Char, Traits> pattern) {
    return detail::ends_with<Traits>(str, pattern);
}

template <typename Char, typename Traits, typename Alloc>
bool ends_with(const std::basic_string_view<Char, Traits> str,
               const std::basic_string<Char, Traits, Alloc> pattern) {
    return detail::ends_with<Traits>(str, pattern);
}

template <typename Char, typename Traits = std::char_traits<Char>>
bool ends_with(const Char* str, const Char symbol) {
    return ends_with(std::basic_string_view<Char, Traits>(str), symbol);
}

template <typename Char, typename Traits, typename Alloc>
bool ends_with(const Char* str, const std::basic_string<Char, Traits, Alloc> pattern) {
    return ends_with(std::basic_string_view<Char, Traits>(str), pattern);
}

template <typename Char, typename Traits>
bool ends_with(const Char* str, const std::basic_string_view<Char, Traits> pattern) {
    return ends_with(std::basic_string_view<Char, Traits>(str), pattern);
}

template <typename Char, typename Traits, typename Predicate>
std::basic_string_view<Char, Traits> trim(const std::basic_string_view<Char, Traits> str,
                                          Predicate&& isSpacePred) {
    const auto start = std::find_if_not(str.begin(), str.end(), IMDEX_FWD(isSpacePred));
    const auto end = std::find_if_not(str.rbegin(), str.rend(), IMDEX_FWD(isSpacePred));
    const auto startOffset = std::distance(str.begin(), start);
    const auto endOffset = std::distance(str.rbegin(), end);
    return str.substr(startOffset, str.size() - startOffset - endOffset);
}

template <typename Traits>
std::basic_string_view<char, Traits> trim(const std::basic_string_view<char, Traits> str) {
    return trim(str, std::isspace);
}

template <typename Traits>
std::basic_string_view<wchar_t, Traits> trim(const std::basic_string_view<wchar_t, Traits> str) {
    return trim(str, iswspace);
}

} // imdex::str namespace
