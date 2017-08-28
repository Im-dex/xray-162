// xrCore.cpp : Defines the entry point for the DLL application.
//
#include "stdafx.h"

#include <mmsystem.h>
#include <objbase.h>
#include "xrCore.h"

#ifdef DEBUG
#include <malloc.h>
#endif // DEBUG

XRCORE_API xrCore Core;
XRCORE_API u32 build_id;
XRCORE_API LPCSTR build_date;

namespace CPU {
extern void Detect();
}

static u32 init_counter = 0;

void xrCore::_initialize(const char* _ApplicationName, LogCallback cb, bool init_fs,
                         const char* fs_fname) {
    xr_strcpy(ApplicationName, _ApplicationName);
    if (0 == init_counter) {
        // Init COM so we can use CoCreateInstance
        //		HRESULT co_res =
        if (!strstr(GetCommandLine(), "-editor"))
            CoInitializeEx(nullptr, COINIT_MULTITHREADED);

        xr_strcpy(Params, sizeof(Params), GetCommandLine());
        _strlwr_s(Params, sizeof(Params));

        string_path fn, dr, di;

        // application path
        GetModuleFileName(GetModuleHandle(MODULE_NAME), fn, sizeof(fn));
        _splitpath(fn, dr, di, nullptr, nullptr);
        strconcat(sizeof(ApplicationPath), ApplicationPath, dr, di);

        GetCurrentDirectory(sizeof(WorkingPath), WorkingPath);

        // User/Comp Name
        DWORD sz_user = sizeof(UserName);
        GetUserName(UserName, &sz_user);

        DWORD sz_comp = sizeof(CompName);
        GetComputerName(CompName, &sz_comp);

        // Mathematics & PSI detection
        CPU::Detect();

        Memory._initialize(strstr(Params, "-mem_debug") ? TRUE : FALSE);

        DUMP_PHASE;

        InitLog();
        _initialize_cpu();

        //		Debug._initialize	();

        rtc_initialize();

        xr_FS = xr_new<CLocatorAPI>();
        //.		R_ASSERT			(co_res==S_OK);
    }
    if (init_fs) {
        u32 flags = 0u;
        if (nullptr != strstr(Params, "-build"))
            flags |= CLocatorAPI::flBuildCopy;
        if (nullptr != strstr(Params, "-ebuild"))
            flags |= CLocatorAPI::flBuildCopy | CLocatorAPI::flEBuildCopy;
#ifdef DEBUG
        if (strstr(Params, "-cache"))
            flags |= CLocatorAPI::flCacheFiles;
        else
            flags &= ~CLocatorAPI::flCacheFiles;
#endif         // DEBUG
        flags |= CLocatorAPI::flScanAppRoot;

#ifndef ELocatorAPIH
        if (nullptr != strstr(Params, "-file_activity"))
            flags |= CLocatorAPI::flDumpFileActivity;
#endif
        FS._initialize(flags, nullptr, fs_fname);
        Msg("'%s' build %d, %s\n", "xrCore", build_id, build_date);
#ifdef DEBUG
        Msg("CRT heap 0x%08x", _get_heap_handle());
        Msg("Process heap 0x%08x", GetProcessHeap());
#endif // DEBUG
    }
    SetLogCB(cb);
    init_counter++;
}

void xrCore::_destroy() {
    --init_counter;
    if (0 == init_counter) {
        FS._destroy();
        xr_delete(xr_FS);

        Memory._destroy();
    }
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD ul_reason_for_call, LPVOID lpvReserved)
{
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH: {
        _clear87();
#ifdef _M_IX86
        _control87(_PC_53, MCW_PC);
#endif
        _control87(_RC_CHOP, MCW_RC);
        _control87(_RC_NEAR, MCW_RC);
        _control87(_MCW_EM, MCW_EM);
    }
    //.		LogFile.reserve		(256);
    break;
    case DLL_THREAD_ATTACH:
        if (!strstr(GetCommandLine(), "-editor"))
            CoInitializeEx(NULL, COINIT_MULTITHREADED);
        timeBeginPeriod(1);
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
#ifdef USE_MEMORY_MONITOR
        memory_monitor::flush_each_time(true);
#endif // USE_MEMORY_MONITOR
        break;
    }
    return TRUE;
}
