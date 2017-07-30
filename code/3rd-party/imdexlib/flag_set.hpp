#pragma once

#include <type_traits>
#include <numeric>

namespace imdexlib {

template <typename T>
class FlagSet final {
    static_assert(std::is_enum_v<T>, "Flag type needs to be enum");
    using Type = std::underlying_type<T>;
public:
    static FlagSet all() {
        return FlagSet(Type(-1));
    }

    FlagSet()
        : value(0)
    {}

    explicit FlagSet(const T val)
        : FlagSet(cast(val))
    {}

    FlagSet(std::initializer_list<T> values)
        : value(fold(values))
    {}

    FlagSet operator| (const T val) const {
        return value | cast(val);
    }

    FlagSet& operator|= (const T val) {
        value |= cast(val);
        return *this;
    }

    FlagSet operator| (std::initializer_list<T> values) const {
        return value | fold(values);
    }

    FlagSet& operator|= (std::initializer_list<T> values) {
        value |= fold(values);
        return *this;
    }

    FlagSet invert() const {
        return ~value;
    }

    bool empty() const {
        return value == 0;
    }

    bool has(const T val) const {
        return (value & cast(val)) != 0;
    }

    bool notHas(const T val) const {
        return !has(val);
    }

    bool has(std::initializer_list<T> values) const {
        for (const auto val : values) {
            if (notContains(val)) {
                return false;
            }
        }
        return true;
    }

private:
    explicit FlagSet(const Type value)
        : value(value)
    {}

    static Type cast(const T val) {
        return static_cast<Type>(val);
    }

    static Type fold(std::initializer_list<T> values) {
        return std::accumulate(values.begin(), values.end(), Type(0),
                               [](const auto accum, const auto val) {
            return accum | cast(val);
        });
    }

    Type value;
};

} // imdexlib namespace
