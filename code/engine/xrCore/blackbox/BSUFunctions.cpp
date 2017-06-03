/*----------------------------------------------------------------------
"Debugging Applications" (Microsoft Press)
Copyright (c) 1997-2000 John Robbins -- All rights reserved.
----------------------------------------------------------------------*/

#include "stdafx_.h"
#include "BugslayerUtil.h"
#include "Internal.h"

/*//////////////////////////////////////////////////////////////////////
                        Function Implementation
//////////////////////////////////////////////////////////////////////*/

DWORD __stdcall BSUGetModuleBaseName ( HANDLE  hProcess   ,
                                       HMODULE hModule    ,
                                       LPTSTR  lpBaseName ,
                                       DWORD   nSize       )
{
    return (NTGetModuleBaseName(hProcess,
        hModule,
        lpBaseName,
        nSize));
}

DWORD  __stdcall
        BSUSymInitialize ( DWORD  dwPID          ,
                           HANDLE hProcess       ,
                           PSTR   UserSearchPath ,
                           BOOL   fInvadeProcess  )
{
    return (::SymInitialize(hProcess,
        UserSearchPath,
        fInvadeProcess));
}

DWORD __stdcall BSUGetModuleFileNameEx ( DWORD     dwPID        ,
                                         HANDLE    hProcess     ,
                                         HMODULE   hModule      ,
                                         LPTSTR    szFilename   ,
                                         DWORD     nSize         )
{
    return (NTGetModuleFileNameEx(dwPID,
        hProcess,
        hModule,
        szFilename,
        nSize));
}

