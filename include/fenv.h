#ifndef _FENV_H
#define _FENV_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#include <bits/fenv.h>

MUSL_EXPORT int feclearexcept(int);
MUSL_EXPORT int fegetexceptflag(fexcept_t *, int);
MUSL_EXPORT int feraiseexcept(int);
MUSL_EXPORT int fesetexceptflag(const fexcept_t *, int);
MUSL_EXPORT int fetestexcept(int);

MUSL_EXPORT int fegetround(void);
MUSL_EXPORT int fesetround(int);

MUSL_EXPORT int fegetenv(fenv_t *);
MUSL_EXPORT int feholdexcept(fenv_t *);
MUSL_EXPORT int fesetenv(const fenv_t *);
MUSL_EXPORT int feupdateenv(const fenv_t *);

#ifdef __cplusplus
}
#endif
#endif

