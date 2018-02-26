#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <array>

#include <imdexlib/linear_allocator.hpp>

using namespace imdex;
using namespace testing;

struct LinearAllocatorTest : Test {
    static constexpr size_t bufferSize = 10;
    std::array<char, bufferSize> buffer;

    bool isBufferPtr(const char* ptr) const noexcept {
        return (ptr >= buffer.data()) && (ptr < (buffer.data() + buffer.size()));
    }
};

TEST_F(LinearAllocatorTest, TestAllocation) {
    linear_allocator<char> alloc(buffer);
    char* bufferPtr = alloc.allocate(bufferSize);
    EXPECT_TRUE(isBufferPtr(bufferPtr));

    char* ptr = alloc.allocate(1);
    EXPECT_FALSE(isBufferPtr(ptr));

    alloc.deallocate(ptr, 1);
    alloc.deallocate(bufferPtr, bufferSize);
}

TEST_F(LinearAllocatorTest, TestReallocation) {
    linear_allocator<char> alloc(buffer);
    auto* ptr = alloc.allocate(bufferSize - 2);
    ASSERT_TRUE(alloc.try_reallocate(ptr, bufferSize - 2, bufferSize - 3));
    ASSERT_TRUE(alloc.try_reallocate(ptr, bufferSize - 3, bufferSize));
    ASSERT_FALSE(alloc.try_reallocate(ptr, bufferSize, bufferSize + 1));
    alloc.deallocate(ptr, bufferSize);
}
