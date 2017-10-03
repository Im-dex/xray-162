#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <imdexlib/string_ref.hpp>

using namespace imdex;
using namespace testing;
using namespace std::string_literals;

TEST(StringRefTest, EmptinessTest) {
    EXPECT_EQ(string_ref(), "");
    EXPECT_EQ(string_ref(), ""s);
    EXPECT_TRUE(string_ref().empty());
    EXPECT_FALSE(string_ref().nonEmpty());
}

TEST(StringRefTest, CStringTest) {
    string_ref ref = "static str";
    EXPECT_EQ(ref, "static str");
    EXPECT_EQ(ref.c_str(), "static str");
}

TEST(StringRefTest, StdStringTest) {
    auto str = "std::string"s;
    string_ref ref = str;
    EXPECT_EQ(ref, str);
    EXPECT_EQ(ref.c_str(), str.c_str());
}

TEST(StringRefTest, UserDefinedLiteralTest) {
    auto ref = "static_str"_sr;
    EXPECT_EQ(ref, "static_str");
}