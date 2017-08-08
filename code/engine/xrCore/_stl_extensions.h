#pragma once

#include <memory>

using std::swap;

template <typename T>
class xalloc {
public:
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    using value_type = T;

    template <class Other>
    struct rebind {
        using other = xalloc<Other>;
    };

    pointer address(reference ref) const { return &ref; }
    const_pointer address(const_reference ref) const { return &ref; }

    xalloc() = default;
    xalloc(const xalloc<T>&) = default;

    template <class Other>
    xalloc(const xalloc<Other>&) {}

    template <class Other>
    xalloc& operator=(const xalloc<Other>&) {
        return *this;
    }

    pointer allocate(const size_type n, const void* p = nullptr) const { return xr_alloc<T>(n); }

    void deallocate(pointer p, const size_type) const { xr_free(p); }

    void deallocate(void* p, const size_type) const { xr_free(p); }

    void construct(pointer p, const T& _Val) { new (p) T(_Val); }

    void destroy(pointer p) { p->~T(); }

    size_type max_size() const {
        const auto count = std::numeric_limits<size_type>::max() / sizeof(T);
        return 0 < count ? count : 1;
    }
};

struct xr_allocator {
    template <typename T>
    struct helper {
        using result = xalloc<T>;
    };

    static void* alloc(const size_t n) { return xr_malloc(n); }

    template <typename T>
    static void dealloc(T*& p) {
        xr_free(p);
    }
};

template <class T, class Other>
bool operator==(const xalloc<T>&, const xalloc<Other>&) {
    return true;
}

template <class T, class Other>
bool operator!=(const xalloc<T>&, const xalloc<Other>&) {
    return false;
}

namespace std {

template <class Tp1, class Tp2>
xalloc<Tp2>& __stl_alloc_rebind(xalloc<Tp1>& a, const Tp2*) {
    return (xalloc<Tp2>&)(a);
}

template <class Tp1, class Tp2>
xalloc<Tp2> __stl_alloc_create(xalloc<Tp1>&, const Tp2*) {
    return xalloc<Tp2>();
}

} // namespace std

// string(char)
using xr_string = std::basic_string<char, std::char_traits<char>, xalloc<char>>;

// vector
template <typename T, typename allocator = xalloc<T>>
using xr_vector = std::vector<T, allocator>;

template <typename T, typename Alloc>
void clearAndReserve(xr_vector<T, Alloc>& vec) {
    if (vec.capacity() <= (vec.size() / 2))
        vec.clear();
    else {
        vec.shrink_to_fit();
        vec.clear();
    }
}

// deque
template <typename T, typename allocator = xalloc<T>>
using xr_deque = std::deque<T, allocator>;

// stack
template <typename T, class C = xr_deque<T>>
using xr_stack = std::stack<T, C>;

template <typename T, typename allocator = xalloc<T>>
using xr_list = std::list<T, allocator>;

template <typename K, class P = std::less<K>, typename allocator = xalloc<K>>
using xr_set = std::set<K, P, allocator>;

template <typename K, class P = std::less<K>, typename allocator = xalloc<K>>
using xr_multiset = std::multiset<K, P, allocator>;

template <typename K, class V, class P = std::less<K>, typename allocator = xalloc<std::pair<K, V>>>
using xr_map = std::map<K, V, P, allocator>;

template <typename K, class V, class P = std::less<K>, typename allocator = xalloc<std::pair<K, V>>>
using xr_multimap = std::multimap<K, V, P, allocator>;

template <typename K, class V, class Traits = std::equal_to<K>,
          typename allocator = xalloc<std::pair<K, V>>>
using xr_hash_map = std::unordered_map<K, V, std::hash<K>, Traits, allocator>;

struct pred_str {
    bool operator()(const char* x, const char* y) const { return std::strcmp(x, y) < 0; }
};
struct pred_stri {
    bool operator()(const char* x, const char* y) const { return _stricmp(x, y) < 0; }
};

#include "FixedVector.h"
#include "buffer_vector.h"

// auxilary definition
using FvectorVec = xr_vector<Fvector>;
using LPSTRVec = xr_vector<LPSTR>;
using SStringVec = xr_vector<xr_string>;
using U16Vec = xr_vector<u16>;
using U32Vec = xr_vector<u32>;
using FloatVec = xr_vector<float>;
using IntVec = xr_vector<int>;
