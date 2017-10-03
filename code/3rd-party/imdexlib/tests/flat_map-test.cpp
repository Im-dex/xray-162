#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <imdexlib/flat_map.hpp>

using namespace imdex;
using namespace testing;
using namespace std::string_literals;

TEST(FlatMapTest, InsertTest) {
    using Map = FlatMap<int, int, std::greater<int>>;
    Map map;

    EXPECT_EQ(map.insert(0, 1), InsertResult::New);
    EXPECT_EQ(map.insert(2, 2), InsertResult::New);
    EXPECT_EQ(map.insert(4, 3), InsertResult::New);
    EXPECT_EQ(map.insert(3, 4), InsertResult::New);
    EXPECT_EQ(map.insert(1, 5), InsertResult::New);

    const auto keyPred = [](const auto& lhs, const auto& rhs) {
        return lhs.first > rhs.first;
    };

    EXPECT_THAT(map, SizeIs(5));
    EXPECT_THAT(map, Not(IsEmpty()));
    EXPECT_TRUE(std::is_sorted(map.begin(), map.end(), keyPred));

    EXPECT_EQ(map.insert({ 0, 42 }), InsertResult::Update);
}

TEST(FlatMapTest, BulkInsertTest) {
    using Map = FlatMap<int, std::string>;
    Map map = {
        { 0,  ""s   },
        { 42, "42"s },
        { 12, "12"s },
        { 94, "94"s },
        { 11, "11"s }
    };

    const auto keyPred = [](const auto& lhs, const auto& rhs) {
        return lhs.first < rhs.first;
    };

    EXPECT_THAT(map, SizeIs(5));
    EXPECT_THAT(map, Not(IsEmpty()));
    EXPECT_TRUE(std::is_sorted(map.begin(), map.end(), keyPred));
}

TEST(FlatMapTest, FindTest) {
    using Map = FlatMap<std::string, int>;
    Map map = {
        { ""s,   0  },
        { "42"s, 42 },
        { "12"s, 12 },
        { "94"s, 94 },
        { "11"s, 11 }
    };

    EXPECT_TRUE(map.contains("42"s));
    EXPECT_FALSE(map.contains("100500"s));

    const auto cmpPred = [](const std::string& lhs, const char* rhs) {
        return lhs < rhs;
    };
    EXPECT_TRUE(map.contains("42", cmpPred));
    EXPECT_FALSE(map.contains("100500", cmpPred));

    EXPECT_EQ(map.find("12"s)->second, 12);
    EXPECT_EQ(map.find("100500"s), map.end());

    EXPECT_EQ(map.find("12", cmpPred)->second, 12);
    EXPECT_EQ(map.find("100500", cmpPred), map.end());
}
