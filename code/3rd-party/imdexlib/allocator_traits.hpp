#pragma once

#include <memory>

#include "detection.hpp"
#include "identity.hpp"

namespace imdex {
namespace detail::alloc {

template <typename T>
using value_type_t = typename T::value_type;

template <typename Alloc>
using try_reallocate_t = decltype(std::declval<Alloc>().try_reallocate(
    std::declval<typename std::allocator_traits<Alloc>::pointer>(),
    std::declval<typename std::allocator_traits<Alloc>::size_type>(),
    std::declval<typename std::allocator_traits<Alloc>::size_type>()
));

template <typename Alloc>
struct allocator_traits {
private:
    using traits = std::allocator_traits<Alloc>;
public:
    using allocator_type = typename traits::allocator_type;
    using value_type = typename traits::value_type;
    using pointer = typename traits::pointer;
    using const_pointer = typename traits::const_pointer;
    using void_pointer = typename traits::void_pointer;
    using const_void_pointer = typename traits::const_void_pointer;
    using difference_type = typename traits::difference_type;
    using size_type = typename traits::size_type;
    using propagate_on_container_copy_assignment =
        typename traits::propagate_on_container_copy_assignment;
    using propagate_on_container_move_assignment =
        typename traits::propagate_on_container_move_assignment;
    using propagate_on_container_swap = typename traits::propagate_on_container_swap;
    using is_always_equal = typename traits::is_always_equal;
    // Extra
    using is_support_reallocation = is_detected_exact<bool, try_reallocate_t, Alloc>;

    template <typename T>
    using rebind_alloc = typename traits::template rebind_alloc<T>;

    template <typename T>
    using rebind_traits = typename traits::template rebind_traits<T>;

    static pointer allocate(Alloc& alloc, const size_type count) {
        return traits::allocate(alloc, count);
    }

    static void deallocate(Alloc& alloc, pointer ptr, const size_type count) {
        traits::deallocate(alloc, ptr, count);
    }

    template <typename T, typename... Args>
    static void construct(Alloc& alloc, T* ptr, Args&&... args) {
        return traits::construct(alloc, ptr, std::forward<Args>(args)...);
    }

    template <typename T>
    static void destroy(Alloc& alloc, T* ptr) {
        traits::destroy(alloc, ptr);
    }

    static size_type max_size(Alloc& alloc) {
        return traits::max_size(alloc);
    }

    static Alloc select_on_container_copy_construction(const Alloc& alloc) {
        return traits::select_on_container_copy_construction(alloc);
    }

    // Extra
    static bool try_reallocate(Alloc& alloc, pointer ptr, const size_type size,
                               const size_type newSize) {
        if constexpr (is_support_reallocation::value) {
            return alloc.try_reallocate(ptr, size, newSize);
        }
        return false;
    }
};

} // detail::alloc namespace

template <typename Alloc>
using allocator_traits = typename std::conditional_t<
    is_detected_v<detail::alloc::value_type_t, Alloc>,
    identity<detail::alloc::allocator_traits<Alloc>>,
    identity<std::allocator_traits<Alloc>>
>::type;

} // imdex namespace
