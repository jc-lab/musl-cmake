#ifndef _MATH_H
#define _MATH_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#define __NEED_float_t
#define __NEED_double_t
#include <bits/alltypes.h>

#if 100*__GNUC__+__GNUC_MINOR__ >= 303
#define NAN       __builtin_nanf("")
#define INFINITY  __builtin_inff()
#else
#define NAN       (0.0f/0.0f)
#define INFINITY  1e5000f
#endif

#define HUGE_VALF INFINITY
#define HUGE_VAL  ((double)INFINITY)
#define HUGE_VALL ((long double)INFINITY)

#define MATH_ERRNO  1
#define MATH_ERREXCEPT 2
#define math_errhandling 2

#define FP_ILOGBNAN (-1-0x7fffffff)
#define FP_ILOGB0 FP_ILOGBNAN

#define FP_NAN       0
#define FP_INFINITE  1
#define FP_ZERO      2
#define FP_SUBNORMAL 3
#define FP_NORMAL    4

#ifdef __FP_FAST_FMA
#define FP_FAST_FMA 1
#endif

#ifdef __FP_FAST_FMAF
#define FP_FAST_FMAF 1
#endif

#ifdef __FP_FAST_FMAL
#define FP_FAST_FMAL 1
#endif

hidden int __fpclassify(double);
hidden int __fpclassifyf(float);
hidden int __fpclassifyl(long double);

static __inline unsigned __FLOAT_BITS(float __f)
{
	union {float __f; unsigned __i;} __u;
	__u.__f = __f;
	return __u.__i;
}
static __inline unsigned long long __DOUBLE_BITS(double __f)
{
	union {double __f; unsigned long long __i;} __u;
	__u.__f = __f;
	return __u.__i;
}

#define fpclassify(x) ( \
	sizeof(x) == sizeof(float) ? __fpclassifyf(x) : \
	sizeof(x) == sizeof(double) ? __fpclassify(x) : \
	__fpclassifyl(x) )

#define isinf(x) ( \
	sizeof(x) == sizeof(float) ? (__FLOAT_BITS(x) & 0x7fffffff) == 0x7f800000 : \
	sizeof(x) == sizeof(double) ? (__DOUBLE_BITS(x) & -1ULL>>1) == 0x7ffULL<<52 : \
	__fpclassifyl(x) == FP_INFINITE)

#define isnan(x) ( \
	sizeof(x) == sizeof(float) ? (__FLOAT_BITS(x) & 0x7fffffff) > 0x7f800000 : \
	sizeof(x) == sizeof(double) ? (__DOUBLE_BITS(x) & -1ULL>>1) > 0x7ffULL<<52 : \
	__fpclassifyl(x) == FP_NAN)

#define isnormal(x) ( \
	sizeof(x) == sizeof(float) ? ((__FLOAT_BITS(x)+0x00800000) & 0x7fffffff) >= 0x01000000 : \
	sizeof(x) == sizeof(double) ? ((__DOUBLE_BITS(x)+(1ULL<<52)) & -1ULL>>1) >= 1ULL<<53 : \
	__fpclassifyl(x) == FP_NORMAL)

#define isfinite(x) ( \
	sizeof(x) == sizeof(float) ? (__FLOAT_BITS(x) & 0x7fffffff) < 0x7f800000 : \
	sizeof(x) == sizeof(double) ? (__DOUBLE_BITS(x) & -1ULL>>1) < 0x7ffULL<<52 : \
	__fpclassifyl(x) > FP_INFINITE)

hidden int __signbit(double);
hidden int __signbitf(float);
hidden int __signbitl(long double);

#define signbit(x) ( \
	sizeof(x) == sizeof(float) ? (int)(__FLOAT_BITS(x)>>31) : \
	sizeof(x) == sizeof(double) ? (int)(__DOUBLE_BITS(x)>>63) : \
	__signbitl(x) )

#define isunordered(x,y) (isnan((x)) ? ((void)(y),1) : isnan((y)))

#define __ISREL_DEF(rel, op, type) \
static __inline int __is##rel(type __x, type __y) \
{ return !isunordered(__x,__y) && __x op __y; }

