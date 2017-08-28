#pragma once

namespace imdex {

template <typename T>
struct identity
{
    using type = T;
};

template <typename T>
using identity_t = typename identity<T>::type;

} // imdex namespace
