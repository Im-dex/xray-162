#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <experimental/generator>

#include <imdexlib/flat_map.hpp>

#ifdef __RESHARPER__
#define co_yield
#endif

using namespace imdex;
using namespace testing;
using namespace std::string_literals;
using std::experimental::generator;

template <typename Key, typename Value, typename Compare>
bool isSorted(const FlatMap<Key, Value, Compare>& map) {
    return std::is_sorted(map.begin(), map.end(), [](const auto& lhs, const auto& rhs) {
        return Compare()(lhs.first, rhs.first);
    });
}

TEST(FlatMapTest, InitializerListConstructionTest) {
    FlatMap<int, int> map {
        {1, 1},
        {0, 0},
        {4, 4},
        {3, 3}
    };

    EXPECT_THAT(map, SizeIs(4));
    EXPECT_THAT(map, Not(IsEmpty()));
    EXPECT_TRUE(isSorted(map));
}

TEST(FlatMapTest, VectorConstructionTest) {
    std::vector<std::pair<int, int>> values = {
        {1, 1},
        {0, 0},
        {4, 4},
        {3, 3}
    };
    FlatMap<int, int> map(values);

    EXPECT_THAT(map, SizeIs(4));
    EXPECT_THAT(map, Not(IsEmpty()));
    EXPECT_TRUE(isSorted(map));
}

TEST(FlatMapTest, IteratorsConstructionTest) {
    const auto gen = []() -> generator<std::pair<int, int>> {
        co_yield {1, 1};
        co_yield {0, 0};
        co_yield {4, 4};
        co_yield {3, 3};
    };

    auto values = gen();
    FlatMap<int, int> map(values.begin(), values.end());

    EXPECT_THAT(map, SizeIs(4));
    EXPECT_THAT(map, Not(IsEmpty()));
    EXPECT_TRUE(isSorted(map));
}

TEST(FlatMapTest, InsertTest) {
    FlatMap<int, int> map;

    EXPECT_EQ(*map.insert(1, 1), std::make_pair(1, 1));
    EXPECT_THAT(map, SizeIs(1));

    EXPECT_EQ(*map.insert(std::make_pair(42, 42)), std::make_pair(42, 42));
    EXPECT_THAT(map, SizeIs(2));

    map.insert(std::initializer_list<std::pair<int, int>>{
        {5, 5},
        {3, 3}
    });
    EXPECT_THAT(map, SizeIs(4));
    EXPECT_TRUE(isSorted(map));
}

TEST(FlatMapTest, BulkInsertTest) {
    FlatMap<int, std::string> map;

    map.insert(std::initializer_list<std::pair<int, std::string>>{
        {0, ""s},
        {42, "42"s},
        {12, "12"s},
        {94, "94"s},
        {11, "11"s}
    });

    EXPECT_THAT(map, SizeIs(5));
    EXPECT_THAT(map, Not(IsEmpty()));
    EXPECT_TRUE(isSorted(map));
}

TEST(FlatMapTest, UpsertTest) {
    FlatMap<int, int, std::greater<>> map;

    EXPECT_EQ(map.upsert(0, 1).second, UpsertResult::Insert);
    EXPECT_EQ(map.upsert(2, 2).second, UpsertResult::Insert);
    EXPECT_EQ(map.upsert(4, 3).second, UpsertResult::Insert);
    EXPECT_EQ(map.upsert(3, 4).second, UpsertResult::Insert);
    EXPECT_EQ(map.upsert(1, 5).second, UpsertResult::Insert);

    EXPECT_THAT(map, SizeIs(5));
    EXPECT_THAT(map, Not(IsEmpty()));
    EXPECT_TRUE(isSorted(map));

    EXPECT_EQ(map.upsert({ 0, 42 }).second, UpsertResult::Update);
}

TEST(FlatMapTest, FindTest) {
    FlatMap<std::string, int> map {
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

inline FlatMap<int, int> mapWithDuplicates {
    { 0, 0 },
    { 1, 4 },
    { 1, 5 },
    { 42, 9 },
    { 12, 12 },
    { 23, 13 },
    { 19, 4 },
    { 42, 9 },
    { 0, 17 }
};

TEST(FlatMapTest, DuplicateTest) {
    EXPECT_THAT(mapWithDuplicates.duplicate_keys(),
                UnorderedElementsAre(0, 1, 42));

    EXPECT_THAT(mapWithDuplicates.duplicate_items(),
                UnorderedElementsAre(std::make_pair(42, 9)));
}

TEST(FlatMapTest, FindDuplicateKeysTest) {
    std::vector<int> dups;

    auto iter = mapWithDuplicates.find_duplicate_keys();
    while (iter != mapWithDuplicates.end()) {
        dups.push_back(*iter);
        std::advance(iter, 1);
    }

    EXPECT_THAT(dups, UnorderedElementsAre(0, 1, 42));
}

TEST(FlatMapTest, FindDuplicateItemsTest) {
    std::vector<std::pair<int, int>> dups;

    auto iter = mapWithDuplicates.find_duplicate_items();
    while (iter != mapWithDuplicates.end()) {
        dups.push_back(*iter);
        std::advance(iter, 1);
    }

    EXPECT_THAT(dups, UnorderedElementsAre(std::make_pair(42, 9)));
}
