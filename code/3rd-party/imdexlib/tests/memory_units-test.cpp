#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <imdexlib/memory_units.hpp>

using namespace imdex::mem_units;
using namespace testing;

TEST(MemoryUnitsTest, ComputeTest) {
    EXPECT_EQ(100_KB, 102400);
    EXPECT_EQ(2_MB, 2_KB * 1024);
    EXPECT_EQ(12_GB, 12_MB * 1024);
}
