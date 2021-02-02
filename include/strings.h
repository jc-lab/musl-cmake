#ifndef	_STRINGS_H
#define	_STRINGS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>


#define __NEED_size_t
#define __NEED_locale_t
#include <bits/alltypes.h>

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE) || defined(_POSIX_SOURCE) \
 || (defined(_POSIX_C_SOURCE) && _POSIX_C_SOURCE+0 < 200809L) \
 || (defined(_XOPEN_SOURCE) && _XOPEN_SOURCE+0 < 700)
MUSL_EXPORT int bcmp (const void *, const void *, size_t);
MUSL_EXPORT void bcopy (const void *, void *, size_t);
MUSL_EXPORT void bzero (void *, size_t);
MUSL_EXPORT char *index (const char *, int);
MUSL_EXPORT char *rindex (const char *, int);
#endif

#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE)  || defined(_BSD_SOURCE)
MUSL_EXPORT int ffs (int);
MUSL_EXPORT int ffsl (long);
MUSL_EXPORT int ffsll (long long);
#endif

MUSL_EXPORT int strcasecmp (const char *, const char *);
MUSL_EXPORT int strncasecmp (const char *, const char *, size_t);

MUSL_EXPORT int strcasecmp_l (const char *, const char *, locale_t);
MUSL_EXPORT int strncasecmp_l (const char *, const char *, size_t, locale_t);

#ifdef __cplusplus
}
#endif

#endif
