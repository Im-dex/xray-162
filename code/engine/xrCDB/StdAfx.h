// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#pragma once

#include "../xrCore/xrCore.h"

#define CNEW(type) new (xr_alloc<type>(1)) type
#define CDELETE(ptr) xr_delete(ptr)
#define CFREE(ptr) xr_free(ptr)
#define CMALLOC(size) xr_malloc(size)
#define CALLOC(type, count) xr_alloc<type>(count)

template <bool _is_pm, typename T>
struct cspecial_free {
    void operator()(T*& ptr) {
        void* _real_ptr = dynamic_cast<void*>(ptr);
        ptr->~T();
        CFREE(_real_ptr);
    }
};

template <typename T>
struct cspecial_free<false, T> {
    void operator()(T*& ptr) {
        ptr->~T();
        CFREE(ptr);
    }
};

template <class T>
void cdelete(T*& ptr) {
    if (ptr) {
        cspecial_free<std::is_polymorphic_v<T>, T>()(ptr);
        ptr = nullptr;
    }
}

#define ENGINE_API
#include "opcode.h"