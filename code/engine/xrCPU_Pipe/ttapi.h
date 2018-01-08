#pragma once

#include "thread_pool.h"

#ifdef XRCPU_PIPE_EXPORTS
#define TTAPI __declspec(dllexport)
#else // XRCPU_PIPE_EXPORTS
#define TTAPI __declspec(dllimport)
#endif // XRCPU_PIPE_EXPORTS

extern ThreadPool TTAPI ttapi;
