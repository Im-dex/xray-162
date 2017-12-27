// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#pragma once

#include "../xrCore/xrCore.h"

#define CNEW(type) new (xr_alloc<type>(1)) type
#define CDELETE(ptr) xr_delete(ptr)
#define CFREE(ptr) xr_free(ptr)
#define CMALLOC(size) xr_malloc(size)
#define CALLOC(type, count) xr_alloc<type>(count)

#define ENGINE_API
#include "opcode.h"