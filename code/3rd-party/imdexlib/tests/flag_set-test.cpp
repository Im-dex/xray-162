#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <imdexlib/flag_set.hpp>

using namespace imdex;
using namespace testing;

enum class TestFlag {
    F1 = 1,
    F2 = 2,
    F3 = 4,
    F4 = 8
};

using Set = FlagSet<TestFlag>;

TEST(FlagSetTest, SetTest) {
    auto set = flag(TestFlag::F1) | TestFlag::F3 | TestFlag::F4;
    EXPECT_EQ(set.underlying(), 0b1101);

    set = flag(TestFlag::F3) | TestFlag::F3;
    EXPECT_EQ(set.underlying(), 0b100);
}

TEST(FlagSetTest, ClearTest) {
    auto set = flag(TestFlag::F2) | TestFlag::F4;
    EXPECT_EQ(set.underlying(), 0b1010);

    set -= TestFlag::F2;
    EXPECT_EQ(set.underlying(), 0b1000);

    set -= TestFlag::F4;
    EXPECT_EQ(set.underlying(), 0);
    EXPECT_TRUE(set.empty());
}

TEST(FlagSetTest, CheckTest) {
    auto set = flag(TestFlag::F2) | TestFlag::F3;
    EXPECT_TRUE(set.has(TestFlag::F2));
    EXPECT_TRUE(set.has(TestFlag::F3));
    EXPECT_FALSE(set.has(TestFlag::F1));
    EXPECT_FALSE(set.has(TestFlag::F4));
}

TEST(FlagSetTest, InverseTest) {
    auto set = flag(TestFlag::F2) | TestFlag::F1;
    EXPECT_EQ(set.asInverted().underlying(), -4);
    EXPECT_EQ(set.invert().underlying(), -4);
}

TEST(FlagSetTest, ResetTest) {
    auto set = flag(TestFlag::F1) | TestFlag::F3;
    EXPECT_FALSE(set.empty());

    set.reset();
    EXPECT_TRUE(set.empty());
}
