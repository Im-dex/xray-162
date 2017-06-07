/*
 * This is a part of the BugTrap package.
 * Copyright (c) 2005-2009 IntelleSoft.
 * All rights reserved.
 *
 * Description: Global variables definitions.
 * Author: Maksim Pyatkovskiy.
 *
 * This source code is only intended as a supplement to the
 * BugTrap package reference and related electronic documentation
 * provided with the product. See these sources for detailed
 * information regarding the BugTrap package.
 */

#pragma once

#include "BugTrap.h"
#include "ResManager.h"
#include "Array.h"
#include "LogFile.h"
#include "CMapi.h"
#include "SymEngine.h"
#include "EnumProcess.h"
#include "LogLink.h"
#include "VersionInfo.h"

#if defined _MANAGED
 #if defined _M_IX86
  #define BUGTRAP_PLATFORM   _T(".NET-x86")
 #elif defined _M_X64
  #define BUGTRAP_PLATFORM   _T(".NET-x64")
 #else
  #error CPU architecture is not supported.
 #endif
#else
 #if defined _M_IX86
  #define BUGTRAP_PLATFORM   _T("Win32-x86")
 #elif defined _M_X64
  #define BUGTRAP_PLATFORM   _T("Win64-x64")
 #else
  #error CPU architecture is not supported.
 #endif
#endif

#define BUGTRAP_TITLE   _T("BugTrap for ") BUGTRAP_PLATFORM

#define _TOSTR(value)    _T(#value)
#define TOSTR(value)     _TOSTR(value)

/// Maximum size of memory buffer (100K).
const DWORD g_dwMaxBufferSize = 100 * 1024;
/// Protocol signature.
const DWORD g_dwProtocolSignature = (('B' << 0) | ('T' << 8) | ('0' << 16) | ('1' << 24));

/// BugTrap module handle.
extern HINSTANCE g_hInstance;
/// Module of interest handle
extern HINSTANCE g_hModule;
/// Application name.
extern TCHAR g_szAppName[MAX_PATH];
/// Application version number.
extern TCHAR g_szAppVersion[MAX_PATH];
/// Web address of product support site.
extern TCHAR g_szSupportURL[MAX_PATH];
/// E-mail address of product support.
extern TCHAR g_szSupportEMail[MAX_PATH];
/// Host name of product support server where BugTrapServer is installed.
extern TCHAR g_szSupportHost[MAX_PATH];
/// E-mail address of error notification service.
extern TCHAR g_szNotificationEMail[MAX_PATH];
/// Name of MAPI profile.
extern TCHAR g_szMailProfile[MAX_PATH];
/// Password of MAPI profile.
extern TCHAR g_szMailPassword[MAX_PATH];
/// Port number of product support server where BugTrapServer is installed.
extern SHORT g_nSupportPort;
/// Path to error report specified by user.
extern TCHAR g_szReportFilePath[MAX_PATH];
/// Internal path to a folder with report files.
extern TCHAR g_szInternalReportFolder[MAX_PATH];
/// Internal path to single report file.
extern TCHAR g_szInternalReportFilePath[MAX_PATH];
/// BugTrap configuration flags.
extern DWORD g_dwFlags;
/// Type of action which is performed in response to the error.
extern BUGTRAP_ACTIVITY g_eActivityType;
/// Application terminaation mode.
extern BUGTRAP_EXITMODE g_eExitMode;
/// Type of produced mini-dump. See @a MINIDUMP_TYPE for details.
extern MINIDUMP_TYPE g_eDumpType;
/// Format of error report.
extern BUGTRAP_REPORTFORMAT g_eReportFormat;
/// Address of error handler called before BugTrap dialog.
extern BT_ErrHandler g_pfnPreErrHandler;
/// User-defined parameter of error handler called before BugTrap dialog.
extern INT_PTR g_nPreErrHandlerParam;
/// Address of error handler called after BugTrap dialog.
extern BT_ErrHandler g_pfnPostErrHandler;
/// User-defined parameter of error handler called after BugTrap dialog.
extern INT_PTR g_nPostErrHandlerParam;
/// Pointer to the exception information.
extern PEXCEPTION_POINTERS g_pExceptionPointers;
/// Custom resources manager.
extern CResManager* g_pResManager;
/// Pointer to Simple MAPI session object.
extern CMapiSession* g_pMapiSession;
/// Pointer to symbolic engine.
extern CSymEngine* g_pSymEngine;
/// Pointer to process enumerator.
extern CEnumProcess* g_pEnumProc;
/// Array of custom log file names attached to the report.
extern CArray<CLogLink*, CDynamicTraits<CLogLink*> > g_arrLogLinks;
/// User defined message printed to the log file.
extern CStrHolder g_strUserMessage;
/// 1st introduction message displayed on the dialog.
extern CStrHolder g_strFirstIntroMesage;
/// 2nd introduction message displayed on the dialog.
extern CStrHolder g_strSecondIntroMesage;

/// Address of custom activity handler called at processing BugTrap action.
extern BT_CustomActivityHandler g_pfnCustomActivityHandler;
/// User-defined parameter of custom activity handler.
extern INT_PTR g_nCustomActivityHandlerParam;
