#pragma once

#define IMDEXLIB_PP_CONCAT_IMPL(a, b) a ## b
#define IMDEXLIB_PP_CONCAT(a, b) IMDEXLIB_PP_CONCAT_IMPL(a, b)

#ifdef __COUNTER__
#   define IMDEXLIB_ANONYMOUS_VAR(name) IMDEXLIB_PP_CONCAT(name, __COUNTER__)
#else
#   define IMDEXLIB_ANONYMOUS_VAR(name) IMDEXLIB_PP_CONCAT(name, __LINE__)
#endif
