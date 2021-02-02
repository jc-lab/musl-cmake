#ifndef _WCHAR_H
#define _WCHAR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#define __NEED_FILE
#define __NEED___isoc_va_list
#define __NEED_size_t
#define __NEED_wchar_t
#define __NEED_wint_t
#define __NEED_mbstate_t

#if __STDC_VERSION__ < 201112L
#define __NEED_struct__IO_FILE
#endif

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define __NEED_locale_t
#define __NEED_va_list
#endif

#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define __NEED_wctype_t
#endif

#include <bits/alltypes.h>

#if L'\0'-1 > 0
#define WCHAR_MAX (0xffffffffu+L'\0')
#define WCHAR_MIN (0+L'\0')
#else
#define WCHAR_MAX (0x7fffffff+L'\0')
#define WCHAR_MIN (-1-0x7fffffff+L'\0')
#endif

#ifdef __cplusplus
#define NULL 0L
#else
#define NULL ((void*)0)
#endif

#undef WEOF
#define WEOF 0xffffffffU

MUSL_EXPORT wchar_t *wcscpy (wchar_t *__restrict, const wchar_t *__restrict);
MUSL_EXPORT wchar_t *wcsncpy (wchar_t *__restrict, const wchar_t *__restrict, size_t);

MUSL_EXPORT wchar_t *wcscat (wchar_t *__restrict, const wchar_t *__restrict);
MUSL_EXPORT wchar_t *wcsncat (wchar_t *__restrict, const wchar_t *__restrict, size_t);

MUSL_EXPORT int wcscmp (const wchar_t *, const wchar_t *);
MUSL_EXPORT int wcsncmp (const wchar_t *, const wchar_t *, size_t);

MUSL_EXPORT int wcscoll(const wchar_t *, const wchar_t *);
MUSL_EXPORT size_t wcsxfrm (wchar_t *__restrict, const wchar_t *__restrict, size_t);

MUSL_EXPORT wchar_t *wcschr (const wchar_t *, wchar_t);
MUSL_EXPORT wchar_t *wcsrchr (const wchar_t *, wchar_t);

MUSL_EXPORT size_t wcscspn (const wchar_t *, const wchar_t *);
MUSL_EXPORT size_t wcsspn (const wchar_t *, const wchar_t *);
MUSL_EXPORT wchar_t *wcspbrk (const wchar_t *, const wchar_t *);

MUSL_EXPORT wchar_t *wcstok (wchar_t *__restrict, const wchar_t *__restrict, wchar_t **__restrict);

MUSL_EXPORT size_t wcslen (const wchar_t *);

MUSL_EXPORT wchar_t *wcsstr (const wchar_t *__restrict, const wchar_t *__restrict);
MUSL_EXPORT wchar_t *wcswcs (const wchar_t *, const wchar_t *);

MUSL_EXPORT wchar_t *wmemchr (const wchar_t *, wchar_t, size_t);
MUSL_EXPORT int wmemcmp (const wchar_t *, const wchar_t *, size_t);
MUSL_EXPORT wchar_t *wmemcpy (wchar_t *__restrict, const wchar_t *__restrict, size_t);
MUSL_EXPORT wchar_t *wmemmove (wchar_t *, const wchar_t *, size_t);
MUSL_EXPORT wchar_t *wmemset (wchar_t *, wchar_t, size_t);

MUSL_EXPORT wint_t btowc (int);
MUSL_EXPORT int wctob (wint_t);

MUSL_EXPORT int mbsinit (const mbstate_t *);
MUSL_EXPORT size_t mbrtowc (wchar_t *__restrict, const char *__restrict, size_t, mbstate_t *__restrict);
MUSL_EXPORT size_t wcrtomb (char *__restrict, wchar_t, mbstate_t *__restrict);

MUSL_EXPORT size_t mbrlen (const char *__restrict, size_t, mbstate_t *__restrict);

MUSL_EXPORT size_t mbsrtowcs (wchar_t *__restrict, const char **__restrict, size_t, mbstate_t *__restrict);
MUSL_EXPORT size_t wcsrtombs (char *__restrict, const wchar_t **__restrict, size_t, mbstate_t *__restrict);

MUSL_EXPORT float wcstof (const wchar_t *__restrict, wchar_t **__restrict);
MUSL_EXPORT double wcstod (const wchar_t *__restrict, wchar_t **__restrict);
MUSL_EXPORT long double wcstold (const wchar_t *__restrict, wchar_t **__restrict);

MUSL_EXPORT long wcstol (const wchar_t *__restrict, wchar_t **__restrict, int);
MUSL_EXPORT unsigned long wcstoul (const wchar_t *__restrict, wchar_t **__restrict, int);

MUSL_EXPORT long long wcstoll (const wchar_t *__restrict, wchar_t **__restrict, int);
MUSL_EXPORT unsigned long long wcstoull (const wchar_t *__restrict, wchar_t **__restrict, int);



MUSL_EXPORT int fwide (FILE *, int);


MUSL_EXPORT int wprintf (const wchar_t *__restrict, ...);
MUSL_EXPORT int fwprintf (FILE *__restrict, const wchar_t *__restrict, ...);
MUSL_EXPORT int swprintf (wchar_t *__restrict, size_t, const wchar_t *__restrict, ...);

