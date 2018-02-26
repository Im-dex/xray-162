#pragma once

#include <variant>

namespace imdex {

template <typename Base, typename Variant>
struct is_common_base_type_variant;

template <typename Base, typename... Ts>
struct is_common_base_type_variant<Base, std::variant<Ts...>>
    : std::conjunction<std::is_base_of<Base, Ts>...>
{};

template <typename Base, typename Variant>
inline constexpr bool is_common_base_type_variant_v = is_common_base_type_variant<Base, Variant>::value;

namespace detail {

template <typename Base, typename Variant>
decltype(auto) get_base(Variant&& var) {
    using Result = std::conditional_t<
        std::is_const_v<Variant&&>,
        const Base&,
        Base&
    >;

    if constexpr (!std::is_const_v<Base> && !std::is_reference_v<Base>) {
        if constexpr (is_common_base_type_variant_v<Base, Variant>) {
            return std::visit([](auto&& value) {
                return static_cast<Result>(value);
            }, var);
        } else {
            static_assert(false, "Not all of the variant types have required base type");
            return std::declval<Result>();
        }
    } else {
        static_assert(false, "Base type needs not to have cv qualifiers");
        return std::declval<Result>();
    }
}

} // detail namespace

template <typename Base, typename... Ts>
const Base& get_base(const std::variant<Ts...>& var) {
    return detail::get_base<Base>(var);
}

template <typename Base, typename... Ts>
Base& get_base(std::variant<Ts...>& var) {
    return detail::get_base<Base>(var);
}

template <typename Base, typename... Ts>
Base& get_base(std::variant<Ts...>&& var) = delete;

} // imdex namespace
