#ifndef	_CTYPE_H
#define	_CTYPE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

MUSL_EXPORT int   isalnum(int);
MUSL_EXPORT int   isalpha(int);
MUSL_EXPORT int   isblank(int);
MUSL_EXPORT int   iscntrl(int);
MUSL_EXPORT int   isdigit(int);
MUSL_EXPORT int   isgraph(int);
MUSL_EXPORT int   islower(int);
MUSL_EXPORT int   isprint(int);
MUSL_EXPORT int   ispunct(int);
MUSL_EXPORT int   isspace(int);
MUSL_EXPORT int   isupper(int);
MUSL_EXPORT int   isxdigit(int);
MUSL_EXPORT int   tolower(int);
MUSL_EXPORT int   toupper(int);

#ifndef __cplusplus
static __inline int __isspace(int _c)
{
	return _c == ' ' || (unsigned)_c-'\t' < 5;
}

#define isalpha(a) (0 ? isalpha(a) : (((unsigned)(a)|32)-'a') < 26)
#define isdigit(a) (0 ? isdigit(a) : ((unsigned)(a)-'0') < 10)
#define islower(a) (0 ? islower(a) : ((unsigned)(a)-'a') < 26)
#define isupper(a) (0 ? isupper(a) : ((unsigned)(a)-'A') < 26)
#define isprint(a) (0 ? isprint(a) : ((unsigned)(a)-0x20) < 0x5f)
#define isgraph(a) (0 ? isgraph(a) : ((unsigned)(a)-0x21) < 0x5e)
#define isspace(a) __isspace(a)
#endif


#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) \
 || defined(_BSD_SOURCE)

#define __NEED_locale_t
#include <bits/alltypes.h>

MUSL_EXPORT int   isalnum_l(int, locale_t);
MUSL_EXPORT int   isalpha_l(int, locale_t);
MUSL_EXPORT int   isblank_l(int, locale_t);
MUSL_EXPORT int   iscntrl_l(int, locale_t);
MUSL_EXPORT int   isdigit_l(int, locale_t);
MUSL_EXPORT int   isgraph_l(int, locale_t);
MUSL_EXPORT int   islower_l(int, locale_t);
MUSL_EXPORT int   isprint_l(int, locale_t);
MUSL_EXPORT int   ispunct_l(int, locale_t);
MUSL_EXPORT int   isspace_l(int, locale_t);
MUSL_EXPORT int   isupper_l(int, locale_t);
MUSL_EXPORT int   isxdigit_l(int, locale_t);
MUSL_EXPORT int   tolower_l(int, locale_t);
MUSL_EXPORT int   toupper_l(int, locale_t);

MUSL_EXPORT int   isascii(int);
MUSL_EXPORT int   toascii(int);
#define _tolower(a) ((a)|0x20)
#define _toupper(a) ((a)&0x5f)
#define isascii(a) (0 ? isascii(a) : (unsigned)(a) < 128)

#endif

#ifdef __cplusplus
}
#endif

#endif
