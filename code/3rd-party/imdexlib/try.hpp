#pragma once

#include <variant>
#include <numeric>
#include <vector>

#include "option.hpp"
#include "detection.hpp"
#include "preprocessor.hpp"

namespace imdex {

template <typename T, typename E>
class Try;

template <typename T>
struct is_try : std::false_type {};

template <typename T, typename E>
struct is_try<Try<T, E>> : std::true_type {};

template <typename T>
constexpr bool is_try_v = is_try<T>::value;

namespace detail::try_ {

template <typename Self, typename Handler>
auto map_error(Self&& self, Handler&& handler) {
    using T = typename remove_cvr_t<Self>::value_type;
    using Error = decltype(IMDEX_FWD(self).error());
    if constexpr (std::is_invocable_v<Handler&&, Error>) {
        using Res = remove_cvr_t<std::invoke_result_t<Handler&&, Error>>;
        if (self.is_failure()) {
            return Try<T, Res>(handler(IMDEX_FWD(self).error()));
        } else {
            return Try<T, Res>(IMDEX_FWD(self).get());
        }
    } else {
        // ReSharper disable once CppStaticAssertFailure
        static_assert(false, "Invalid map handler");
        return self;
    }
}

} // detail::try_ namespace

struct in_place_error_t final {};

constexpr inline in_place_error_t in_place_error;

#pragma warning(disable : 4521)

template <typename E>
class Failure {
    static_assert(!std::is_const_v<E>, "Error type needs not to be const");
    static_assert(!std::is_reference_v<E>, "Error type needs not to be a reference");
    static_assert(!std::is_void_v<E>, "Error type needs not to be a void");
public:
    template <typename... Args>
    Failure(Args&&... args)
        : error(std::forward<Args>(args)...)
    {}

    template <typename T>
    Failure(const Failure<T>& that)
        : error(that.get())
    {}

    template <typename T>
    Failure(Failure<T>& that)
        : error(that.get())
    {}

    template <typename T>
    Failure(Failure<T>&& that)
        : error(std::move(that).get())
    {}

    Failure(Failure& that)
        : Failure(static_cast<const Failure&>(that))
    {}

    Failure(const Failure& that)
        : error(that.error)
    {}

    Failure(Failure&&) = default;
    ~Failure() = default;

    Failure& operator= (const Failure&) = default;
    Failure& operator= (Failure&&) = default;

    const E& get() const & {
        return error;
    }

    E& get() & {
        return error;
    }

    E&& get() && {
        return std::move(error);
    }

    size_t hash() const {
        return std::hash<E>()(error);
    }

    void swap(Failure& that) {
        using std::swap;
        swap(error, that.error);
    }

    bool operator== (const Failure& that) const {
        return error == that.error;
    }

    bool operator!= (const Failure& that) const {
        return error != that.error;
    }
private:
    E error;
};

template <typename T, typename E = std::error_code>
class Try {
    static_assert(!std::is_reference_v<T>, "Value type needs not to be a reference");
    static_assert(!std::is_const_v<T>, "Value type needs not to be const");
public:
    using value_type = T;
    using error_type = E;

    template <typename U>
    Try(U&& value)
        : storage(std::in_place_index<0>, std::forward<U>(value))
    {}

    template <typename... Args>
    Try(in_place_error_t, Args&&... args)
        : storage(std::in_place_index<1>, std::forward<Args>(args)...)
    {}

    Try(const Failure<E>& failure)
        : storage(std::in_place_index<1>, failure)
    {}

    Try(Failure<E>& failure)
        : storage(std::in_place_index<1>, failure)
    {}

    Try(Failure<E>&& failure)
        : storage(std::in_place_index<1>, failure)
    {}

    template <typename U>
    Try(const Failure<U>& failure)
        : storage(std::in_place_index<1>, Failure<E>(failure))
    {}

    template <typename U>
    Try(Failure<U>& failure)
        : storage(std::in_place_index<1>, Failure<E>(failure))
    {}

    template <typename U>
    Try(Failure<U>&& failure)
        : storage(std::in_place_index<1>, Failure<E>(std::move(failure)))
    {}

    template <typename U>
    Try(Try<U>& that)
        : Try(initialize(static_cast<const Try<U>&>(that)))
    {}

    template <typename U>
    Try(const Try<U>& that)
        : Try(initialize(that))
    {}

    template <typename U>
    Try(Try<U>&& that)
        : Try(initialize(std::move(that)))
    {}

    Try(Try& that)
        : Try(static_cast<const Try&>(that))
    {}

    Try(const Try& that)
        : storage(that.storage)
    {}

