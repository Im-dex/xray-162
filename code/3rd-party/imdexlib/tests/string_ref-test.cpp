#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <imdexlib/string_ref.hpp>

using namespace imdex;
using namespace testing;
using namespace std::string_literals;
using namespace string_ref_literals;

TEST(StringRefTest, EmptinessTest) {
    EXPECT_STREQ(string_ref().c_str(), "");
    EXPECT_EQ(string_ref().c_str(), ""s);
    EXPECT_TRUE(string_ref().empty());
    EXPECT_FALSE(string_ref().non_empty());
}

TEST(StringRefTest, CStringTest) {
    const string_ref ref = "static str";
    EXPECT_STREQ(ref.c_str(), "static str");
}

TEST(StringRefTest, StdStringTest) {
    const auto str = "std::string"s;
    const string_ref ref = str;
    EXPECT_EQ(ref.c_str(), str.c_str());
}

TEST(StringRefTest, UserDefinedLiteralTest) {
    const auto ref = "static_str"_sr;
    EXPECT_STREQ(ref.c_str(), "static_str");
}