#include "stdafx.h"

#include "xrsharedmem.h"
#include "xrMemory_pure.h"
#include "xrMemory_align.h"

#include <malloc.h>

xrMemory Memory;
bool mem_initialized = false;
bool shared_str_initialized = false;

// fake fix of memory corruptions in multiplayer game :(
XRCORE_API bool g_allow_heap_min = true;

#ifdef DEBUG_MEMORY_MANAGER
XRCORE_API void dump_phase() {
    if (!Memory.debug_mode)
        return;

    static int phase_counter = 0;

    string256 temp;
    xr_sprintf(temp, sizeof(temp), "x:\\$phase$%d.dump", ++phase_counter);
    Memory.mem_statistic(temp);
}
#endif // DEBUG_MEMORY_MANAGER

xrMemory::xrMemory() {
#ifdef DEBUG_MEMORY_MANAGER

    debug_mode = false;

#endif // DEBUG_MEMORY_MANAGER
}

#ifdef DEBUG_MEMORY_MANAGER
BOOL g_bMEMO = FALSE;
#endif // DEBUG_MEMORY_MANAGER

void xrMemory::_initialize(bool bDebug) {
#ifdef DEBUG_MEMORY_MANAGER
    debug_mode = bDebug;
    debug_info_update = 0;
#endif // DEBUG_MEMORY_MANAGER

    stat_calls = 0;
    stat_counter = 0;

    if (!strstr(Core.Params, "-pure_alloc")) {
        // initialize POOLs
        u32 element = mem_pools_ebase;
        u32 sector = mem_pools_ebase * 1024;
        for (u32 pid = 0; pid < mem_pools_count; pid++) {
            mem_pools[pid]._initialize(element, sector, 0x1);
            element += mem_pools_ebase;
        }
    }

#ifdef DEBUG_MEMORY_MANAGER
    if (0 == strstr(Core.Params, "-memo"))
        mem_initialized = true;
    else
        g_bMEMO = TRUE;
#else  // DEBUG_MEMORY_MANAGER
    mem_initialized = true;
#endif // DEBUG_MEMORY_MANAGER

    //	DUMP_PHASE;
    g_pStringContainer = xr_new<str_container>();
    shared_str_initialized = true;
    //	DUMP_PHASE;
    g_pSharedMemoryContainer = xr_new<smem_container>();
    //	DUMP_PHASE;
}

#ifdef DEBUG_MEMORY_MANAGER
extern void dbg_dump_leaks();
extern void dbg_dump_str_leaks();
#endif // DEBUG_MEMORY_MANAGER

