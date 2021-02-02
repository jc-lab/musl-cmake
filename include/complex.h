#ifndef _COMPLEX_H
#define _COMPLEX_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#define complex _Complex
#ifdef __GNUC__
#define _Complex_I (__extension__ (0.0f+1.0fi))
#else
#define _Complex_I (0.0f+1.0fi)
#endif
#define I _Complex_I

MUSL_EXPORT double complex cacos(double complex);
MUSL_EXPORT float complex cacosf(float complex);
MUSL_EXPORT long double complex cacosl(long double complex);

MUSL_EXPORT double complex casin(double complex);
MUSL_EXPORT float complex casinf(float complex);
MUSL_EXPORT long double complex casinl(long double complex);

MUSL_EXPORT double complex catan(double complex);
MUSL_EXPORT float complex catanf(float complex);
MUSL_EXPORT long double complex catanl(long double complex);

MUSL_EXPORT double complex ccos(double complex);
MUSL_EXPORT float complex ccosf(float complex);
MUSL_EXPORT long double complex ccosl(long double complex);

MUSL_EXPORT double complex csin(double complex);
MUSL_EXPORT float complex csinf(float complex);
MUSL_EXPORT long double complex csinl(long double complex);

MUSL_EXPORT double complex ctan(double complex);
MUSL_EXPORT float complex ctanf(float complex);
MUSL_EXPORT long double complex ctanl(long double complex);

MUSL_EXPORT double complex cacosh(double complex);
MUSL_EXPORT float complex cacoshf(float complex);
MUSL_EXPORT long double complex cacoshl(long double complex);

MUSL_EXPORT double complex casinh(double complex);
MUSL_EXPORT float complex casinhf(float complex);
MUSL_EXPORT long double complex casinhl(long double complex);

MUSL_EXPORT double complex catanh(double complex);
MUSL_EXPORT float complex catanhf(float complex);
MUSL_EXPORT long double complex catanhl(long double complex);

MUSL_EXPORT double complex ccosh(double complex);
MUSL_EXPORT float complex ccoshf(float complex);
MUSL_EXPORT long double complex ccoshl(long double complex);

MUSL_EXPORT double complex csinh(double complex);
MUSL_EXPORT float complex csinhf(float complex);
MUSL_EXPORT long double complex csinhl(long double complex);

MUSL_EXPORT double complex ctanh(double complex);
MUSL_EXPORT float complex ctanhf(float complex);
MUSL_EXPORT long double complex ctanhl(long double complex);

MUSL_EXPORT double complex cexp(double complex);
MUSL_EXPORT float complex cexpf(float complex);
MUSL_EXPORT long double complex cexpl(long double complex);

MUSL_EXPORT double complex clog(double complex);
MUSL_EXPORT float complex clogf(float complex);
MUSL_EXPORT long double complex clogl(long double complex);

MUSL_EXPORT double cabs(double complex);
MUSL_EXPORT float cabsf(float complex);
MUSL_EXPORT long double cabsl(long double complex);

MUSL_EXPORT double complex cpow(double complex, double complex);
MUSL_EXPORT float complex cpowf(float complex, float complex);
MUSL_EXPORT long double complex cpowl(long double complex, long double complex);

MUSL_EXPORT double complex csqrt(double complex);
MUSL_EXPORT float complex csqrtf(float complex);
MUSL_EXPORT long double complex csqrtl(long double complex);

MUSL_EXPORT double carg(double complex);
MUSL_EXPORT float cargf(float complex);
MUSL_EXPORT long double cargl(long double complex);

MUSL_EXPORT double cimag(double complex);
MUSL_EXPORT float cimagf(float complex);
MUSL_EXPORT long double cimagl(long double complex);

MUSL_EXPORT double complex conj(double complex);
MUSL_EXPORT float complex conjf(float complex);
MUSL_EXPORT long double complex conjl(long double complex);

MUSL_EXPORT double complex cproj(double complex);
MUSL_EXPORT float complex cprojf(float complex);
MUSL_EXPORT long double complex cprojl(long double complex);

MUSL_EXPORT double creal(double complex);
MUSL_EXPORT float crealf(float complex);
MUSL_EXPORT long double creall(long double complex);

#ifndef __cplusplus
#define __CIMAG(x, t) \
	(+(union { _Complex t __z; t __xy[2]; }){(_Complex t)(x)}.__xy[1])

#define creal(x) ((double)(x))
#define crealf(x) ((float)(x))
#define creall(x) ((long double)(x))

#define cimag(x) __CIMAG(x, double)
#define cimagf(x) __CIMAG(x, float)
#define cimagl(x) __CIMAG(x, long double)
#endif

#if __STDC_VERSION__ >= 201112L
#if defined(_Imaginary_I)
#define __CMPLX(x, y, t) ((t)(x) + _Imaginary_I*(t)(y))
#elif defined(__clang__)
#define __CMPLX(x, y, t) (+(_Complex t){ (t)(x), (t)(y) })
#else
#define __CMPLX(x, y, t) (__builtin_complex((t)(x), (t)(y)))
#endif
#define CMPLX(x, y) __CMPLX(x, y, double)
#define CMPLXF(x, y) __CMPLX(x, y, float)
#define CMPLXL(x, y) __CMPLX(x, y, long double)
#endif

#ifdef __cplusplus
}
#endif
#endif
