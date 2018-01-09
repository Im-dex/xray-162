#include "stdafx.h"

#include "xrsharedmem.h"

xrMemory Memory;
bool shared_str_initialized = false;

// fake fix of memory corruptions in multiplayer game :(
XRCORE_API bool g_allow_heap_min = true;

void xrMemory::_initialize() {
    g_pStringContainer = new str_container();
    shared_str_initialized = true;
    g_pSharedMemoryContainer = new smem_container();
}

void xrMemory::_destroy() {
    xr_delete(g_pSharedMemoryContainer);
    shared_str_initialized = false;
    xr_delete(g_pStringContainer);
}

void xrMemory::mem_compact() {
    RegFlushKey(HKEY_CLASSES_ROOT);
    RegFlushKey(HKEY_CURRENT_USER);
    if (g_allow_heap_min)
        _heapmin();
    HeapCompact(GetProcessHeap(), 0);
    if (g_pStringContainer)
        g_pStringContainer->clean();
    if (g_pSharedMemoryContainer)
        g_pSharedMemoryContainer->clean();
    if (strstr(Core.Params, "-swap_on_compact"))
        SetProcessWorkingSetSize(GetCurrentProcess(), size_t(-1), size_t(-1));
}

// xr_strdup
char* xr_strdup(const char* string) {
    VERIFY(string);
    u32 len = u32(xr_strlen(string)) + 1;
    char* memory = (char*)xr_malloc(len);
    std::memcpy(memory, string, len);
    return memory;
}
