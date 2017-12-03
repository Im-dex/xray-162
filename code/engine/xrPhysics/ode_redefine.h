#pragma once

#ifdef XRPHYSICS_EXPORTS

#ifdef dSqrt
#undef dSqrt
#define dSqrt(x) ((float)std::sqrt(x)) /* square root */
#endif

#ifdef dRecipSqrt
#undef dRecipSqrt
#define dRecipSqrt(x) ((float)(1.0f / std::sqrt(x))) /* reciprocal square root */
#endif

#ifdef dSin
#undef dSin
#define dSin(x) ((float)std::sin(x)) /* sine */
#endif

#ifdef dCos
#undef dCos
#define dCos(x) ((float)std::cos(x)) /* cosine */
#endif

#ifdef dFabs
#undef dFabs
#define dFabs(x) ((float)xr::abs(x)) /* absolute value */
#endif

#endif // XRGAME_EXPORTS