__ISREL_DEF(lessf, <, float_t)
__ISREL_DEF(less, <, double_t)
__ISREL_DEF(lessl, <, long double)
__ISREL_DEF(lessequalf, <=, float_t)
__ISREL_DEF(lessequal, <=, double_t)
__ISREL_DEF(lessequall, <=, long double)
__ISREL_DEF(lessgreaterf, !=, float_t)
__ISREL_DEF(lessgreater, !=, double_t)
__ISREL_DEF(lessgreaterl, !=, long double)
__ISREL_DEF(greaterf, >, float_t)
__ISREL_DEF(greater, >, double_t)
__ISREL_DEF(greaterl, >, long double)
__ISREL_DEF(greaterequalf, >=, float_t)
__ISREL_DEF(greaterequal, >=, double_t)
__ISREL_DEF(greaterequall, >=, long double)

#define __tg_pred_2(x, y, p) ( \
	sizeof((x)+(y)) == sizeof(float) ? p##f(x, y) : \
	sizeof((x)+(y)) == sizeof(double) ? p(x, y) : \
	p##l(x, y) )

#define isless(x, y)            __tg_pred_2(x, y, __isless)
#define islessequal(x, y)       __tg_pred_2(x, y, __islessequal)
#define islessgreater(x, y)     __tg_pred_2(x, y, __islessgreater)
#define isgreater(x, y)         __tg_pred_2(x, y, __isgreater)
#define isgreaterequal(x, y)    __tg_pred_2(x, y, __isgreaterequal)

MUSL_EXPORT double      acos(double);
MUSL_EXPORT float       acosf(float);
MUSL_EXPORT long double acosl(long double);

MUSL_EXPORT double      acosh(double);
MUSL_EXPORT float       acoshf(float);
MUSL_EXPORT long double acoshl(long double);

MUSL_EXPORT double      asin(double);
MUSL_EXPORT float       asinf(float);
MUSL_EXPORT long double asinl(long double);

MUSL_EXPORT double      asinh(double);
MUSL_EXPORT float       asinhf(float);
MUSL_EXPORT long double asinhl(long double);

MUSL_EXPORT double      atan(double);
MUSL_EXPORT float       atanf(float);
MUSL_EXPORT long double atanl(long double);

MUSL_EXPORT double      atan2(double, double);
MUSL_EXPORT float       atan2f(float, float);
MUSL_EXPORT long double atan2l(long double, long double);

MUSL_EXPORT double      atanh(double);
MUSL_EXPORT float       atanhf(float);
MUSL_EXPORT long double atanhl(long double);

MUSL_EXPORT double      cbrt(double);
MUSL_EXPORT float       cbrtf(float);
MUSL_EXPORT long double cbrtl(long double);

MUSL_EXPORT double      ceil(double);
MUSL_EXPORT float       ceilf(float);
MUSL_EXPORT long double ceill(long double);

MUSL_EXPORT double      copysign(double, double);
MUSL_EXPORT float       copysignf(float, float);
MUSL_EXPORT long double copysignl(long double, long double);

MUSL_EXPORT double      cos(double);
MUSL_EXPORT float       cosf(float);
MUSL_EXPORT long double cosl(long double);

MUSL_EXPORT double      cosh(double);
MUSL_EXPORT float       coshf(float);
MUSL_EXPORT long double coshl(long double);

MUSL_EXPORT double      erf(double);
MUSL_EXPORT float       erff(float);
MUSL_EXPORT long double erfl(long double);

MUSL_EXPORT double      erfc(double);
MUSL_EXPORT float       erfcf(float);
MUSL_EXPORT long double erfcl(long double);

MUSL_EXPORT double      exp(double);
MUSL_EXPORT float       expf(float);
MUSL_EXPORT long double expl(long double);

MUSL_EXPORT double      exp2(double);
MUSL_EXPORT float       exp2f(float);
MUSL_EXPORT long double exp2l(long double);

MUSL_EXPORT double      expm1(double);
MUSL_EXPORT float       expm1f(float);
MUSL_EXPORT long double expm1l(long double);

MUSL_EXPORT double      fabs(double);
MUSL_EXPORT float       fabsf(float);
MUSL_EXPORT long double fabsl(long double);

MUSL_EXPORT double      fdim(double, double);
MUSL_EXPORT float       fdimf(float, float);
MUSL_EXPORT long double fdiml(long double, long double);

MUSL_EXPORT double      floor(double);
MUSL_EXPORT float       floorf(float);
MUSL_EXPORT long double floorl(long double);

MUSL_EXPORT double      fma(double, double, double);
MUSL_EXPORT float       fmaf(float, float, float);
MUSL_EXPORT long double fmal(long double, long double, long double);

