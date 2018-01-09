// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#pragma once

#include "../xrCore/xrCore.h"

#define CNEW(type) new type
#define CDELETE(ptr) delete ptr
#define CFREE(ptr) delete[] ptr
#define CALLOC(type, count) new type[count]

#define ENGINE_API
#include "opcode.h"