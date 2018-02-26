#pragma once

#include "allocator_traits.hpp"

namespace imdex {

template <typename T, typename FallbackAllocator = std::allocator<T>>
class linear_allocator final {
    using traits = allocator_traits<FallbackAllocator>;
public:
    linear_allocator(T* begin, const T* end,
                     const FallbackAllocator& alloc = FallbackAllocator())
        noexcept(std::is_nothrow_copy_constructible_v<FallbackAllocator>)
        : begin(begin),
          end(end),
          cur(begin),
          fallback(alloc)
    {}

    linear_allocator(T* buffer, const size_t size,
                     const FallbackAllocator& alloc = FallbackAllocator())
        noexcept(std::is_nothrow_copy_constructible_v<FallbackAllocator>)
        : linear_allocator(buffer, buffer + size, alloc)
    {}

    template <size_t Size>
    linear_allocator(T (&array)[Size])
        noexcept(std::is_nothrow_copy_constructible_v<FallbackAllocator>)
        : linear_allocator(static_cast<T*>(array), Size)
    {}

    template <size_t Size>
    linear_allocator(std::array<T, Size>& array)
        noexcept(std::is_nothrow_copy_constructible_v<FallbackAllocator>)
        : linear_allocator(array.data(), array.size())
    {}

    using value_type = typename traits::value_type;
    using size_type = typename traits::size_type;
    using difference_type = typename traits::difference_type;
    using pointer = typename traits::pointer;
    using propagate_on_container_copy_assignment = std::false_type;
    using propagate_on_container_move_assignment = std::true_type;
    using propagate_on_container_swap = std::false_type;
    using is_always_equal = std::false_type;

    template <typename U, typename Alloc>
    bool operator== (const linear_allocator<U, Alloc>& that) const noexcept {
        return begin == that.begin && fallback == that.fallback;
    }

    template <typename U, typename Alloc>
    bool operator!= (const linear_allocator<U, Alloc>& that) const noexcept {
        return begin != that.begin || fallback != that.fallback;
    }

    [[nodiscard]] T* allocate(const size_type size) {
        if (hasFreeStaticSpace(size)) {
            auto* res = cur;
            cur += size;
            return res;
        } else {
            return fallback.allocate(size);
        }
    }

    [[nodiscard]] bool try_reallocate(T* ptr, const size_type size, const size_type newSize) {
        if (newSize == size)
            return true;

        if (isBufferPtr(ptr)) {
            if (isLastBufferChunk(ptr, size)) {
                if (newSize > size) {
                    const size_type diff = newSize - size;
                    if (hasFreeStaticSpace(diff)) {
                        cur += diff;
                        return true;
                    }
                } else {
                    const size_type diff = size - newSize;
                    cur -= diff;
                    return true;
                }
            }
            return false;
        } else {
            return traits::try_reallocate(fallback, ptr, size, newSize);
        }
    }

    void deallocate(T* ptr, const size_type size) {
        if (isBufferPtr(ptr)) {
            if (isLastBufferChunk(ptr, size)) {
                cur -= size;
            }
        } else {
            fallback.deallocate(ptr, size);
        }
    }
private:
    bool hasFreeStaticSpace(const size_type size) const noexcept {
        return cur + size <= end;
    }

    bool isBufferPtr(T* ptr) const noexcept {
        return ptr >= begin && ptr < end;
    }

    bool isLastBufferChunk(T* ptr, const size_type size) const noexcept {
        return (ptr + size) == cur;
    }

    T* begin;
    const T* end;
    T* cur;
    FallbackAllocator fallback;
};

} // imdex namespace
