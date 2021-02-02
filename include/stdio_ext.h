#ifndef _STDIO_EXT_H
#define _STDIO_EXT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#define FSETLOCKING_QUERY 0
#define FSETLOCKING_INTERNAL 1
#define FSETLOCKING_BYCALLER 2

MUSL_EXPORT void _flushlbf(void);
MUSL_EXPORT int __fsetlocking(FILE *, int);
MUSL_EXPORT int __fwriting(FILE *);
MUSL_EXPORT int __freading(FILE *);
MUSL_EXPORT int __freadable(FILE *);
MUSL_EXPORT int __fwritable(FILE *);
MUSL_EXPORT int __flbf(FILE *);
MUSL_EXPORT size_t __fbufsize(FILE *);
MUSL_EXPORT size_t __fpending(FILE *);
MUSL_EXPORT int __fpurge(FILE *);

MUSL_EXPORT size_t __freadahead(FILE *);
MUSL_EXPORT const char *__freadptr(FILE *, size_t *);
MUSL_EXPORT void __freadptrinc(FILE *, size_t);
MUSL_EXPORT void __fseterr(FILE *);

#ifdef __cplusplus
}
#endif

#endif
