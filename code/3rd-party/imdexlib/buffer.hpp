#pragma once

#include <array>

#include "linear_allocator.hpp"

namespace imdex {

template <typename T, size_t StaticSize,
          typename FallbackAllocator = std::allocator<T>>
class VectorBuffer final {
    using Allocator = linear_allocator<T, FallbackAllocator>;
public:
    using vector_type = std::vector<T, Allocator>;

    VectorBuffer() noexcept
        : buffer(),
          alloc(buffer.data(), buffer.size()),
          vector_(alloc) {
        vector_.reserve(buffer.size());
    }

    VectorBuffer(const VectorBuffer&) = delete;
    VectorBuffer(VectorBuffer&&) = delete;
    ~VectorBuffer() = default;

    VectorBuffer& operator= (const VectorBuffer&) = delete;
    VectorBuffer& operator= (VectorBuffer&&) = delete;

    vector_type& vector() noexcept {
        return vector_;
    }

    const vector_type& vector() const noexcept {
        return vector_;
    }
private:
    std::array<T, StaticSize> buffer;
    Allocator alloc;
    std::vector<T, Allocator> vector_;
};

template <size_t StaticSize,
          typename FallbackAllocator = std::allocator<std::byte>>
class MemoryBuffer final {
    using fallback_value_type = typename std::allocator_traits<FallbackAllocator>::value_type;
    static_assert(std::is_same_v<fallback_value_type, std::byte>,
                  "Expected std::byte value type");
public:
    using value_type = std::byte;
    using pointer = std::add_pointer_t<value_type>;
    using const_pointer = std::add_const_t<pointer>;

    MemoryBuffer()
        : buffer(),
          allocator(buffer.data(), buffer.size()),
          ptr(nullptr),
          size_(0)
    {}

    explicit MemoryBuffer(const size_t size)
        : buffer(),
          allocator(buffer.data(), buffer.size()),
          ptr(allocator.allocate(size)),
          size_(size)
    {}

    MemoryBuffer(const MemoryBuffer&) = delete;
    MemoryBuffer(MemoryBuffer&&) = delete;
    ~MemoryBuffer() noexcept = default;

    MemoryBuffer& operator= (const MemoryBuffer&) = delete;
    MemoryBuffer& operator= (MemoryBuffer&&) = delete;

    size_t size() const noexcept {
        return size_;
    }

    bool empty() const noexcept {
        return size_ == 0;
    }

    bool non_empy() const noexcept {
        return size_ != 0;
    }

    pointer data() noexcept {
        return ptr;
    }

    const_pointer data() const noexcept {
        return ptr;
    }

    void resize(const size_t newSize) {
        if (ptr != nullptr) {
            if (allocator.try_reallocate(ptr, size_, newSize)) {
                size_ = newSize;
                return;
            }
            allocator.deallocate(ptr, size_);
        }

        ptr = allocator.allocate(newSize);
        size_ = newSize;
    }
private:
    std::array<std::byte, StaticSize> buffer;
    linear_allocator<std::byte, FallbackAllocator> allocator;
    pointer ptr;
    size_t size_;
};

} // imdex namespace
