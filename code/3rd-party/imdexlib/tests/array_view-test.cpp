#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <imdexlib/array_view.hpp>

using namespace imdex;
using namespace testing;

TEST(ArrayViewTest, DefaultConstructionTest) {
    ArrayView<int> view;
    EXPECT_THAT(view, IsEmpty());
    EXPECT_FALSE(view.non_empty());
    EXPECT_THAT(view, SizeIs(0));
    EXPECT_EQ(view.data(), nullptr);
}

TEST(ArrayViewTest, CArrayConstructionTest) {
    const int cArray[10] = { 0 };

    ArrayView<int> view(cArray);
    EXPECT_THAT(view, SizeIs(10));
    EXPECT_EQ(view.data(), &cArray[0]);
}

TEST(ArrayViewTest, PointerWithSizeConstructionTest) {
    auto ptr = std::make_unique<int[]>(5);

    ArrayView<int> view(ptr.get(), 5);
    EXPECT_THAT(view, SizeIs(5));
    EXPECT_EQ(view.data(), ptr.get());
}

TEST(ArrayViewTest, StdArrayConstructionTest) {
    const std::array<int, 42> array = { 0 };

    ArrayView<int> view(array);
    EXPECT_THAT(view, SizeIs(array.size()));
    EXPECT_EQ(view.data(), array.data());
}

TEST(ArrayViewTest, IterationTest) {
    const std::array<int, 4> array = { 1, 2, 3, 4 };
    std::vector<int> res;

    for (const auto value : ArrayView<int>(array)) {
        res.push_back(value);
    }

    EXPECT_THAT(res, ElementsAreArray(array));
}