MUSL_EXPORT double      fmax(double, double);
MUSL_EXPORT float       fmaxf(float, float);
MUSL_EXPORT long double fmaxl(long double, long double);

MUSL_EXPORT double      fmin(double, double);
MUSL_EXPORT float       fminf(float, float);
MUSL_EXPORT long double fminl(long double, long double);

MUSL_EXPORT double      fmod(double, double);
MUSL_EXPORT float       fmodf(float, float);
MUSL_EXPORT long double fmodl(long double, long double);

MUSL_EXPORT double      frexp(double, int *);
MUSL_EXPORT float       frexpf(float, int *);
MUSL_EXPORT long double frexpl(long double, int *);

MUSL_EXPORT double      hypot(double, double);
MUSL_EXPORT float       hypotf(float, float);
MUSL_EXPORT long double hypotl(long double, long double);

MUSL_EXPORT int         ilogb(double);
MUSL_EXPORT int         ilogbf(float);
MUSL_EXPORT int         ilogbl(long double);

MUSL_EXPORT double      ldexp(double, int);
MUSL_EXPORT float       ldexpf(float, int);
MUSL_EXPORT long double ldexpl(long double, int);

MUSL_EXPORT double      lgamma(double);
MUSL_EXPORT float       lgammaf(float);
MUSL_EXPORT long double lgammal(long double);

MUSL_EXPORT long long   llrint(double);
MUSL_EXPORT long long   llrintf(float);
MUSL_EXPORT long long   llrintl(long double);

MUSL_EXPORT long long   llround(double);
MUSL_EXPORT long long   llroundf(float);
MUSL_EXPORT long long   llroundl(long double);

MUSL_EXPORT double      log(double);
MUSL_EXPORT float       logf(float);
MUSL_EXPORT long double logl(long double);

MUSL_EXPORT double      log10(double);
MUSL_EXPORT float       log10f(float);
MUSL_EXPORT long double log10l(long double);

MUSL_EXPORT double      log1p(double);
MUSL_EXPORT float       log1pf(float);
MUSL_EXPORT long double log1pl(long double);

MUSL_EXPORT double      log2(double);
MUSL_EXPORT float       log2f(float);
MUSL_EXPORT long double log2l(long double);

MUSL_EXPORT double      logb(double);
MUSL_EXPORT float       logbf(float);
MUSL_EXPORT long double logbl(long double);

MUSL_EXPORT long        lrint(double);
MUSL_EXPORT long        lrintf(float);
MUSL_EXPORT long        lrintl(long double);

MUSL_EXPORT long        lround(double);
MUSL_EXPORT long        lroundf(float);
MUSL_EXPORT long        lroundl(long double);

MUSL_EXPORT double      modf(double, double *);
MUSL_EXPORT float       modff(float, float *);
MUSL_EXPORT long double modfl(long double, long double *);

MUSL_EXPORT double      nan(const char *);
MUSL_EXPORT float       nanf(const char *);
MUSL_EXPORT long double nanl(const char *);

MUSL_EXPORT double      nearbyint(double);
MUSL_EXPORT float       nearbyintf(float);
MUSL_EXPORT long double nearbyintl(long double);

MUSL_EXPORT double      nextafter(double, double);
MUSL_EXPORT float       nextafterf(float, float);
MUSL_EXPORT long double nextafterl(long double, long double);

MUSL_EXPORT double      nexttoward(double, long double);
MUSL_EXPORT float       nexttowardf(float, long double);
MUSL_EXPORT long double nexttowardl(long double, long double);

MUSL_EXPORT double      pow(double, double);
MUSL_EXPORT float       powf(float, float);
MUSL_EXPORT long double powl(long double, long double);

MUSL_EXPORT double      remainder(double, double);
MUSL_EXPORT float       remainderf(float, float);
MUSL_EXPORT long double remainderl(long double, long double);

MUSL_EXPORT double      remquo(double, double, int *);
MUSL_EXPORT float       remquof(float, float, int *);
MUSL_EXPORT long double remquol(long double, long double, int *);

MUSL_EXPORT double      rint(double);
MUSL_EXPORT float       rintf(float);
MUSL_EXPORT long double rintl(long double);

MUSL_EXPORT double      round(double);
MUSL_EXPORT float       roundf(float);
MUSL_EXPORT long double roundl(long double);

