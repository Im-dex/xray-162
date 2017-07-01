#pragma once

#define PROTECT_API __declspec(dllexport)

#ifdef BENCHMARK_BUILD
#undef PROTECT_API
#define PROTECT_API
#endif //	#ifdef	BENCHMARK_BUILD
