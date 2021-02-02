#ifndef _ERR_H
#define _ERR_H

#include <features.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

MUSL_EXPORT void warn(const char *, ...);
MUSL_EXPORT void vwarn(const char *, va_list);
MUSL_EXPORT void warnx(const char *, ...);
MUSL_EXPORT void vwarnx(const char *, va_list);

_Noreturn void err(int, const char *, ...);
_Noreturn void verr(int, const char *, va_list);
_Noreturn void errx(int, const char *, ...);
_Noreturn void verrx(int, const char *, va_list);

#ifdef __cplusplus
}
#endif

#endif
