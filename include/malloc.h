#ifndef _MALLOC_H
#define _MALLOC_H

#ifdef __cplusplus
extern "C" {
#endif

#define __NEED_size_t

#include <bits/alltypes.h>

MUSL_EXPORT void *malloc (size_t);
MUSL_EXPORT void *calloc (size_t, size_t);
MUSL_EXPORT void *realloc (void *, size_t);
MUSL_EXPORT void free (void *);
MUSL_EXPORT void *valloc (size_t);
MUSL_EXPORT void *memalign(size_t, size_t);

MUSL_EXPORT size_t malloc_usable_size(void *);

#ifdef __cplusplus
}
#endif

#endif
