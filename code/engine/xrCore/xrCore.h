#pragma once

#include <xr_config.h>

#ifndef DEBUG
#define MASTER_GOLD
#endif // DEBUG

//#define BENCHMARK_BUILD

#ifdef BENCHMARK_BUILD
#define BENCH_SEC_CALLCONV __stdcall
#define BENCH_SEC_SCRAMBLEVTBL1 \
    virtual int GetFlags() { return 1; }
#define BENCH_SEC_SCRAMBLEVTBL2 \
    virtual void* GetData() { return 0; }
#define BENCH_SEC_SCRAMBLEVTBL3 \
    virtual void* GetCache() { return 0; }
#define BENCH_SEC_SIGN , void* pBenchScrampleVoid = 0
#define BENCH_SEC_SCRAMBLEMEMBER1 float m_fSrambleMember1;
#define BENCH_SEC_SCRAMBLEMEMBER2 float m_fSrambleMember2;
#else //	BENCHMARK_BUILD
#define BENCH_SEC_CALLCONV
#define BENCH_SEC_SCRAMBLEVTBL1
#define BENCH_SEC_SCRAMBLEVTBL2
#define BENCH_SEC_SCRAMBLEVTBL3
#define BENCH_SEC_SIGN
#define BENCH_SEC_SCRAMBLEMEMBER1
#define BENCH_SEC_SCRAMBLEMEMBER2
#endif //	BENCHMARK_BUILD

#pragma warning(disable : 4996)

#if (defined(_DEBUG) || defined(MIXED) || defined(DEBUG)) && !defined(FORCE_NO_EXCEPTIONS)
// "debug" or "mixed"
#if !defined(_CPPUNWIND)
#error Please enable exceptions...
#endif
#define _HAS_EXCEPTIONS 1 // STL
#define XRAY_EXCEPTIONS 1 // XRAY

#define XR_NOEXCEPT noexcept
#define XR_NOEXCEPT_OP(x) noexcept(x)
#else
// "release"
#if defined(_CPPUNWIND) && !defined __BORLANDC__
#error Please disable exceptions...
#endif
#ifdef _HAS_EXCEPTIONS
#undef _HAS_EXCEPTIONS
#endif
#define _HAS_EXCEPTIONS 0 // STL
#define XRAY_EXCEPTIONS 0 // XRAY
#define LUABIND_NO_EXCEPTIONS
#pragma warning(disable : 4530)

#define XR_NOEXCEPT throw()
#define XR_NOEXCEPT_OP(x)
#endif

#if !defined(_MT)
// multithreading disabled
#error Please enable multi-threaded library...
#endif

#include "xrCore_platform.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <string.h>
#include <typeinfo.h>

#ifndef DEBUG
#ifdef _DEBUG
#define DEBUG
#endif
#ifdef MIXED
#define DEBUG
#endif
#endif

// inline control - redefine to use compiler's heuristics ONLY
// it seems "IC" is misused in many places which cause code-bloat
// ...and VC7.1 really don't miss opportunities for inline :)
#define _inline inline
#define __inline inline
#define IC inline
#define ICF inline
#define ICN __declspec(noinline)

#ifndef DEBUG
#pragma inline_depth(254)
#pragma inline_recursion(on)
#pragma intrinsic(abs, fabs, fmod, sin, cos, tan, asin, acos, atan, sqrt, exp, log, log10, strcat)
#endif

#include <time.h>
#include <sys\utime.h>
#define MODULE_NAME "xrCore.dll"

// Warnings
#pragma warning(disable : 4251) // object needs DLL interface
#pragma warning(disable : 4201) // nonstandard extension used : nameless struct/union
#pragma warning(disable : 4100) // unreferenced formal parameter
#pragma warning(disable : 4127) // conditional expression is constant
//#pragma warning (disable : 4530 )		// C++ exception handler used, but unwind semantics
//are not enabled
#pragma warning(disable : 4345)
#ifndef DEBUG
#pragma warning(disable : 4189) //  local variable is initialized but not refenced
#endif                          //	frequently in release code due to large amount of VERIFY

