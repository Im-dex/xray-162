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

template <typename T, typename Alloc>
void clearAndReserve(std::vector<T, Alloc>& vec) {
    if (vec.capacity() <= (vec.size() / 2))
        vec.clear();
    else {
        vec.shrink_to_fit();
        vec.clear();
    }
}

struct pred_str {
    bool operator()(const char* x, const char* y) const { return std::strcmp(x, y) < 0; }
};
struct pred_stri {
    bool operator()(const char* x, const char* y) const { return _stricmp(x, y) < 0; }
};

#include "FixedVector.h"
#include "buffer_vector.h"

// auxilary definition
using FvectorVec = std::vector<Fvector>;
using LPSTRVec = std::vector<LPSTR>;
using SStringVec = std::vector<std::string>;
using U16Vec = std::vector<u16>;
using U32Vec = std::vector<u32>;
using FloatVec = std::vector<float>;
using IntVec = std::vector<int>;
