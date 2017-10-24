#pragma once

#include "identity.hpp"

namespace imdex {

template <typename... Ts>
struct typelist {
    static constexpr size_t size() noexcept {
        return sizeof...(Ts);
    }
};

template <typename T>
struct is_typelist : std::false_type {};

template <typename... Ts>
struct is_typelist<typelist<Ts...>> : std::true_type {};

template <typename T>
constexpr bool is_typelist_v = is_typelist<T>::value;

template <typename T, typename List>
struct ts_prepend;

template <typename T, typename... Ts>
struct ts_prepend<T, typelist<Ts...>> {
    using type = typelist<T, Ts...>;
};

template <typename T, typename List>
using ts_prepend_t = typename ts_prepend<T, List>::type;

template <typename List, typename T>
struct ts_append;

template <typename T, typename... Ts>
struct ts_append<typelist<Ts...>, T> {
    using type = typelist<Ts..., T>;
};

template <typename List, typename T>
using ts_append_t = typename ts_append<List, T>::type;

template <typename List>
struct ts_head;

template <typename T, typename... Ts>
struct ts_head<typelist<T, Ts...>> {
    using type = T;
};

template <typename List>
using ts_head_t = typename ts_head<List>::type;;

template <typename List>
struct ts_tail;

template <typename T, typename... Ts>
struct ts_tail<typelist<T, Ts...>> {
    using type = typelist<Ts...>;
};

template <>
struct ts_tail<typelist<>> {
    using type = typelist<>;
};

template <typename List>
using ts_tail_t = typename ts_tail<List>::type;

template <typename List>
struct ts_reverse;

template <typename T, typename... Ts>
struct ts_reverse<typelist<T, Ts...>> {
    using type = ts_append_t<typename ts_reverse<typelist<Ts...>>::type, T>;
};

template <>
struct ts_reverse<typelist<>> {
    using type = typelist<>;
};

template <typename List>
using ts_reverse_t = typename ts_reverse<List>::type;

namespace detail {

template <typename List>
struct ts_applier;

template <typename... Ts>
struct ts_applier<typelist<Ts...>> {
    template <typename Handler>
    static void apply(Handler&& handler) {
        [[maybe_unused]]
        const int fold[] = { (handler(identity<Ts>()), 0)..., 0 };
    }
};

} // detail namespace

template <typename List, typename Handler>
void ts_apply(Handler&& handler) {
    detail::ts_applier<List>::apply(std::forward<Handler>(handler));
}

} // imdex namespace