#ifdef _M_AMD64
#pragma warning(disable : 4512)
#endif

// stl
#pragma warning(push)
#pragma warning(disable : 4702)
#include <algorithm>
#include <limits>
#include <vector>
#include <stack>
#include <list>
#include <set>
#include <array>
#include <map>
#include <mutex>
#include <filesystem>
#include <cinttypes>
#include <chrono>

#include <unordered_map>
#include <unordered_set>

#include <string>
#include <string_view>
#pragma warning(pop)
#pragma warning(disable : 4100) // unreferenced formal parameter

namespace stdfs = std::experimental::filesystem;
using namespace std::string_view_literals;

// Our headers
#ifdef XRCORE_EXPORTS
#define XRCORE_API __declspec(dllexport)
#else
#define XRCORE_API __declspec(dllimport)
#endif

#include "xrDebug.h"
#define FMT_THROW(x) R_ASSERT2(false, "format failed")
#include <fmtlib/fmt/format.h>
#include <fmtlib/fmt/string.h>

#include "xr_writer.h"
#include "make_string.h"
#include "vector.h"
#include "conv.h"

#include "clsid.h"
#include "xrMemory.h"
#include "xrDebug.h"

#include "_stl_extensions.h"
#include "xrsharedmem.h"
#include "xrstring.h"
#include "xr_resource.h"
#include "rt_compressor.h"
#include "xr_shared.h"
#include "string_concatenations.h"

// stl ext
struct XRCORE_API xr_rtoken {
    std::string name;
    int id;
    xr_rtoken(const std::string_view nm, const int id) : name(nm), id(id) {}

    void rename(const std::string_view nm) { name = nm; }
    bool equal(const std::string_view nm) const { return name == nm; }
};

#pragma pack(push, 1)
struct XRCORE_API xr_shortcut {
    enum {
        flShift = 0x20,
        flCtrl = 0x40,
        flAlt = 0x80,
    };
    union {
        struct {
            u8 key;
            Flags8 ext;
        };
        u16 hotkey;
    };
    xr_shortcut(u8 k, bool a, bool c, bool s) : key(k) {
        ext.assign(u8((a ? flAlt : 0) | (c ? flCtrl : 0) | (s ? flShift : 0)));
    }
    xr_shortcut() {
        ext.zero();
        key = 0;
    }
    bool similar(const xr_shortcut& v) const { return ext.equal(v.ext) && (key == v.key); }
};
#pragma pack(pop)

using RStringVec = xr_vector<std::string>;
using RStringSet = xr_set<shared_str>;
using RTokenVec = xr_vector<xr_rtoken>;

#define xr_pure_interface __interface

#include "FS.h"
#include "log.h"
#include "xr_trims.h"
#include "xr_ini.h"
#ifdef NO_FS_SCAN
#include "ELocatorAPI.h"
#else
#include "LocatorAPI.h"
#endif
#include "FileSystem.h"
#include "FTimer.h"
#include "fastdelegate.h"
#include "intrusive_ptr.h"

#include "net_utils.h"

// destructor
template <class T>
class destructor {
    T* ptr;

public:
    destructor(T* p) { ptr = p; }
    ~destructor() { xr_delete(ptr); }
    T& operator()() { return *ptr; }
};

// ********************************************** The Core definition
class XRCORE_API xrCore {
public:
    string64 ApplicationName;
    string_path ApplicationPath;
    string_path WorkingPath;
    string64 UserName;
    string64 CompName;
    string512 Params;
    DWORD dwFrame;

    void _initialize(const char* ApplicationName, LogCallback cb = nullptr, bool init_fs = true,
                     const char* fs_fname = nullptr);
    void _destroy();
};

extern XRCORE_API xrCore Core;
