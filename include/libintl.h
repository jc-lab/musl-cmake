#ifndef _LIBINTL_H
#define _LIBINTL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#define __USE_GNU_GETTEXT 1
#define __GNU_GETTEXT_SUPPORTED_REVISION(major) ((major) == 0 ? 1 : -1)

#if __GNUC__ >= 3
#define __fa(n) __attribute__ ((__format_arg__ (n)))
#else
#define __fa(n)
#endif

MUSL_EXPORT char *gettext(const char *) __fa(1);
MUSL_EXPORT char *dgettext(const char *, const char *) __fa(2);
MUSL_EXPORT char *dcgettext(const char *, const char *, int) __fa(2);
MUSL_EXPORT char *ngettext(const char *, const char *, unsigned long) __fa(1) __fa(2);
MUSL_EXPORT char *dngettext(const char *, const char *, const char *, unsigned long) __fa(2) __fa(3);
MUSL_EXPORT char *dcngettext(const char *, const char *, const char *, unsigned long, int) __fa(2) __fa(3);
MUSL_EXPORT char *textdomain(const char *);
MUSL_EXPORT char *bindtextdomain (const char *, const char *);
MUSL_EXPORT char *bind_textdomain_codeset(const char *, const char *);

#undef __fa

#ifdef __cplusplus
}
#endif

#endif
