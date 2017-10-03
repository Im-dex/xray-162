#pragma once

#include <type_traits>

namespace imdex {

template <typename T>
class FlagSet final {
    static_assert(std::is_enum_v<T>, "Flag type needs to be enum");
    using Type = std::underlying_type_t<T>;
public:
    using value_type = T;
    using underlying_type = Type;

    FlagSet()
        : value(0)
    {}

    explicit FlagSet(const T val)
        : FlagSet(cast(val))
    {}

    FlagSet operator| (const T val) const {
        return value | cast(val);
    }

    FlagSet& operator|= (const T val) {
        value |= cast(val);
        return *this;
    }

    FlagSet operator- (const T val) const {
        return value & ~cast(val);
    }

    FlagSet operator-= (const T val) {
        value &= ~cast(val);
        return *this;
    }

    FlagSet asInverted() const {
        return ~value;
    }

    FlagSet& invert() {
        value = ~value;
        return *this;
    }

    FlagSet& reset() {
        value = Type(0);
        return *this;
    }

    bool empty() const {
        return value == 0;
    }

    bool has(const T val) const {
        const auto underlyingVal = cast(val);
        return (value & underlyingVal) == underlyingVal;
    }

    bool notHas(const T val) const {
        return (value & cast(val)) != val;
    }

    underlying_type underlying() const noexcept {
        return value;
    }

private:
    FlagSet(const Type value)
        : value(value)
    {}

    static Type cast(const T val) {
        return static_cast<Type>(val);
    }

    Type value;
};

template <typename T>
FlagSet<T> flag(const T val) {
    return FlagSet<T>(val);
}

} // imdex namespace
