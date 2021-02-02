#ifndef _NL_TYPES_H
#define _NL_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#define NL_SETD 1
#define NL_CAT_LOCALE 1

typedef int nl_item;
typedef void *nl_catd;

MUSL_EXPORT nl_catd catopen (const char *, int);
MUSL_EXPORT char *catgets (nl_catd, int, int, const char *);
MUSL_EXPORT int catclose (nl_catd);

#ifdef __cplusplus
}
#endif

#endif
