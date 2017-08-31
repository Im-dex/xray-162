#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <imdexlib/scope_guard.hpp>

using namespace imdex;
using namespace testing;

struct call_mock : Mock {
    call_mock() = default;
    call_mock(const call_mock&) = delete;
    call_mock& operator= (const call_mock&) = delete;

    MOCK_CONST_METHOD0(expected, void());
    MOCK_CONST_METHOD0(unexpected, void());
};

TEST(ScopeGuardTest, ScopeExitTest) {
#ifdef NDEBUG
    static constexpr size_t expectedCallsCount = 1;
#else
    static constexpr size_t expectedCallsCount = 2;
#endif

    call_mock mock;
    EXPECT_CALL(mock, expected()).Times(Exactly(expectedCallsCount));

    {
        IMDEXLIB_SCOPE_EXIT { mock.expected(); };
    }

#ifndef NDEBUG
    EXPECT_ANY_THROW(
        IMDEXLIB_SCOPE_EXIT{ mock.expected(); };
        throw 0;
    );
#endif
}

TEST(ScopeGuardTest, ScopeSuccessTest) {
    call_mock mock;
    EXPECT_CALL(mock, expected()).Times(Exactly(1));
#ifndef NDEBUG
    EXPECT_CALL(mock, unexpected()).Times(Exactly(0));
#endif

    {
        IMDEXLIB_SCOPE_SUCCESS { mock.expected(); };
    }

#ifndef NDEBUG
    EXPECT_ANY_THROW(
        IMDEXLIB_SCOPE_SUCCESS{ mock.unexpected(); };
        throw 0;
    );
#endif
}

TEST(ScopeGuardTest, ScopeFailTest) {
    call_mock mock;
#ifndef NDEBUG
    EXPECT_CALL(mock, expected()).Times(Exactly(1));
#endif
    EXPECT_CALL(mock, unexpected()).Times(Exactly(0));

    {
        IMDEXLIB_SCOPE_FAIL{ mock.unexpected(); };
    }

#ifndef NDEBUG
    EXPECT_ANY_THROW(
        IMDEXLIB_SCOPE_FAIL{ mock.expected(); };
        throw 0;
    );
#endif
}