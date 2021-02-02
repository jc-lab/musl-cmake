#ifndef _ICONV_H
#define _ICONV_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#define __NEED_size_t

#include <bits/alltypes.h>

typedef void *iconv_t;

MUSL_EXPORT iconv_t iconv_open(const char *, const char *);
MUSL_EXPORT size_t iconv(iconv_t, char **__restrict, size_t *__restrict, char **__restrict, size_t *__restrict);
MUSL_EXPORT int iconv_close(iconv_t);

#ifdef __cplusplus
}
#endif

#endif
