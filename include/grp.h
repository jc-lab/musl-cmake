#ifndef	_GRP_H
#define	_GRP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#define __NEED_size_t
#define __NEED_gid_t

#ifdef _GNU_SOURCE
#define __NEED_FILE
#endif

#include <bits/alltypes.h>

struct group {
	char *gr_name;
	char *gr_passwd;
	gid_t gr_gid;
	char **gr_mem;
};

MUSL_EXPORT struct group  *getgrgid(gid_t);
MUSL_EXPORT struct group  *getgrnam(const char *);

MUSL_EXPORT int getgrgid_r(gid_t, struct group *, char *, size_t, struct group **);
MUSL_EXPORT int getgrnam_r(const char *, struct group *, char *, size_t, struct group **);

#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
MUSL_EXPORT struct group  *getgrent(void);
MUSL_EXPORT void           endgrent(void);
MUSL_EXPORT void           setgrent(void);
#endif

#ifdef _GNU_SOURCE
MUSL_EXPORT struct group  *fgetgrent(FILE *);
MUSL_EXPORT int putgrent(const struct group *, FILE *);
#endif

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
MUSL_EXPORT int getgrouplist(const char *, gid_t, gid_t *, int *);
MUSL_EXPORT int setgroups(size_t, const gid_t *);
MUSL_EXPORT int initgroups(const char *, gid_t);
#endif

#ifdef __cplusplus
}
#endif

#endif