void xrMemory::_destroy() {
#ifdef DEBUG_MEMORY_MANAGER
    mem_alloc_gather_stats(false);
    mem_alloc_show_stats();
    mem_alloc_clear_stats();
#endif // DEBUG

#ifdef DEBUG_MEMORY_MANAGER
    if (debug_mode)
        dbg_dump_str_leaks();
#endif // DEBUG_MEMORY_MANAGER

    xr_delete(g_pSharedMemoryContainer);
    xr_delete(g_pStringContainer);

#ifdef DEBUG_MEMORY_MANAGER
    if (debug_mode)
        dbg_dump_leaks();
#endif // DEBUG_MEMORY_MANAGER

    mem_initialized = false;
#ifdef DEBUG_MEMORY_MANAGER
    debug_mode = false;
#endif // DEBUG_MEMORY_MANAGER
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

#ifdef DEBUG_MEMORY_MANAGER
ICF u8* acc_header(void* P) {
    u8* _P = (u8*)P;
    return _P - 1;
}
ICF u32 get_header(void* P) { return (u32)*acc_header(P); }
void xrMemory::mem_statistic(LPCSTR fn) {
    if (!debug_mode)
        return;
    mem_compact();

    debug_cs.lock();
    debug_mode = false;

    FILE* Fa = fopen(fn, "w");
    fprintf(Fa, "$BEGIN CHUNK #0\n");
    fprintf(Fa, "POOL: %d %dKb\n", mem_pools_count, mem_pools_ebase);

    fprintf(Fa, "$BEGIN CHUNK #1\n");
    for (u32 k = 0; k < mem_pools_count; ++k)
        fprintf(Fa, "%2d: %d %db\n", k, mem_pools[k].get_block_count(), (k + 1) * 16);

    fprintf(Fa, "$BEGIN CHUNK #2\n");
    for (u32 it = 0; it < debug_info.size(); it++) {
        if (0 == debug_info[it]._p)
            continue;

        u32 p_current = get_header(debug_info[it]._p);
        int pool_id = (mem_generic == p_current) ? -1 : p_current;

        fprintf(Fa, "0x%08X[%2d]: %8d %s\n", *(u32*)(&debug_info[it]._p), pool_id,
                debug_info[it]._size, debug_info[it]._name);
    }

    {
        for (u32 k = 0; k < mem_pools_count; ++k) {
            MEMPOOL& pool = mem_pools[k];
            u8* list = pool.list;
            while (list) {
                pool.cs.Enter();
                u32 temp = *(u32*)(&list);
                if (!temp)
                    break;
                fprintf(Fa, "0x%08X[%2d]: %8d mempool\n", temp, k, pool.s_element);
                list = (u8*)*pool.access(list);
                pool.cs.Leave();
            }
        }
    }

    /*
    fprintf					(Fa,"$BEGIN CHUNK #3\n");
    for (u32 it=0; it<debug_info.size(); it++)
    {
            if (0==debug_info[it]._p)	continue	;
            try{
                    if (0==strcmp(debug_info[it]._name,"storage: sstring"))
                            fprintf		(Fa,"0x%08X: %8d %s
    %s\n",*(u32*)(&debug_info[it]._p),debug_info[it]._size,debug_info[it]._name,((str_value*)(*(u32*)(&debug_info[it]._p)))->value);
            }catch(...){
            }
    }
    */

    fclose(Fa);

    // leave
    debug_mode = true;
    debug_cs.unlock();

    /*
    mem_compact				();
    LPCSTR					fn	= "$memstat$.tmp";
    xr_map<u32,u32>			stats;

    if (g_pStringContainer)			Msg	("memstat: shared_str: economy: %d
    bytes",g_pStringContainer->stat_economy()); if (g_pSharedMemoryContainer)	Msg
    ("memstat: shared_mem: economy: %d bytes",g_pSharedMemoryContainer->stat_economy());

    // Dump memory stats into file to avoid reallocation while traversing
    {
            IWriter*	F		= FS.w_open(fn);
            F->w_u32			(0);
            _HEAPINFO			hinfo;
            int					heapstatus;
            hinfo._pentry		= NULL;
            while( ( heapstatus = _heapwalk( &hinfo ) ) == _HEAPOK )
                    if (hinfo._useflag == _USEDENTRY)	F->w_u32	(u32(hinfo._size));
            FS.w_close			(F);
    }

    // Read back and perform sorting
    {
            IReader*	F		= FS.r_open	(fn);
            u32 size			= F->r_u32	();
            while (!F->eof())
            {
                    size						= F->r_u32	();
                    xr_map<u32,u32>::iterator I	= stats.find(size);
                    if (I!=stats.end())			I->second += 1;
                    else
    stats.insert(std::make_pair(size,1));
            }
            FS.r_close			(F);
            FS.file_delete		(fn);
    }

    // Output to log
    {
            xr_map<u32,u32>::iterator I		= stats.begin();
            xr_map<u32,u32>::iterator E		= stats.end();
            for (; I!=E; I++)	Msg			("%8d : %-4d
    [%d]",I->first,I->second,I->first*I->second);
    }
    */
}
#endif // DEBUG_MEMORY_MANAGER

// xr_strdup
char* xr_strdup(const char* string) {
    VERIFY(string);
    u32 len = u32(xr_strlen(string)) + 1;
    char* memory = (char*)Memory.mem_alloc(len
#ifdef DEBUG_MEMORY_NAME
                                           ,
                                           "strdup"
#endif // DEBUG_MEMORY_NAME
    );
    std::memcpy(memory, string, len);
    return memory;
}

XRCORE_API bool is_stack_ptr(void* _ptr) {
    int local_value = 0;
    void* ptr_refsound = _ptr;
    void* ptr_local = &local_value;
    ptrdiff_t difference = (ptrdiff_t)xr::abs(s64(ptrdiff_t(ptr_local) - ptrdiff_t(ptr_refsound)));
    return (difference < (512 * 1024));
}


#ifdef DEBUG_MEMORY_MANAGER
XRCORE_API void* g_globalCheckAddr = NULL;
extern void save_stack_trace();
#else
#define debug_mode 0
#endif // DEBUG_MEMORY_MANAGER

MEMPOOL mem_pools[mem_pools_count];

// MSVC
ICF u8* acc_header(void* P) {
    u8* _P = (u8*)P;
    return _P - 1;
}
ICF u32 get_header(void* P) { return (u32)*acc_header(P); }
ICF u32 get_pool(size_t size) {
    u32 pid = u32(size / mem_pools_ebase);
    if (pid >= mem_pools_count)
        return mem_generic;
    else
        return pid;
}

#ifdef PURE_ALLOC
bool g_use_pure_alloc = false;
#endif // PURE_ALLOC

void* xrMemory::mem_alloc(size_t size) {
    stat_calls++;

#ifdef PURE_ALLOC
    static bool g_use_pure_alloc_initialized = false;
    if (!g_use_pure_alloc_initialized) {
        g_use_pure_alloc_initialized = true;
        g_use_pure_alloc =
#ifdef XRCORE_STATIC
            true
#else  // XRCORE_STATIC
            !!strstr(GetCommandLine(), "-pure_alloc")
#endif // XRCORE_STATIC
            ;
    }

    if (g_use_pure_alloc) {
        void* result = malloc(size);
#ifdef USE_MEMORY_MONITOR
        memory_monitor::monitor_alloc(result, size, _name);
#endif // USE_MEMORY_MONITOR
        return (result);
    }
#endif // PURE_ALLOC

#ifdef DEBUG_MEMORY_MANAGER
    if (mem_initialized)
        debug_cs.Enter();
#endif // DEBUG_MEMORY_MANAGER

    u32 _footer = debug_mode ? 4 : 0;
    void* _ptr = 0;

    //
    if (!mem_initialized /*|| debug_mode*/) {
        // generic
        //	Igor: Reserve 1 byte for xrMemory header
        void* _real = xr_aligned_offset_malloc(1 + size + _footer, 16, 0x1);
        // void*	_real			=	xr_aligned_offset_malloc	(size + _footer,
        // 16, 0x1);
        _ptr = (void*)(((u8*)_real) + 1);
        *acc_header(_ptr) = mem_generic;
    } else {
#ifdef DEBUG_MEMORY_MANAGER
        save_stack_trace();
#endif // DEBUG
       //	accelerated
       //	Igor: Reserve 1 byte for xrMemory header
        u32 pool = get_pool(1 + size + _footer);
        // u32	pool				=	get_pool	(size+_footer);
        if (mem_generic == pool) {
            // generic
            //	Igor: Reserve 1 byte for xrMemory header
            void* _real = xr_aligned_offset_malloc(1 + size + _footer, 16, 0x1);
            // void*	_real		=	xr_aligned_offset_malloc	(size +
            // _footer,16,0x1);
            _ptr = (void*)(((u8*)_real) + 1);
            *acc_header(_ptr) = mem_generic;
        } else {
            // pooled
            //	Igor: Reserve 1 byte for xrMemory header
            //	Already reserved when getting pool id
            void* _real = mem_pools[pool].create();
            _ptr = (void*)(((u8*)_real) + 1);
            *acc_header(_ptr) = (u8)pool;
        }
    }

#ifdef DEBUG_MEMORY_MANAGER
    if (debug_mode)
        dbg_register(_ptr, size, _name);
    if (mem_initialized)
        debug_cs.Leave();
        // if(g_globalCheckAddr==_ptr){
        //	__debugbreak();
        //}
        // if (_name && (0==strcmp(_name,"class ISpatial *")) && (size==376))
        //{
        //	__debugbreak();
        //}
#endif // DEBUG_MEMORY_MANAGER
#ifdef USE_MEMORY_MONITOR
    memory_monitor::monitor_alloc(_ptr, size, _name);
#endif // USE_MEMORY_MONITOR
    return _ptr;
}

void xrMemory::mem_free(void* P) {
    stat_calls++;
#ifdef USE_MEMORY_MONITOR
    memory_monitor::monitor_free(P);
#endif // USE_MEMORY_MONITOR

#ifdef PURE_ALLOC
    if (g_use_pure_alloc) {
        free(P);
        return;
    }
#endif // PURE_ALLOC

#ifdef DEBUG_MEMORY_MANAGER
    if (g_globalCheckAddr == P)
        __debugbreak();
#endif // DEBUG_MEMORY_MANAGER

#ifdef DEBUG_MEMORY_MANAGER
    if (mem_initialized)
        debug_cs.Enter();
#endif // DEBUG_MEMORY_MANAGER
    if (debug_mode)
        dbg_unregister(P);
    u32 pool = get_header(P);
    void* _real = (void*)(((u8*)P) - 1);
    if (mem_generic == pool) {
        // generic
        xr_aligned_free(_real);
    } else {
        // pooled
        VERIFY2(pool < mem_pools_count, "Memory corruption");
        mem_pools[pool].destroy(_real);
    }
#ifdef DEBUG_MEMORY_MANAGER
    if (mem_initialized)
        debug_cs.Leave();
#endif // DEBUG_MEMORY_MANAGER
}

extern BOOL g_bDbgFillMemory;

void* xrMemory::mem_realloc(void* P, size_t size) {
    stat_calls++;
#ifdef PURE_ALLOC
    if (g_use_pure_alloc) {
        void* result = realloc(P, size);
#ifdef USE_MEMORY_MONITOR
        memory_monitor::monitor_free(P);
        memory_monitor::monitor_alloc(result, size, _name);
#endif // USE_MEMORY_MONITOR
        return (result);
    }
#endif // PURE_ALLOC
    if (0 == P) {
        return mem_alloc(size
#ifdef DEBUG_MEMORY_NAME
                         ,
                         _name
#endif // DEBUG_MEMORY_NAME
        );
    }

#ifdef DEBUG_MEMORY_MANAGER
    if (g_globalCheckAddr == P)
        __debugbreak();
#endif // DEBUG_MEMORY_MANAGER

#ifdef DEBUG_MEMORY_MANAGER
    if (mem_initialized)
        debug_cs.Enter();
#endif // DEBUG_MEMORY_MANAGER
    u32 p_current = get_header(P);
    //	Igor: Reserve 1 byte for xrMemory header
    u32 p_new = get_pool(1 + size + (debug_mode ? 4 : 0));
    // u32		p_new				= get_pool	(size+(debug_mode?4:0));
    u32 p_mode;

    if (mem_generic == p_current) {
        if (p_new < p_current)
            p_mode = 2;
        else
            p_mode = 0;
    } else
        p_mode = 1;

    void* _real = (void*)(((u8*)P) - 1);
    void* _ptr = NULL;
    if (0 == p_mode) {
        u32 _footer = debug_mode ? 4 : 0;
#ifdef DEBUG_MEMORY_MANAGER
        if (debug_mode) {
            g_bDbgFillMemory = false;
            dbg_unregister(P);
            g_bDbgFillMemory = true;
        }
#endif // DEBUG_MEMORY_MANAGER
       //	Igor: Reserve 1 byte for xrMemory header
        void* _real2 = xr_aligned_offset_realloc(_real, 1 + size + _footer, 16, 0x1);
        // void*	_real2			=	xr_aligned_offset_realloc
        // (_real,size+_footer,16,0x1);
        _ptr = (void*)(((u8*)_real2) + 1);
        *acc_header(_ptr) = mem_generic;
#ifdef DEBUG_MEMORY_MANAGER
        if (debug_mode)
            dbg_register(_ptr, size, _name);
#endif // DEBUG_MEMORY_MANAGER
#ifdef USE_MEMORY_MONITOR
        memory_monitor::monitor_free(P);
        memory_monitor::monitor_alloc(_ptr, size, _name);
#endif // USE_MEMORY_MONITOR
    } else if (1 == p_mode) {
        // pooled realloc
        R_ASSERT2(p_current < mem_pools_count, "Memory corruption");
        u32 s_current = mem_pools[p_current].get_element();
        u32 s_dest = (u32)size;
        void* p_old = P;

        void* p_new = mem_alloc(size
#ifdef DEBUG_MEMORY_NAME
                                ,
                                _name
#endif // DEBUG_MEMORY_NAME
        );
        //	Igor: Reserve 1 byte for xrMemory header
        //	Don't bother in this case?
        std::memcpy(p_new, p_old, std::min(s_current - 1, s_dest));
        // mem_copy				(p_new,p_old,_min(s_current,s_dest));
        mem_free(p_old);
        _ptr = p_new;
    } else if (2 == p_mode) {
        // relocate into another mmgr(pooled) from real
        void* p_old = P;
        void* p_new = mem_alloc(size
#ifdef DEBUG_MEMORY_NAME
                                ,
                                _name
#endif // DEBUG_MEMORY_NAME
        );
        std::memcpy(p_new, p_old, size);
        mem_free(p_old);
        _ptr = p_new;
    }

#ifdef DEBUG_MEMORY_MANAGER
    if (mem_initialized)
        debug_cs.Leave();

    if (g_globalCheckAddr == _ptr)
        __debugbreak();
#endif // DEBUG_MEMORY_MANAGER

    return _ptr;
}