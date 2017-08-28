#include "stdafx.h"

#include <process.h>
#include <powerbase.h>

// mmsystem.h
#define MMNOSOUND
#define MMNOMIDI
#define MMNOAUX
#define MMNOMIXER
#define MMNOJOY
#include <mmsystem.h>

typedef struct _PROCESSOR_POWER_INFORMATION {
    ULONG Number;
    ULONG MaxMhz;
    ULONG CurrentMhz;
    ULONG MhzLimit;
    ULONG MaxIdleState;
    ULONG CurrentIdleState;
} PROCESSOR_POWER_INFORMATION, *PPROCESSOR_POWER_INFORMATION;

// Initialized on startup
XRCORE_API Fmatrix Fidentity;
XRCORE_API Dmatrix Didentity;
XRCORE_API CRandom Random;

#ifdef _M_AMD64

namespace FPU {
XRCORE_API void m24() {
    _control87(_RC_CHOP, MCW_RC);
}
XRCORE_API void m24r() {
    _control87(_RC_NEAR, MCW_RC);
}
XRCORE_API void m53() {
    _control87(_RC_CHOP, MCW_RC);
}
XRCORE_API void m53r() {
    _control87(_RC_NEAR, MCW_RC);
}
XRCORE_API void m64() {
    _control87(_RC_CHOP, MCW_RC);
}
XRCORE_API void m64r() {
    _control87(_RC_NEAR, MCW_RC);
}

#else
u16 getFPUsw() {
    u16 SW;
    __asm fstcw SW;
    return SW;
}

namespace FPU {
static u16 _24 = 0;
static u16 _24r = 0;
static u16 _53 = 0;
static u16 _53r = 0;
static u16 _64 = 0;
static u16 _64r = 0;

XRCORE_API void m24() {
    u16 p = _24;
    __asm fldcw p;
}
XRCORE_API void m24r() {
    u16 p = _24r;
    __asm fldcw p;
}
XRCORE_API void m53() {
    u16 p = _53;
    __asm fldcw p;
}
XRCORE_API void m53r() {
    u16 p = _53r;
    __asm fldcw p;
}
XRCORE_API void m64() {
    u16 p = _64;
    __asm fldcw p;
}
XRCORE_API void m64r() {
    u16 p = _64r;
    __asm fldcw p;
}

#endif

void initialize() {
    _clear87();

#ifdef _M_IX86
    _control87(_PC_24, MCW_PC);
    _control87(_RC_CHOP, MCW_RC);
    _24 = getFPUsw(); // 24, chop
    _control87(_RC_NEAR, MCW_RC);
    _24r = getFPUsw(); // 24, rounding

    _control87(_PC_53, MCW_PC);
    _control87(_RC_CHOP, MCW_RC);

    _53 = getFPUsw(); // 53, chop
    _control87(_RC_NEAR, MCW_RC);
    _53r = getFPUsw(); // 53, rounding

    _control87(_PC_64, MCW_PC);
    _control87(_RC_CHOP, MCW_RC);
    _64 = getFPUsw(); // 64, chop

    _control87(_RC_NEAR, MCW_RC);
    _64r = getFPUsw(); // 64, rounding
#endif

    m24r();

    ::Random.seed(u32(CPU::GetCLK() % (1i64 << 32i64)));
}
} // namespace FPU

namespace CPU {
XRCORE_API u64 qpc_freq = []{ 
    u64 result;
    QueryPerformanceCounter(PLARGE_INTEGER(&result));
    return result; 
}();

XRCORE_API u32 qpc_counter = 0;

XRCORE_API processor_info ID;

XRCORE_API u64 QPC() {
    u64 _dest;
    QueryPerformanceCounter(PLARGE_INTEGER(&_dest));
    qpc_counter++;
    return _dest;
}

void Detect() {
    // General CPU identification
    if (!query_processor_info(&ID)) {
        // Core.Fatal		("Fatal error: can't detect CPU/FPU.");
        abort();
    }
}

} // namespace CPU

bool g_initialize_cpu_called = false;

//------------------------------------------------------------------------------------
void _initialize_cpu() {
    Msg("* Detected CPU: %s [%s], F%d/M%d/S%d, 'rdtsc'", CPU::ID.modelName,
        CPU::ID.vendor, CPU::ID.family, CPU::ID.model, CPU::ID.stepping);

    string256 features;
    xr_strcpy(features, sizeof(features), "RDTSC");
    if (CPU::ID.hasFeature(CpuFeature::Mmx))
        xr_strcat(features, ", MMX");
    if (CPU::ID.hasFeature(CpuFeature::_3dNow))
        xr_strcat(features, ", 3DNow!");
    if (CPU::ID.hasFeature(CpuFeature::Sse))
        xr_strcat(features, ", SSE");
    if (CPU::ID.hasFeature(CpuFeature::Sse2))
        xr_strcat(features, ", SSE2");
    if (CPU::ID.hasFeature(CpuFeature::Sse3))
        xr_strcat(features, ", SSE3");
    if (CPU::ID.hasFeature(CpuFeature::MWait))
        xr_strcat(features, ", MONITOR/MWAIT");
    if (CPU::ID.hasFeature(CpuFeature::Ssse3))
        xr_strcat(features, ", SSSE3");
    if (CPU::ID.hasFeature(CpuFeature::Sse41))
        xr_strcat(features, ", SSE4.1");
    if (CPU::ID.hasFeature(CpuFeature::Sse42))
        xr_strcat(features, ", SSE4.2");
    if (CPU::ID.hasFeature(CpuFeature::HT))
        xr_strcat(features, ", HTT");

    Msg("* CPU features: %s", features);
    Msg("* CPU cores/threads: %d/%d", CPU::ID.n_cores, CPU::ID.n_threads);

    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    const size_t cpusCount = sysInfo.dwNumberOfProcessors;

    xr_vector<PROCESSOR_POWER_INFORMATION> cpusInfo(cpusCount);
    CallNtPowerInformation(ProcessorInformation, nullptr, 0, cpusInfo.data(),
                           sizeof(PROCESSOR_POWER_INFORMATION) * cpusCount);

    for (size_t i = 0; i < cpusInfo.size(); i++) {
        const PROCESSOR_POWER_INFORMATION& cpuInfo = cpusInfo[i];
        Msg("* CPU%zu current freq: %lu MHz, max freq: %lu MHz",
            i, cpuInfo.CurrentMhz, cpuInfo.MaxMhz);
    }

    Log("");

    Fidentity.identity();  // Identity matrix
    Didentity.identity();  // Identity matrix
    pvInitializeStatics(); // Lookup table for compressed normals
    FPU::initialize();
    _initialize_cpu_thread();

    g_initialize_cpu_called = true;
}

// per-thread initialization
#include <xmmintrin.h>
#define _MM_DENORMALS_ZERO_MASK 0x0040
#define _MM_DENORMALS_ZERO_ON 0x0040
#define _MM_FLUSH_ZERO_MASK 0x8000
#define _MM_FLUSH_ZERO_ON 0x8000
#define _MM_SET_FLUSH_ZERO_MODE(mode) _mm_setcsr((_mm_getcsr() & ~_MM_FLUSH_ZERO_MASK) | (mode))
#define _MM_SET_DENORMALS_ZERO_MODE(mode) \
    _mm_setcsr((_mm_getcsr() & ~_MM_DENORMALS_ZERO_MASK) | (mode))
static BOOL _denormals_are_zero_supported = TRUE;
extern void __cdecl _terminate();
void debug_on_thread_spawn();

void _initialize_cpu_thread() {
    debug_on_thread_spawn();
#ifndef XRCORE_STATIC
    // fpu & sse
    FPU::m24r();
#endif // XRCORE_STATIC
    if (CPU::ID.hasFeature(CpuFeature::Sse)) {
        //_mm_setcsr ( _mm_getcsr() | (_MM_FLUSH_ZERO_ON+_MM_DENORMALS_ZERO_ON) );
        _MM_SET_FLUSH_ZERO_MODE(_MM_FLUSH_ZERO_ON);
        if (_denormals_are_zero_supported) {
            __try {
                _MM_SET_DENORMALS_ZERO_MODE(_MM_DENORMALS_ZERO_ON);
            } __except (EXCEPTION_EXECUTE_HANDLER) {
                _denormals_are_zero_supported = FALSE;
            }
        }
    }
}

// threading API
#pragma pack(push, 8)
struct THREAD_NAME {
    DWORD dwType;
    LPCSTR szName;
    DWORD dwThreadID;
    DWORD dwFlags;
};
void thread_name(const char* name) {
    THREAD_NAME tn;
    tn.dwType = 0x1000;
    tn.szName = name;
    tn.dwThreadID = DWORD(-1);
    tn.dwFlags = 0;
    __try {
        RaiseException(0x406D1388, 0, sizeof(tn) / sizeof(DWORD), (ULONG_PTR*)&tn);
    } __except (EXCEPTION_CONTINUE_EXECUTION) {
    }
}
#pragma pack(pop)

struct THREAD_STARTUP {
    thread_t* entry;
    char* name;
    void* args;
};
void __cdecl thread_entry(void* _params) {
    // initialize
    THREAD_STARTUP* startup = (THREAD_STARTUP*)_params;
    thread_name(startup->name);
    thread_t* entry = startup->entry;
    void* arglist = startup->args;
    xr_delete(startup);
    _initialize_cpu_thread();

    // call
    entry(arglist);
}

void thread_spawn(thread_t* entry, const char* name, unsigned stack, void* arglist) {
    Debug._initialize();

    THREAD_STARTUP* startup = xr_new<THREAD_STARTUP>();
    startup->entry = entry;
    startup->name = (char*)name;
    startup->args = arglist;
    _beginthread(thread_entry, stack, startup);
}

void spline1(float t, Fvector* p, Fvector* ret) {
    float t2 = t * t;
    float t3 = t2 * t;
    float m[4];

    ret->x = 0.0f;
    ret->y = 0.0f;
    ret->z = 0.0f;
    m[0] = (0.5f * ((-1.0f * t3) + (2.0f * t2) + (-1.0f * t)));
    m[1] = (0.5f * ((3.0f * t3) + (-5.0f * t2) + (0.0f * t) + 2.0f));
    m[2] = (0.5f * ((-3.0f * t3) + (4.0f * t2) + (1.0f * t)));
    m[3] = (0.5f * ((1.0f * t3) + (-1.0f * t2) + (0.0f * t)));

    for (int i = 0; i < 4; i++) {
        ret->x += p[i].x * m[i];
        ret->y += p[i].y * m[i];
        ret->z += p[i].z * m[i];
    }
}

void spline2(float t, Fvector* p, Fvector* ret) {
    float s = 1.0f - t;
    float t2 = t * t;
    float t3 = t2 * t;
    float m[4];

    m[0] = s * s * s;
    m[1] = 3.0f * t3 - 6.0f * t2 + 4.0f;
    m[2] = -3.0f * t3 + 3.0f * t2 + 3.0f * t + 1;
    m[3] = t3;

    ret->x = (p[0].x * m[0] + p[1].x * m[1] + p[2].x * m[2] + p[3].x * m[3]) / 6.0f;
    ret->y = (p[0].y * m[0] + p[1].y * m[1] + p[2].y * m[2] + p[3].y * m[3]) / 6.0f;
    ret->z = (p[0].z * m[0] + p[1].z * m[1] + p[2].z * m[2] + p[3].z * m[3]) / 6.0f;
}

#define beta1 1.0f
#define beta2 0.8f

void spline3(float t, Fvector* p, Fvector* ret) {
    float s = 1.0f - t;
    float t2 = t * t;
    float t3 = t2 * t;
    float b12 = beta1 * beta2;
    float b13 = b12 * beta1;
    float delta = 2.0f - b13 + 4.0f * b12 + 4.0f * beta1 + beta2 + 2.0f;
    float d = 1.0f / delta;
    float b0 = 2.0f * b13 * d * s * s * s;
    float b3 = 2.0f * t3 * d;
    float b1 = d * (2 * b13 * t * (t2 - 3 * t + 3) + 2 * b12 * (t3 - 3 * t2 + 2) +
                    2 * beta1 * (t3 - 3 * t + 2) + beta2 * (2 * t3 - 3 * t2 + 1));
    float b2 = d * (2 * b12 * t2 * (-t + 3) + 2 * beta1 * t * (-t2 + 3) +
                    beta2 * t2 * (-2 * t + 3) + 2 * (-t3 + 1));

    ret->x = p[0].x * b0 + p[1].x * b1 + p[2].x * b2 + p[3].x * b3;
    ret->y = p[0].y * b0 + p[1].y * b1 + p[2].y * b2 + p[3].y * b3;
    ret->z = p[0].z * b0 + p[1].z * b1 + p[2].z * b2 + p[3].z * b3;
}
