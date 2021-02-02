#ifndef _WCTYPE_H
#define _WCTYPE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#define __NEED_wint_t
#define __NEED_wctype_t

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define __NEED_locale_t
#endif

#include <bits/alltypes.h>

typedef const int * wctrans_t;

#undef WEOF
#define WEOF 0xffffffffU

#undef iswdigit

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
MUSL_EXPORT wint_t    towctrans(wint_t, wctrans_t);
MUSL_EXPORT wint_t    towlower(wint_t);
MUSL_EXPORT wint_t    towupper(wint_t);
MUSL_EXPORT wctrans_t wctrans(const char *);
MUSL_EXPORT wctype_t  wctype(const char *);

#ifndef __cplusplus
#undef iswdigit
#define iswdigit(a) (0 ? iswdigit(a) : ((unsigned)(a)-'0') < 10)
#endif

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)

MUSL_EXPORT int iswalnum_l(wint_t, locale_t);
MUSL_EXPORT int iswalpha_l(wint_t, locale_t);
MUSL_EXPORT int iswblank_l(wint_t, locale_t);
MUSL_EXPORT int iswcntrl_l(wint_t, locale_t);
MUSL_EXPORT int iswdigit_l(wint_t, locale_t);
MUSL_EXPORT int iswgraph_l(wint_t, locale_t);
MUSL_EXPORT int iswlower_l(wint_t, locale_t);
MUSL_EXPORT int iswprint_l(wint_t, locale_t);
MUSL_EXPORT int iswpunct_l(wint_t, locale_t);
MUSL_EXPORT int iswspace_l(wint_t, locale_t);
MUSL_EXPORT int iswupper_l(wint_t, locale_t);
MUSL_EXPORT int iswxdigit_l(wint_t, locale_t);
MUSL_EXPORT int iswctype_l(wint_t, wctype_t, locale_t);
MUSL_EXPORT wint_t towlower_l(wint_t, locale_t);
MUSL_EXPORT wint_t towupper_l(wint_t, locale_t);
MUSL_EXPORT wint_t towctrans_l(wint_t, wctrans_t, locale_t);
MUSL_EXPORT wctrans_t wctrans_l(const char *, locale_t);
MUSL_EXPORT wctype_t  wctype_l(const char *, locale_t);

#endif

#ifdef __cplusplus
}
#endif

#endif
