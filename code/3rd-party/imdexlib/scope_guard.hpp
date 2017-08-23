#pragma once

#include <type_traits>

#include "preprocessor.hpp"
#include "uncaught_exceptions_counter.hpp"

#define IMDEXLIB_SCOPE_EXIT\
    const auto IMDEXLIB_ANONYMOUS_VAR(scope_exit) = ::imdex::ScopeExit() + [&]()

#define IMDEXLIB_SCOPE_SUCCESS\
    const auto IMDEXLIB_ANONYMOUS_VAR(scope_success) = ::imdex::ScopeSuccess() + [&]()

#define IMDEXLIB_SCOPE_FAIL\
    const auto IMDEXLIB_ANONYMOUS_VAR(scope_fail) = ::imdex::ScopeFailure() + [&]() noexcept

namespace imdex {

enum class ScopeExit;
enum class ScopeSuccess;
enum class ScopeFailure;

template <typename Function>
class scope_guard final
{
public:

    explicit scope_guard(Function&& function) noexcept(std::is_nothrow_move_constructible_v<Function>)
        : function(std::move(function))
    {
    }

    scope_guard(scope_guard&& that) noexcept(std::is_nothrow_move_constructible_v<Function>)
        : function(std::move(that.function))
    {
    }

    scope_guard(const scope_guard&) = delete;

    scope_guard& operator= (const scope_guard&) = delete;
    scope_guard& operator= (scope_guard&&) = delete;

    ~scope_guard() noexcept(noexcept(std::declval<Function>()()))
    {
        function();
    }

private:

    Function function;
};

namespace detail {
namespace scope_guard {

template <typename Function, bool ExecuteOnException>
constexpr bool is_nothrow_destructor() noexcept
{
    return ExecuteOnException ? true : noexcept(std::declval<Function>()());
}

}} // detail::scope_guard namespace

template <typename Function, bool ExecuteOnException>
class scope_guard_for_new_exception final
{
public:

    explicit scope_guard_for_new_exception(Function&& function) noexcept(std::is_nothrow_move_constructible_v<Function>)
        : function(std::move(function)),
          counter()
    {
    }

    scope_guard_for_new_exception(scope_guard_for_new_exception&& that) noexcept(std::is_nothrow_move_constructible_v<Function>)
        : function(std::move(that.function)),
          counter(std::move(that.counter))
    {
    }

    scope_guard_for_new_exception(const scope_guard_for_new_exception&) = delete;

    scope_guard_for_new_exception& operator= (const scope_guard_for_new_exception&) = delete;
    scope_guard_for_new_exception& operator= (scope_guard_for_new_exception&&) = delete;

    ~scope_guard_for_new_exception() noexcept(detail::scope_guard::is_nothrow_destructor<Function, ExecuteOnException>())
    {
        execute(std::bool_constant<ExecuteOnException>());
    }

private:

    void execute(std::true_type /* execute on exception */) noexcept
    {
        if (counter.is_new_uncaught_exception())
            function();
    }

    void execute(std::false_type /* execute on exception */) noexcept(noexcept(std::declval<Function&>()()))
    {
        if (!counter.is_new_uncaught_exception())
            function();
    }

    Function function;
    uncaught_exceptions_counter counter;
};

template <typename Function>
scope_guard<std::decay_t<Function>> operator+ (ScopeExit, Function&& function)
    noexcept(std::is_nothrow_move_constructible_v<std::decay_t<Function>>)
{
    return scope_guard<std::decay_t<Function>>(std::forward<Function>(function));
}

template <typename Function>
scope_guard_for_new_exception<std::decay_t<Function>, true> operator+ (ScopeFailure, Function&& function)
    noexcept(std::is_nothrow_move_constructible_v<std::decay_t<Function>>)
{
    return scope_guard_for_new_exception<std::decay_t<Function>, true>(std::forward<Function>(function));
}

template <typename Function>
scope_guard_for_new_exception<std::decay_t<Function>, false> operator+ (ScopeSuccess, Function&& function)
    noexcept(std::is_nothrow_move_constructible_v<std::decay_t<Function>>)
{
    return scope_guard_for_new_exception<std::decay_t<Function>, false>(std::forward<Function>(function));
}

} // imdex namespace
