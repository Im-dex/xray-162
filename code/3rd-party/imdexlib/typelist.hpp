#pragma once

namespace imdex {

template <typename... Ts>
struct typelist
{
    static constexpr size_t size() noexcept
    {
        return sizeof...(Ts);
    }
};

} // imdex namespace
