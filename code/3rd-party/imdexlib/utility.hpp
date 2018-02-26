#pragma once

namespace imdex {

class in_place final {};

template <typename...>
constexpr bool false_v = false;

template <typename T>
T& drop_const(const T& value) {
    return const_cast<T&>(value);
}

} // imdex namespace
