#pragma once

#include <imdexlib/detection.hpp>
#include <imdexlib/traits.hpp>

namespace xr {
namespace detail::error {

template <typename T>
using print_t = decltype(
    std::declval<const T&>().print(std::declval<fmt::BasicWriter<char>&>())
);

template <typename T>
using is_error = imdex::is_detected<print_t, T>;

template <typename T>
constexpr bool is_error_v = is_error<T>::value;

template <typename... Errs>
struct generate_error {
    static_assert(!std::disjunction_v<std::is_reference<Errs>...>,
                  "Error type needs to be not a reference");
    static_assert(!std::disjunction_v<std::is_const<Errs>...>,
                  "Error type needs to be not const");
    static_assert(!std::disjunction_v<std::is_void<Errs>...>,
                  "Error type needs to be not a void");
    static_assert(imdex::ts_is_unique_v<imdex::typelist<Errs...>>,
                  "The list of error types needs to be unique");
    static_assert(std::conjunction_v<is_error<Errs>...>,
                  "Error type needs to have print(fmt::BasicWriter<char>&) const method");
    static_assert(sizeof...(Errs) > 0, "Empty error list");
    using type = std::variant<Errs...>;
};

} // detail::error namespace

template <typename... Errs>
using Error = typename detail::error::generate_error<Errs...>::type;

template <typename... Errs>
void printError(const Error<Errs...>& error, fmt::BasicWriter<char>& writer) {
    std::visit([&](const auto& err) { err.print(writer); }, error);
}

template <typename E>
void printError(const E& error, fmt::BasicWriter<char>& writer) {
    if constexpr (detail::error::is_error_v<E>) {
        error.print(writer);
    } else {
        // ReSharper disable once CppStaticAssertFailure
        static_assert(false, "Argument is not an expected error type");
    }
}

class FileNotFoundError final {
public:
    explicit FileNotFoundError(stdfs::path path)
        : path(std::move(path))
    {}

    void print(fmt::BasicWriter<char>& writer) const {
        writer.write("File '{}' not found", path);
    }
private:
    stdfs::path path;
};

} // xr namespace