    Try(Try&&) = default;
    ~Try() = default;

    Try& operator= (const Try&) = default;
    Try& operator= (Try&&) = default;

    bool is_success() const noexcept {
        return std::holds_alternative<T>(storage);
    }

    bool is_failure() const noexcept {
        return std::holds_alternative<Failure<E>>(storage);
    }

    const T& get() const & {
        return std::get<T>(storage);
    }

    T& get() & {
        return std::get<T>(storage);
    }

    T&& get() && {
        return std::get<T>(std::move(storage));
    }

    const T& get_or_else(const T& $default) const & {
        return is_success() ? get() : $default;
    }

    T& get_or_else(T& $default) & {
        return is_success() ? get() : $default;
    }

    T&& get_or_else(T&& $default) && {
        return is_success() ? get() : $default;
    }

    const T& get_or_else(T&& $default) & = delete;
    const T& get_or_else(T&& $default) const & = delete;

    const E& error() const & {
        return std::get<Failure<E>>(storage).get();
    }

    E& error() & {
        return std::get<Failure<E>>(storage).get();
    }

    E&& error() && {
        return std::get<Failure<E>>(std::move(storage)).get();
    }

    size_t hash() const {
        return std::hash<Storage>()(storage);
    }

    void swap(Try& that) {
        using std::swap;
        swap(storage, that.storage);
    }

    bool operator== (const Try& that) const {
        return storage == that.storage;
    }

    bool operator!= (const Try& that) const {
        return storage != that.storage;
    }

    explicit operator bool() const noexcept {
        return is_success();
    }

    template <typename Handler>
    Try recover(Handler&& handler) const & {
        return recover(*this, std::forward<Handler>(handler));
    }

    template <typename Handler>
    Try recover(Handler&& handler) && {
        return recover(std::move(*this), std::forward<Handler>(handler));
    }

    template <typename Handler>
    auto map(Handler&& handler) const & {
        return map(*this, IMDEX_FWD(handler));
    }

    template <typename Handler>
    auto map(Handler&& handler) && {
        return map(std::move(*this), IMDEX_FWD(handler));
    }

    template <typename Handler>
    auto flat_map(Handler&& handler) const & {
        return flat_map(*this, IMDEX_FWD(handler));
    }

    template <typename Handler>
    auto flat_map(Handler&& handler) && {
        return flat_map(std::move(*this), IMDEX_FWD(handler));
    }

    template <typename Handler>
    auto map_error(Handler&& handler) const & {
        return detail::try_::map_error(*this, IMDEX_FWD(handler));
    }

    template <typename Handler>
    auto map_error(Handler&& handler) && {
        return detail::try_::map_error(std::move(*this), IMDEX_FWD(handler));
    }

    template <typename Handler>
    void if_success(Handler&& handler) const & {
        if (is_success())
            handler(get());
    }

    template <typename Handler>
    void if_success(Handler&& handler) && {
        if (is_success())
            handler(get());
    }
private:
    using Storage = std::variant<T, Failure<E>>;

    template <typename That>
    static Storage initialize(That&& that) {
        if (that.is_success()) {
            using Value = decltype(IMDEX_FWD(that).get());
            if constexpr (std::is_constructible_v<T, Value>) {
                return Storage(std::in_place_index<0>, IMDEX_FWD(that).get());
            } else {
                // ReSharper disable once CppStaticAssertFailure
                static_assert(false, "Can't convert value type");
                return std::declval<Storage>();
            }
        } else {
            using Error = decltype(IMDEX_FWD(that).get_error());
            if constexpr (std::is_constructible_v<Failure<E>, Error>) {
                return Storage(std::in_place_index<1>, IMDEX_FWD(that).error());
            } else {
                // ReSharper disable once CppStaticAssertFailure
                static_assert(false, "Can't convert error type");
                return std::declval<Storage>();
            }
        }
    }

    template <typename Self, typename Handler>
    static Try recover(Self&& self, Handler&& handler) {
        using Error = decltype(IMDEX_FWD(self).error());
        if constexpr (std::is_invocable_r_v<T, Handler&&, Error>) {
            if (self.is_success()) {
                return self;
            } else {
                return Try(handler(IMDEX_FWD(self).error()));
            }
        } else {
            // ReSharper disable once CppStaticAssertFailure
            static_assert(false, "Invalid recover handler");
            return std::declval<Try>();
        }
    }

