#pragma once

class XRCORE_API xrMemory {
public:
    void _initialize();
    void _destroy();

    u32 mem_usage(u32* pBlocksUsed = NULL, u32* pBlocksFree = NULL);
    void mem_compact();

    void* mem_alloc(size_t size);
    void* mem_realloc(void* p, size_t size);
    void mem_free(void* p);
};

extern XRCORE_API xrMemory Memory;

template <class T>
IC T* xr_alloc(u32 count) {
    return (T*)Memory.mem_alloc(count * sizeof(T));
}
template <class T>
IC void xr_free(T*& P) {
    if (P) {
        Memory.mem_free((void*)P);
        P = NULL;
    };
}
IC void* xr_malloc(size_t size) { return Memory.mem_alloc(size); }
IC void* xr_realloc(void* P, size_t size) { return Memory.mem_realloc(P, size); }

XRCORE_API char* xr_strdup(const char* string);

#pragma warning(push)
#pragma warning(disable : 4595) // Warning C4595 'operator new': non - member operator new or delete
                                // functions may not be declared inline

IC void* operator new(size_t size) { return Memory.mem_alloc(size ? size : 1); }
IC void operator delete(void* p) { xr_free(p); }
IC void* operator new[](size_t size) { return Memory.mem_alloc(size ? size : 1); }
IC void operator delete[](void* p) { xr_free(p); }

#pragma warning(pop)

XRCORE_API void vminfo(size_t* _free, size_t* reserved, size_t* committed);
XRCORE_API void log_vminfo();
XRCORE_API u32 mem_usage_impl(u32* pBlocksUsed, u32* pBlocksFree);

template <typename T, typename... Args>
T* xr_new(Args&&... args) {
    T* ptr = static_cast<T*>(Memory.mem_alloc(sizeof(T)));
    return new (ptr) T(std::forward<Args>(args)...);
}

template <bool _is_pm, typename T>
struct xr_special_free {
    IC void operator()(T*& ptr) {
        void* _real_ptr = dynamic_cast<void*>(ptr);
        ptr->~T();
        Memory.mem_free(_real_ptr);
    }
};

template <typename T>
struct xr_special_free<false, T> {
    IC void operator()(T*& ptr) {
        ptr->~T();
        Memory.mem_free(ptr);
    }
};

template <class T>
IC void xr_delete(T*& ptr) {
    if (ptr) {
        xr_special_free<std::is_polymorphic_v<T>, T>()(ptr);
        ptr = NULL;
    }
}
template <class T>
IC void xr_delete(T* const& ptr) {
    if (ptr) {
        xr_special_free<std::is_polymorphic_v<T>, T>(ptr);
        const_cast<T*&>(ptr) = NULL;
    }
}