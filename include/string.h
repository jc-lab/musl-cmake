#ifndef	_STRING_H
#define	_STRING_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#ifdef __cplusplus
#define NULL 0L
#else
#define NULL ((void*)0)
#endif

#define __NEED_size_t
#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) \
 || defined(_BSD_SOURCE)
#define __NEED_locale_t
#endif

#include <bits/alltypes.h>

MUSL_EXPORT void *memcpy (void *__restrict, const void *__restrict, size_t);
MUSL_EXPORT void *memmove (void *, const void *, size_t);
MUSL_EXPORT void *memset (void *, int, size_t);
MUSL_EXPORT int memcmp (const void *, const void *, size_t);
MUSL_EXPORT void *memchr (const void *, int, size_t);

MUSL_EXPORT char *strcpy (char *__restrict, const char *__restrict);
MUSL_EXPORT char *strncpy (char *__restrict, const char *__restrict, size_t);

MUSL_EXPORT char *strcat (char *__restrict, const char *__restrict);
MUSL_EXPORT char *strncat (char *__restrict, const char *__restrict, size_t);

MUSL_EXPORT int strcmp (const char *, const char *);
MUSL_EXPORT int strncmp (const char *, const char *, size_t);

MUSL_EXPORT int strcoll (const char *, const char *);
MUSL_EXPORT size_t strxfrm (char *__restrict, const char *__restrict, size_t);

MUSL_EXPORT char *strchr (const char *, int);
MUSL_EXPORT char *strrchr (const char *, int);

MUSL_EXPORT size_t strcspn (const char *, const char *);
MUSL_EXPORT size_t strspn (const char *, const char *);
MUSL_EXPORT char *strpbrk (const char *, const char *);
MUSL_EXPORT char *strstr (const char *, const char *);
MUSL_EXPORT char *strtok (char *__restrict, const char *__restrict);

MUSL_EXPORT size_t strlen (const char *);

MUSL_EXPORT char *strerror (int);

#if defined(_BSD_SOURCE) || defined(_GNU_SOURCE)
#include <strings.h>
#endif

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) \
 || defined(_BSD_SOURCE)
MUSL_EXPORT char *strtok_r (char *__restrict, const char *__restrict, char **__restrict);
MUSL_EXPORT int strerror_r (int, char *, size_t);
MUSL_EXPORT char *stpcpy(char *__restrict, const char *__restrict);
MUSL_EXPORT char *stpncpy(char *__restrict, const char *__restrict, size_t);
MUSL_EXPORT size_t strnlen (const char *, size_t);
MUSL_EXPORT char *strdup (const char *);
MUSL_EXPORT char *strndup (const char *, size_t);
MUSL_EXPORT char *strsignal(int);
MUSL_EXPORT char *strerror_l (int, locale_t);
MUSL_EXPORT int strcoll_l (const char *, const char *, locale_t);
MUSL_EXPORT size_t strxfrm_l (char *__restrict, const char *__restrict, size_t, locale_t);
#endif

#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) \
 || defined(_BSD_SOURCE)
MUSL_EXPORT void *memccpy (void *__restrict, const void *__restrict, int, size_t);
#endif

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
MUSL_EXPORT char *strsep(char **, const char *);
MUSL_EXPORT size_t strlcat (char *, const char *, size_t);
MUSL_EXPORT size_t strlcpy (char *, const char *, size_t);
MUSL_EXPORT void explicit_bzero (void *, size_t);
#endif

#ifdef _GNU_SOURCE
#define	strdupa(x)	strcpy(alloca(strlen(x)+1),x)
MUSL_EXPORT int strverscmp (const char *, const char *);
MUSL_EXPORT char *strchrnul(const char *, int);
MUSL_EXPORT char *strcasestr(const char *, const char *);
MUSL_EXPORT void *memmem(const void *, size_t, const void *, size_t);
MUSL_EXPORT void *memrchr(const void *, int, size_t);
MUSL_EXPORT void *mempcpy(void *, const void *, size_t);
#ifndef __cplusplus
MUSL_EXPORT char *basename();
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
