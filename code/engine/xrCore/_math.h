#pragma once

#include "cpuid.h"

namespace FPU {
XRCORE_API void m24(void);
XRCORE_API void m24r(void);
XRCORE_API void m53(void);
XRCORE_API void m53r(void);
XRCORE_API void m64(void);
XRCORE_API void m64r(void);
}; // namespace FPU
namespace CPU {
XRCORE_API extern u64 qpc_freq;
XRCORE_API extern u32 qpc_counter;

XRCORE_API extern processor_info ID;
XRCORE_API extern u64 QPC();

#ifndef _M_AMD64
#pragma warning(disable : 4035)
inline u64 GetCLK() {
    _asm _emit 0x0F;
    _asm _emit 0x31;
}
#pragma warning(default : 4035)
#else
inline u64 GetCLK() { return __rdtsc(); }
#endif

} // namespace CPU

XRCORE_API void _initialize_cpu();
XRCORE_API void set_current_thread_name(const char* threadName);
XRCORE_API void set_thread_name(const char* threadName, std::thread& thread);