MUSL_EXPORT double      scalbln(double, long);
MUSL_EXPORT float       scalblnf(float, long);
MUSL_EXPORT long double scalblnl(long double, long);

MUSL_EXPORT double      scalbn(double, int);
MUSL_EXPORT float       scalbnf(float, int);
MUSL_EXPORT long double scalbnl(long double, int);

MUSL_EXPORT double      sin(double);
MUSL_EXPORT float       sinf(float);
MUSL_EXPORT long double sinl(long double);

MUSL_EXPORT double      sinh(double);
MUSL_EXPORT float       sinhf(float);
MUSL_EXPORT long double sinhl(long double);

MUSL_EXPORT double      sqrt(double);
MUSL_EXPORT float       sqrtf(float);
MUSL_EXPORT long double sqrtl(long double);

MUSL_EXPORT double      tan(double);
MUSL_EXPORT float       tanf(float);
MUSL_EXPORT long double tanl(long double);

MUSL_EXPORT double      tanh(double);
MUSL_EXPORT float       tanhf(float);
MUSL_EXPORT long double tanhl(long double);

MUSL_EXPORT double      tgamma(double);
MUSL_EXPORT float       tgammaf(float);
MUSL_EXPORT long double tgammal(long double);

MUSL_EXPORT double      trunc(double);
MUSL_EXPORT float       truncf(float);
MUSL_EXPORT long double truncl(long double);


#if defined(_XOPEN_SOURCE) || defined(_BSD_SOURCE)
#undef  MAXFLOAT
#define MAXFLOAT        3.40282346638528859812e+38F
#endif

#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define M_E             2.7182818284590452354   /* e */
#define M_LOG2E         1.4426950408889634074   /* log_2 e */
#define M_LOG10E        0.43429448190325182765  /* log_10 e */
#define M_LN2           0.69314718055994530942  /* log_e 2 */
#define M_LN10          2.30258509299404568402  /* log_e 10 */
#define M_PI            3.14159265358979323846  /* pi */
#define M_PI_2          1.57079632679489661923  /* pi/2 */
#define M_PI_4          0.78539816339744830962  /* pi/4 */
#define M_1_PI          0.31830988618379067154  /* 1/pi */
#define M_2_PI          0.63661977236758134308  /* 2/pi */
#define M_2_SQRTPI      1.12837916709551257390  /* 2/sqrt(pi) */
#define M_SQRT2         1.41421356237309504880  /* sqrt(2) */
#define M_SQRT1_2       0.70710678118654752440  /* 1/sqrt(2) */

extern int signgam;

MUSL_EXPORT double      j0(double);
MUSL_EXPORT double      j1(double);
MUSL_EXPORT double      jn(int, double);

MUSL_EXPORT double      y0(double);
MUSL_EXPORT double      y1(double);
MUSL_EXPORT double      yn(int, double);
#endif

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define HUGE            3.40282346638528859812e+38F

MUSL_EXPORT double      drem(double, double);
MUSL_EXPORT float       dremf(float, float);

MUSL_EXPORT int         finite(double);
MUSL_EXPORT int         finitef(float);

MUSL_EXPORT double      scalb(double, double);
MUSL_EXPORT float       scalbf(float, float);

MUSL_EXPORT double      significand(double);
MUSL_EXPORT float       significandf(float);

MUSL_EXPORT double      lgamma_r(double, int*);
MUSL_EXPORT float       lgammaf_r(float, int*);

MUSL_EXPORT float       j0f(float);
MUSL_EXPORT float       j1f(float);
MUSL_EXPORT float       jnf(int, float);

MUSL_EXPORT float       y0f(float);
MUSL_EXPORT float       y1f(float);
MUSL_EXPORT float       ynf(int, float);
#endif

#ifdef _GNU_SOURCE
MUSL_EXPORT long double lgammal_r(long double, int*);

MUSL_EXPORT void        sincos(double, double*, double*);
MUSL_EXPORT void        sincosf(float, float*, float*);
MUSL_EXPORT void        sincosl(long double, long double*, long double*);

MUSL_EXPORT double      exp10(double);
MUSL_EXPORT float       exp10f(float);
MUSL_EXPORT long double exp10l(long double);

MUSL_EXPORT double      pow10(double);
MUSL_EXPORT float       pow10f(float);
MUSL_EXPORT long double pow10l(long double);
#endif

#ifdef __cplusplus
}
#endif

#endif