    template <typename Self, typename Handler>
    static auto map(Self&& self, Handler&& handler) {
        using Value = decltype(IMDEX_FWD(self).get());
        if constexpr (std::is_invocable_v<Handler&&, Value>) {
            using Res = remove_cvr_t<std::invoke_result_t<Handler&&, Value>>;
            if (self.is_success()) {
                return Try<Res, E>(handler(IMDEX_FWD(self).get()));
            } else {
                return Try<Res, E>(in_place_error, IMDEX_FWD(self).error());
            }
        } else {
            // ReSharper disable once CppStaticAssertFailure
            static_assert(false, "Invalid map handler");
            return self;
        }
    }

    template <typename Self, typename Handler>
    static auto flat_map(Self&& self, Handler&& handler) {
        using Value = decltype(IMDEX_FWD(self).get());
        if constexpr (std::is_invocable_v<Handler&&, Value>) {
            using Res = std::invoke_result_t<Handler&&, Value>;
            using Error = decltype(IMDEX_FWD(self).error());
            if constexpr (is_try_v<Res> &&
                          std::is_constructible_v<Res, in_place_error_t, Error>) {
                if (self.is_success()) {
                    return handler(IMDEX_FWD(self).get());
                } else {
                    return Res(in_place_error, IMDEX_FWD(self).error());
                }
            } else {
                // ReSharper disable once CppStaticAssertFailure
                static_assert(false, "Handler result needs to be try with compatible error type");
                return self;
            }
        } else {
            // ReSharper disable once CppStaticAssertFailure
            static_assert(false, "Invalid flat_map handler");
            return self;
        }
    }

    Storage storage;
};

#pragma warning(default : 4521)

template <typename E>
class Try<void, E> {
public:
    using value_type = void;
    using error_type = E;

    Try() = default;

    template <typename... Args>
    Try(in_place_error_t, Args&&... args)
        : error_(std::in_place, std::forward<Args>(args)...)
    {}

    template <typename U>
    Try(const Failure<U>& failure)
        : error_(failure.get())
    {}

    template <typename U>
    Try(Failure<U>&& failure)
        : error_(std::move(failure).get())
    {}

    template <typename U>
    Try(const Try<void, U>& that) : error_() {
        if (that.is_failure()) {
            error.emplace(that.get_error());
        }
    }

    template <typename U>
    Try(Try<void, U>&& that) : error_() {
        if (that.is_failure()) {
            error.emplace(std::move(that).get_error());
        }
    }

    bool is_success() const noexcept {
        return error_.empty();
    }

    bool is_failure() const noexcept {
        return error_.non_empty();
    }

    const E& error() const & {
        return error_.get();
    }

    E& error() & {
        return error_.get();
    }

    E&& error() && {
        return std::move(error_).get();
    }

    void swap(Try& that) {
        using std::swap;
        swap(error_, that.error_);
    }

    bool operator== (const Try& that) const {
        return error_ == that.error_;
    }

    bool operator!= (const Try& that) const {
        return error_ != that.error_;
    }

    explicit operator bool() const noexcept {
        return is_success();
    }

    Try recover() const {
        return Try();
    }

    template <typename U>
    Try<remove_cvr_t<U>, E> map(U&& value) const & {
        return map(*this, IMDEX_FWD(value));
    }

    template <typename U>
    Try<remove_cvr_t<U>, E> map(U&& value) && {
        return map(std::move(*this), IMDEX_FWD(value));
    }

    template <typename U>
    Try<U, E> flat_map(const Try<U, E>& that) const & {
        return flat_map(*this, that);
    }

    template <typename U>
    Try<U, E> flat_map(Try<U, E>&& that) const & {
        return flat_map(*this, std::move(that));
    }

    template <typename U>
    Try<U, E> flat_map(const Try<U, E>& that) && {
        return flat_map(std::move(*this), std::move(that));
    }

    template <typename U>
    Try<U, E> flat_map(Try<U, E>&& that) && {
        return flat_map(std::move(*this), std::move(that));
    }

    template <typename Handler>
    auto map_error(Handler&& handler) const & {
        return detail::try_::map_error(*this, IMDEX_FWD(handler));
    }

    template <typename Handler>
    auto map_error(Handler&& handler) && {
        return detail::try_::map_error(std::move(*this), IMDEX_FWD(handler));
    }

    template <typename Handler>
    void if_success(Handler&& handler) const {
        if (is_success())
            handler();
    }
private:
    template <typename Self, typename U>
    static auto map(Self&& self, U&& value) {
        using Res = Try<remove_cvr_t<U>, E>;
        if (self.is_success()) {
            return Res(IMDEX_FWD(value));
        } else {
            return Res(in_place_error, IMDEX_FWD(self).error());
        }
    }

