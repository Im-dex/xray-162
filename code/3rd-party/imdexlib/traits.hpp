#pragma once

#include <iterator>
#include <imdexlib/typelist.hpp>

#include "detection.hpp"

namespace imdex {

template <typename T>
using remove_cvr = std::remove_cv<std::remove_reference_t<T>>;

template <typename T>
using remove_cvr_t = typename remove_cvr<T>::type;

namespace detail {

template <typename T, typename U>
struct is_comparable_to final {
    template <typename A, typename B>
    static auto check(A&& a, B&& b) -> decltype(a == b, std::true_type{});

    static std::false_type check(...);

    using result = decltype(check(std::declval<T>(), std::declval<U>()));
};

} // detail namespace

template <typename T, typename U>
using is_comparable_to = typename detail::is_comparable_to<T, U>::result;

template <typename T, typename U>
constexpr bool is_comparable_to_v = is_comparable_to<T, U>::value;

template <typename T>
using is_comparable = is_comparable_to<T, T>;

template <typename T>
constexpr bool is_comparable_v = is_comparable<T>::value;

namespace detail {

template <typename T, typename U>
struct is_nothrow_comparable_to final {
    template <typename A, typename B>
    static auto check(A&& a, B&& b) -> decltype(std::bool_constant<noexcept(a == b)>{});

    static std::false_type check(...);

    using result = decltype(check(std::declval<T>(), std::declval<U>()));
};

} // detail namespace

template <typename T, typename U>
using is_nothrow_comparable_to = typename detail::is_nothrow_comparable_to<T, U>::result;

template <typename T, typename U>
constexpr bool is_nothrow_comparable_to_v = is_nothrow_comparable_to<T, U>::value;

template <typename T>
using is_nothrow_comparable = is_nothrow_comparable_to<T, T>;

template <typename T>
constexpr bool is_nothrow_comparable_v = is_nothrow_comparable<T>::value;

namespace detail {

using std::begin;
using std::end;
using std::size;

template <typename T>
class is_sequence {
    template <typename U>
    static auto check(U&& v) -> decltype(begin(v), end(v), std::true_type{});

    static std::false_type check(...);
public:
    static constexpr bool value = decltype(check(std::declval<T>()))::value;
};

template <typename Iter>
using iterator_category_t = typename std::iterator_traits<Iter>::iterator_category;

template <typename Seq>
using size_method_t = decltype(size(std::declval<const Seq&>()));

} // detail namespace

template <typename T>
using is_sequence = detail::is_sequence<T>;

template <typename T>
constexpr bool is_sequence_v = is_sequence<T>::value;

template <typename T>
using is_iterator = is_detected<detail::iterator_category_t, T>;

template <typename T>
constexpr bool is_iterator_v = is_iterator<T>::value;

template <typename T>
using is_random_access_iterator = is_detected_exact<std::random_access_iterator_tag,
                                                    detail::iterator_category_t,
                                                    T>;

template <typename T>
constexpr bool is_random_access_iterator_v = is_random_access_iterator<T>::value;

template <typename T>
using is_size_aware = is_detected<detail::size_method_t, T>;

template <typename T>
constexpr bool is_size_aware_v = is_size_aware<T>::value;

namespace detail {

template <typename Handler, typename Params, typename AlwaysVoid = void>
struct is_callable : std::false_type {};

template <typename Handler, typename... Args>
struct is_callable<Handler, typelist<Args...>,
                   std::void_t<decltype(std::declval<Handler>()(std::declval<Args>()...))>> : std::true_type {};

template <typename Res, typename Handler, typename Params, typename AlwaysVoid = void>
struct is_callable_r : std::false_type {};

template <typename Res, typename Handler, typename... Args>
struct is_callable_r<Res, Handler, typelist<Args...>,
                     std::void_t<decltype(std::declval<Handler>()(std::declval<Args>()...))>>
    : std::is_same<Res, decltype(std::declval<Handler>()(std::declval<Args>()...))> {};


} // detail namespace

template <typename Handler, typename... Args>
using is_callable = detail::is_callable<Handler, typelist<Args...>>;

template <typename Handler, typename... Args>
constexpr bool is_callable_v = is_callable<Handler, Args...>::value;

template <typename Res, typename Handler, typename... Args>
using is_callable_r = detail::is_callable_r<Res, Handler, typelist<Args...>>;

template <typename Res, typename Handler, typename... Args>
constexpr bool is_callable_r_v = is_callable_r<Res, Handler, Args...>::value;

template <typename T, typename U>
struct is_same_template : std::false_type {};

template <template <typename...> class T, typename... Ts, typename... Us>
struct is_same_template<T<Ts...>, T<Us...>> : std::true_type {};

template <typename T, typename U>
constexpr bool is_same_template_v = is_same_template<T, U>::value;

} // imdex namespace
