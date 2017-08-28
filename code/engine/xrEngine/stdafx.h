#ifndef STDAFX_3DA
#define STDAFX_3DA
#pragma once

#ifdef _EDITOR
#include "..\editors\ECore\stdafx.h"
#else

#ifndef NDEBUG
#ifndef INGAME_EDITOR
#define INGAME_EDITOR
#endif // #ifndef INGAME_EDITOR
#endif // #ifndef NDEBUG

#ifdef INGAME_EDITOR
#define _WIN32_WINNT 0x0550
#endif // #ifdef INGAME_EDITOR

#include "../xrCore/xrCore.h"
#include "xrAPI/xrAPI.h"

#ifdef _DEBUG
#define D3D_DEBUG_INFO
#endif

#pragma warning(disable : 4995)
#include <d3d9.h>
//#include <dplay8.h>
#pragma warning(default : 4995)

// you must define ENGINE_BUILD then building the engine itself
// and not define it if you are about to build DLL
#ifndef NO_ENGINE_API
#ifdef ENGINE_BUILD
#define DLL_API __declspec(dllimport)
#define ENGINE_API __declspec(dllexport)
#else
#undef DLL_API
#define DLL_API __declspec(dllexport)
#define ENGINE_API __declspec(dllimport)
#endif
#else
#define ENGINE_API
#define DLL_API
#endif // NO_ENGINE_API

#define ECORE_API

// Our headers
#include "engine.h"
#include "defines.h"
#ifndef NO_XRLOG
#include "../xrcore/log.h"
#endif
#include "device.h"
#include "../xrcore/fs.h"

#include "../xrcdb/xrXRC.h"

#include "../xrSound/sound.h"

extern ENGINE_API CInifile* pGameIni;

#ifndef DEBUG
#define LUABIND_NO_ERROR_CHECKING
#endif

#if !defined(DEBUG) || defined(FORCE_NO_EXCEPTIONS)
#define LUABIND_NO_EXCEPTIONS
#endif

#define LUABIND_DONT_COPY_STRINGS

#define READ_IF_EXISTS(ltx, method, section, name, default_value) \
    (((ltx)->line_exist(section, name)) ? ((ltx)->method(section, name)) : (default_value))

#endif // !M_BORLAND
#endif // !defined STDAFX_3DA