#include "stdafx.h"
#include "stacktrace_collector.h"

#include <dbghelp.h>

thread_local static void* stack[MaxStackTraceDepth];
thread_local static char symbol[sizeof(SYMBOL_INFO) + (MaxFrameLength + 1) * sizeof(char)];

void BuildStackTrace(StackTraceInfo& stackTrace) {
    static std::mutex dbghelpMutex;
    std::lock_guard<std::mutex> lock(dbghelpMutex);

    const auto processHandle = GetCurrentProcess();
    const auto symRes = SymInitialize(processHandle, nullptr, TRUE);

    const auto framesCount = CaptureStackBackTrace(1, MaxStackTraceDepth, stack, nullptr);
    SYMBOL_INFO* symbolInfo = reinterpret_cast<SYMBOL_INFO*>(&symbol);
    symbolInfo->MaxNameLen = MaxFrameLength;
    symbolInfo->SizeOfStruct = sizeof(SYMBOL_INFO);

    IMAGEHLP_LINE64 lineInfo = { 0 };
    lineInfo.SizeOfStruct = sizeof(IMAGEHLP_LINE64);

    for (size_t i = 0; i < framesCount; i++) {
        const auto addr = reinterpret_cast<DWORD64>(stack[i]);
        SymFromAddr(processHandle, addr, nullptr, symbolInfo);
        DWORD displacement = 0;
        SymGetLineFromAddr64(processHandle, addr, &displacement, &lineInfo);
        auto* dst = stackTrace.frames + (MaxFrameLength + 1) * i;
        std::snprintf(dst, MaxFrameLength + 1, "%zi: %s at %s:%u", framesCount - i, symbolInfo->Name, lineInfo.FileName, lineInfo.LineNumber);
    }

    stackTrace.count = framesCount;
}