MUSL_EXPORT int vwprintf (const wchar_t *__restrict, __isoc_va_list);
MUSL_EXPORT int vfwprintf (FILE *__restrict, const wchar_t *__restrict, __isoc_va_list);
MUSL_EXPORT int vswprintf (wchar_t *__restrict, size_t, const wchar_t *__restrict, __isoc_va_list);

MUSL_EXPORT int wscanf (const wchar_t *__restrict, ...);
MUSL_EXPORT int fwscanf (FILE *__restrict, const wchar_t *__restrict, ...);
MUSL_EXPORT int swscanf (const wchar_t *__restrict, const wchar_t *__restrict, ...);

MUSL_EXPORT int vwscanf (const wchar_t *__restrict, __isoc_va_list);
MUSL_EXPORT int vfwscanf (FILE *__restrict, const wchar_t *__restrict, __isoc_va_list);
MUSL_EXPORT int vswscanf (const wchar_t *__restrict, const wchar_t *__restrict, __isoc_va_list);

MUSL_EXPORT wint_t fgetwc (FILE *);
MUSL_EXPORT wint_t getwc (FILE *);
MUSL_EXPORT wint_t getwchar (void);

MUSL_EXPORT wint_t fputwc (wchar_t, FILE *);
MUSL_EXPORT wint_t putwc (wchar_t, FILE *);
MUSL_EXPORT wint_t putwchar (wchar_t);

MUSL_EXPORT wchar_t *fgetws (wchar_t *__restrict, int, FILE *__restrict);
MUSL_EXPORT int fputws (const wchar_t *__restrict, FILE *__restrict);

MUSL_EXPORT wint_t ungetwc (wint_t, FILE *);

struct tm;
MUSL_EXPORT size_t wcsftime (wchar_t *__restrict, size_t, const wchar_t *__restrict, const struct tm *__restrict);

#undef iswdigit

#if defined(_GNU_SOURCE)
MUSL_EXPORT wint_t fgetwc_unlocked (FILE *);
MUSL_EXPORT wint_t getwc_unlocked (FILE *);
MUSL_EXPORT wint_t getwchar_unlocked (void);
MUSL_EXPORT wint_t fputwc_unlocked (wchar_t, FILE *);
MUSL_EXPORT wint_t putwc_unlocked (wchar_t, FILE *);
MUSL_EXPORT wint_t putwchar_unlocked (wchar_t);
MUSL_EXPORT wchar_t *fgetws_unlocked (wchar_t *__restrict, int, FILE *__restrict);
MUSL_EXPORT int fputws_unlocked (const wchar_t *__restrict, FILE *__restrict);
#endif

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
MUSL_EXPORT size_t wcsftime_l (wchar_t *__restrict, size_t, const wchar_t *__restrict, const struct tm *__restrict, locale_t);
#endif

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE)  || defined(_BSD_SOURCE)
MUSL_EXPORT FILE *open_wmemstream(wchar_t **, size_t *);
MUSL_EXPORT size_t mbsnrtowcs(wchar_t *__restrict, const char **__restrict, size_t, size_t, mbstate_t *__restrict);
MUSL_EXPORT size_t wcsnrtombs(char *__restrict, const wchar_t **__restrict, size_t, size_t, mbstate_t *__restrict);
MUSL_EXPORT wchar_t *wcsdup(const wchar_t *);
MUSL_EXPORT size_t wcsnlen (const wchar_t *, size_t);
MUSL_EXPORT wchar_t *wcpcpy (wchar_t *__restrict, const wchar_t *__restrict);
MUSL_EXPORT wchar_t *wcpncpy (wchar_t *__restrict, const wchar_t *__restrict, size_t);
MUSL_EXPORT int wcscasecmp(const wchar_t *, const wchar_t *);
MUSL_EXPORT int wcscasecmp_l(const wchar_t *, const wchar_t *, locale_t);
MUSL_EXPORT int wcsncasecmp(const wchar_t *, const wchar_t *, size_t);
MUSL_EXPORT int wcsncasecmp_l(const wchar_t *, const wchar_t *, size_t, locale_t);
MUSL_EXPORT int wcscoll_l(const wchar_t *, const wchar_t *, locale_t);
MUSL_EXPORT size_t wcsxfrm_l(wchar_t *__restrict, const wchar_t *__restrict, size_t, locale_t);
#endif

#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
MUSL_EXPORT int wcwidth (wchar_t);
MUSL_EXPORT int wcswidth (const wchar_t *, size_t);
MUSL_EXPORT int       iswalnum(wint_t);
MUSL_EXPORT int       iswalpha(wint_t);
MUSL_EXPORT int       iswblank(wint_t);
MUSL_EXPORT int       iswcntrl(wint_t);
MUSL_EXPORT int       iswdigit(wint_t);
MUSL_EXPORT int       iswgraph(wint_t);
MUSL_EXPORT int       iswlower(wint_t);
MUSL_EXPORT int       iswprint(wint_t);
MUSL_EXPORT int       iswpunct(wint_t);
MUSL_EXPORT int       iswspace(wint_t);
MUSL_EXPORT int       iswupper(wint_t);
MUSL_EXPORT int       iswxdigit(wint_t);
MUSL_EXPORT int       iswctype(wint_t, wctype_t);
MUSL_EXPORT wint_t    towlower(wint_t);
MUSL_EXPORT wint_t    towupper(wint_t);
MUSL_EXPORT wctype_t  wctype(const char *);

#ifndef __cplusplus
#undef iswdigit
#define iswdigit(a) (0 ? iswdigit(a) : ((unsigned)(a)-'0') < 10)
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
