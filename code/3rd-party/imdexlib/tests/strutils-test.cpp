#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <imdexlib/strutils.hpp>

using namespace imdex::str;
using namespace testing;
using namespace std::string_literals;
using namespace std::string_view_literals;

template <typename T>
struct StrUtilsTest : Test {
    T str = "prefix_data_suffix";
};

using StrTypes = Types<const char*, std::string, std::string_view>;
TYPED_TEST_CASE(StrUtilsTest, StrTypes);

TYPED_TEST(StrUtilsTest, JoinTest) {
    const auto expected = "a|b|cde|"s + std::string(this->str);
    EXPECT_EQ(join({ "a"s, "b", "cde"sv, this->str }, "|"sv), expected);
}

TYPED_TEST(StrUtilsTest, StartsWithTest) {
    EXPECT_TRUE(starts_with(this->str, 'p'));
    EXPECT_TRUE(starts_with(this->str, "prefix"s));
    EXPECT_TRUE(starts_with(this->str, "prefix"sv));
    EXPECT_FALSE(starts_with(this->str, 'r'));
    EXPECT_FALSE(starts_with(this->str, "data"s));
    EXPECT_FALSE(starts_with(this->str, "data"sv));
}

TYPED_TEST(StrUtilsTest, EndsWithTest) {
    EXPECT_TRUE(ends_with(this->str, 'x'));
    EXPECT_TRUE(ends_with(this->str, "suffix"s));
    EXPECT_TRUE(ends_with(this->str, "suffix"sv));
    EXPECT_FALSE(ends_with(this->str, 'r'));
    EXPECT_FALSE(ends_with(this->str, "data"s));
    EXPECT_FALSE(ends_with(this->str, "data"sv));
}

TYPED_TEST(StrUtilsTest, TrimTest) {
    TypeParam str = "\t\t   data    ewfdwe\t\t dqed\t\t ";
    EXPECT_EQ(trim(std::string_view(str)), "data    ewfdwe\t\t dqed"s);
    EXPECT_EQ(trim(std::string_view(this->str)), this->str);
}
