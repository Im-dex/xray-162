#pragma once

#define DEBUG_INFO __FILE__, __LINE__, __FUNCTION__

#define CHECK_OR_EXIT(expr, message)  \
    do {                              \
        if (!(expr))                  \
            xrDebug::do_exit(message); \
    } while (0)

#define R_ASSERT(expr)                                            \
    do {                                                          \
        static bool ignore_always = false;                        \
        if (!ignore_always && !(expr))                            \
            ::Debug.fail(#expr, DEBUG_INFO, ignore_always); \
    } while (0)
#define R_ASSERT2(expr, e2)                                                 \
    do {                                                                    \
        static bool ignore_always = false;                                  \
        if (!ignore_always && !(expr))                                      \
            ::Debug.fail(#expr, e2, DEBUG_INFO, ignore_always); \
    } while (0)
#define R_ASSERT3(expr, e2, e3)                                                       \
    do {                                                                              \
        static bool ignore_always = false;                                            \
        if (!ignore_always && !(expr))                                                \
            ::Debug.fail(#expr, e2, { e3 }, DEBUG_INFO, ignore_always); \
    } while (0)
#define R_ASSERT4(expr, e2, e3, e4)                                                             \
    do {                                                                                        \
        static bool ignore_always = false;                                                      \
        if (!ignore_always && !(expr))                                                          \
            ::Debug.fail(#expr, e2, { e3, e4 }, DEBUG_INFO, ignore_always); \
    } while (0)
#define R_CHK(expr)                                                    \
    do {                                                               \
        static bool ignore_always = false;                             \
        HRESULT hr = expr;                                             \
        if (!ignore_always && FAILED(hr))                              \
            ::Debug.error(hr, #expr, {}, DEBUG_INFO, ignore_always); \
    } while (0)
#define R_CHK2(expr, e2)                                                         \
    do {                                                                         \
        static bool ignore_always = false;                                       \
        HRESULT hr = expr;                                                       \
        if (!ignore_always && FAILED(hr))                                        \
            ::Debug.error(hr, #expr, { e2 }, DEBUG_INFO, ignore_always); \
    } while (0)
#define FATAL(description) Debug.fatal(DEBUG_INFO, description)

#ifdef VERIFY
#undef VERIFY
#endif // VERIFY

#ifdef DEBUG
#define NODEFAULT FATAL("nodefault reached")
#define VERIFY(expr)                                        \
    do {                                                    \
        static bool ignore_always = false;                  \
        if (!ignore_always && !(expr))                      \
            ::Debug.fail(#expr, DEBUG_INFO, ignore_always); \
    } while (0)
#define VERIFY2(expr, e2)                                       \
    do {                                                        \
        static bool ignore_always = false;                      \
        if (!ignore_always && !(expr))                          \
            ::Debug.fail(#expr, e2, DEBUG_INFO, ignore_always); \
    } while (0)
#define VERIFY3(expr, e2, e3)                                       \
    do {                                                            \
        static bool ignore_always = false;                          \
        if (!ignore_always && !(expr))                              \
            ::Debug.fail(#expr, e2, { e3 }, DEBUG_INFO, ignore_always); \
    } while (0)
#define VERIFY4(expr, e2, e3, e4)                                       \
    do {                                                                \
        static bool ignore_always = false;                              \
        if (!ignore_always && !(expr))                                  \
            ::Debug.fail(#expr, e2, { e3, e4 }, DEBUG_INFO, ignore_always); \
    } while (0)
#define CHK_DX(expr)                                             \
    do {                                                         \
        static bool ignore_always = false;                       \
        HRESULT hr = expr;                                       \
        if (!ignore_always && FAILED(hr))                        \
            ::Debug.error(hr, #expr, {}, DEBUG_INFO, ignore_always); \
    } while (0)
#else // DEBUG
#define NODEFAULT __assume(0)
#define VERIFY(expr) \
    do {             \
    } while (0)
#define VERIFY2(expr, e2) \
    do {                  \
    } while (0)
#define VERIFY3(expr, e2, e3) \
    do {                      \
    } while (0)
#define VERIFY4(expr, e2, e3, e4) \
    do {                          \
    } while (0)
#define CHK_DX(a) a
#endif // DEBUG

#define QUOTE_IMPL(x) #x
#define QUOTE(x) QUOTE_IMPL(x)
#define __FILE__LINE__ __FILE__ "(" QUOTE(__LINE__) ") : "