    template <typename Self, typename U>
    static auto flat_map(Self&& self, U&& that) {
        if (self.is_success()) {
            return that;
        } else {
            using That = remove_cvr_t<U>;
            using Error = decltype(IMDEX_FWD(self).error());
            if constexpr (std::is_constructible_v<That, in_place_error_t, Error>) {
                return That(in_place_error, IMDEX_FWD(self).error());
            } else {
                // ReSharper disable once CppStaticAssertFailure
                static_assert(false, "Incompatible error type");
                return self;
            }
        }
    }

    option<E> error_;
};

template <typename TryT, typename T>
TryT make_try(T&& value) {
    if constexpr (is_try_v<TryT>) {
        return TryT(IMDEX_FWD(value));
    } else {
        // ReSharper disable once CppStaticAssertFailure
        static_assert(false, "Try expected");
        return std::declval<TryT>();
    }
}

template <typename TryT>
TryT make_try() {
    if constexpr (is_try_v<TryT>) {
        if constexpr (std::is_void_v<typename TryT::value_type>) {
            return TryT{};
        } else {
            // ReSharper disable once CppStaticAssertFailure
            static_assert(false, "Try<void, E> expected");
            return std::declval<TryT>();
        }
    } else {
        // ReSharper disable once CppStaticAssertFailure
        static_assert(false, "Try expected");
        return std::declval<TryT>();
    }
}

template <typename E>
Failure<remove_cvr_t<E>> to_failure(E&& error) {
    return Failure<remove_cvr_t<E>>(IMDEX_FWD(error));
}

template <typename E, typename... Args>
Failure<E> make_failure(Args&&... args) {
    return Failure<E>(std::forward<Args>(args)...);
}

template <typename E>
void swap(Failure<E>& lhs, Failure<E>& rhs) {
    lhs.swap(rhs);
}

template <typename T, typename E>
void swap(Try<T, E>& lhs, Try<T, E>& rhs) {
    lhs.swap(rhs);
}

template <typename Error,
          typename Storage = std::vector<Error>>
class ErrorChain final {
public:
    using iterator = typename Storage::iterator;
    using const_iterator = typename Storage::const_iterator;

    ErrorChain() = default;

    ErrorChain(const Error& err)
        : storage()
    {}

    ErrorChain(Error&& err)
        : storage()
    {}

    ErrorChain(std::initializer_list<Error> init)
        : storage(init)
    {}

    template <typename Iter>
    ErrorChain(Iter first, Iter last)
        : storage(first, last)
    {}

    void add_error(const Error& error) {
        storage.push_back(error);
    }

    void add_error(Error&& error) {
        storage.push_back(std::move(error));
    }

    template <typename... Args>
    void emplace_error(Args&&... args) {
        storage.emplace_back(std::forward<Args>(args)...);
    }

    bool empty() const noexcept {
        return storage.empty();
    }

    bool non_empty() const noexcept {
        return !empty();
    }

    iterator begin() noexcept {
        return storage.begin();
    }

    const_iterator begin() const noexcept {
        return storage.begin();
    }

    const_iterator cbegin() const noexcept {
        return storage.cbegin();
    }

    iterator end() noexcept {
        return storage.end();
    }

    const_iterator end() const noexcept {
        return storage.end();
    }

    const_iterator cend() const noexcept {
        return storage.cend();
    }
private:
    Storage storage;
};

} // imdex namespace

namespace std {

template <typename E>
struct hash<imdex::Failure<E>> {
    size_t operator()(const imdex::Failure<E>& value) const noexcept {
        return value.hash();
    }
};

template <typename T, typename E>
struct hash<imdex::Try<T, E>> {
    size_t operator()(const imdex::Try<T, E>& value) const noexcept {
        return value.hash();
    }
};

} // std namespace

#define IMDEX_UNWRAP_IMPL(ret, var, try_)                                                 \
    auto IMDEXLIB_ANONYMOUS_VAR(imdex__tryVal__) = try_;                                  \
    if (IMDEXLIB_ANONYMOUS_VAR(imdex__tryVal__).is_failure())                             \
        ret imdex::to_failure(std::move(IMDEXLIB_ANONYMOUS_VAR(imdex__tryVal__)).error());\
    auto var = std::move(IMDEXLIB_ANONYMOUS_VAR(imdex__tryVal__)).get()

#define IMDEX_UNWRAP(var, try_) IMDEX_UNWRAP_IMPL(return, var, try_)
#define IMDEX_CO_UNWRAP(var, try_) IMDEX_UNWRAP_IMPL(co_return, var, try_)
