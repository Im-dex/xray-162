#pragma once

#include <type_traits>

namespace std {

template <typename T>
class reference_wrapper;

template <typename... Ts>
class tuple;

} // std namespace

namespace imdex {

template <typename T>
struct is_reference_wrapper : std::false_type {};

template <typename T>
struct is_reference_wrapper<std::reference_wrapper<T>> : std::true_type {};

template <typename T>
constexpr bool is_reference_wrapper_v = is_reference_wrapper<T>::value;

template <typename T>
struct is_tuple : std::false_type {};

template <typename... Ts>
struct is_tuple<std::tuple<Ts...>> : std::true_type {};

template <typename T>
constexpr bool is_tuple_v = is_tuple<T>::value;

} // imdex namespace
