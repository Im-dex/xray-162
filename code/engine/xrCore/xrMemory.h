#pragma once

class XRCORE_API xrMemory
{
public:
    void _initialize();
    void _destroy();

    u32 mem_usage(u32* pBlocksUsed = NULL, u32* pBlocksFree = NULL);
    void mem_compact();
};

extern XRCORE_API xrMemory Memory;

XRCORE_API void vminfo(size_t* _free, size_t* reserved, size_t* committed);
XRCORE_API void log_vminfo();
XRCORE_API u32 mem_usage_impl(u32* pBlocksUsed, u32* pBlocksFree);

XRCORE_API char* xr_strdup(const char* string);

//#pragma warning(push)
//#pragma warning(disable : 4595) // Warning C4595 'operator new': non - member operator new or delete
//                                // functions may not be declared inline
//
//IC void* operator new(size_t size) { return Memory.mem_alloc(size ? size : 1); }
//IC void operator delete(void* p) { xr_delete(p); }
//IC void* operator new[](size_t size) { return Memory.mem_alloc(size ? size : 1); }
//IC void operator delete[](void* p) { xr_delete(p); }
//
//#pragma warning(pop)

template <class T>
T* xr_alloc(u32 count)
{
    return (T*)malloc(count * sizeof(T));
}

inline void* xr_malloc(size_t size) { return malloc(size); }
inline void* xr_realloc(void* P, size_t size) { return realloc(P, size); }

template <typename T, typename... Args>
T* xr_new(Args&&... args)
{
    return new T(std::forward<Args>(args)...);
}

template <class T>
void xr_delete(T*& ptr)
{
    delete ptr;
    ptr = nullptr;
}

template <class T>
void xr_free(T*& ptr)
{
    free((void*)ptr);
    ptr = nullptr;
}