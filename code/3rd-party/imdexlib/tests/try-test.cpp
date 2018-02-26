#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <imdexlib/try.hpp>

using namespace imdex;
using namespace testing;
using namespace std::string_literals;

using TestTry = Try<std::string>;

struct TryTest : Test {
    const std::string value = "val"s;
    const std::error_code error = std::make_error_code(std::errc::invalid_argument);

    TestTry successed() const {
        return value;
    }

    TestTry failed() const {
        return to_failure(error);
    }
};

TEST_F(TryTest, ConstructorTest) {
    EXPECT_EQ(TestTry("val"s).get(), "val"s);
    EXPECT_EQ(TestTry(value).get(), value);

    EXPECT_EQ(TestTry(in_place_error, error).error(), error);
}

TEST_F(TryTest, RecoverSuccessedTest) {
    const TestTry res = successed().recover([](auto) { return "recovered"s; });
    EXPECT_TRUE(res.is_success());
    EXPECT_EQ(res.get(), value);
}

TEST_F(TryTest, RecoverFailedTest) {
    const TestTry res = failed().recover([](auto) { return "recovered"s; });
    EXPECT_TRUE(res.is_success());
    EXPECT_EQ(res.get(), "recovered"s);
}

TEST_F(TryTest, MapSuccessedTest) {
    const Try<size_t> res = successed().map([](auto value) { return value.size(); });
    EXPECT_TRUE(res.is_success());
    EXPECT_EQ(res.get(), value.size());
}

TEST_F(TryTest, MapFailedTest) {
    const Try<size_t> res = failed().map([](auto value) { return value.size(); });
    EXPECT_TRUE(res.is_failure());
    EXPECT_EQ(res.error(), error);
}

TEST_F(TryTest, FlatMapSuccessedBySuccessedTest) {
    const Try<size_t> res = successed().flat_map([](auto value) {
        return Try<size_t>(value.size());
    });
    EXPECT_TRUE(res.is_success());
    EXPECT_EQ(res.get(), value.size());
}

TEST_F(TryTest, FlatMapSuccessedByFailedTest) {
    const Try<float> res = successed().flat_map([&](auto value) {
        return Try<float>(in_place_error, error);
    });
    EXPECT_TRUE(res.is_failure());
    EXPECT_EQ(res.error(), error);
}

TEST_F(TryTest, FlatMapFailedBySuccessedTest) {
    const auto res = failed().flat_map([](auto value) { return Try<size_t>(value.size()); });
    EXPECT_TRUE(res.is_failure());
    EXPECT_EQ(res.error(), error);
}

TEST_F(TryTest, FlatMapFailedByFailedTest) {
    const auto err = std::make_error_code(std::errc::address_in_use);
    const auto res = failed().flat_map([&](auto value) { return Try<float>(in_place_error, err); });
    EXPECT_TRUE(res.is_failure());
    EXPECT_EQ(res.error(), error);
}

TEST_F(TryTest, SuccessTest) {
    const TestTry res = "ss"s;
    EXPECT_TRUE(res.is_success());
    EXPECT_EQ(res.get(), "ss"s);
}

TEST_F(TryTest, FailureTest) {
    const TestTry res = to_failure(error);
    EXPECT_TRUE(res.is_failure());
    EXPECT_EQ(res.error(), error);
}
