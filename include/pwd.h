#ifndef _PWD_H
#define _PWD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#define __NEED_size_t
#define __NEED_uid_t
#define __NEED_gid_t

#ifdef _GNU_SOURCE
#define __NEED_FILE
#endif

#include <bits/alltypes.h>

struct passwd {
	char *pw_name;
	char *pw_passwd;
	uid_t pw_uid;
	gid_t pw_gid;
	char *pw_gecos;
	char *pw_dir;
	char *pw_shell;
};

#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
MUSL_EXPORT void setpwent (void);
MUSL_EXPORT void endpwent (void);
MUSL_EXPORT struct passwd *getpwent (void);
#endif

MUSL_EXPORT struct passwd *getpwuid (uid_t);
MUSL_EXPORT struct passwd *getpwnam (const char *);
MUSL_EXPORT int getpwuid_r (uid_t, struct passwd *, char *, size_t, struct passwd **);
MUSL_EXPORT int getpwnam_r (const char *, struct passwd *, char *, size_t, struct passwd **);

#ifdef _GNU_SOURCE
MUSL_EXPORT struct passwd *fgetpwent(FILE *);
MUSL_EXPORT int putpwent(const struct passwd *, FILE *);
#endif

#ifdef __cplusplus
}
#endif

#endif
