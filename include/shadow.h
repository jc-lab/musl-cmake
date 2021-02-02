#ifndef _SHADOW_H
#define _SHADOW_H

#ifdef __cplusplus
extern "C" {
#endif

#define	__NEED_FILE
#define __NEED_size_t

#include <bits/alltypes.h>

#define	SHADOW "/etc/shadow"

struct spwd {
	char *sp_namp;
	char *sp_pwdp;
	long sp_lstchg;
	long sp_min;
	long sp_max;
	long sp_warn;
	long sp_inact;
	long sp_expire;
	unsigned long sp_flag;
};

MUSL_EXPORT void setspent(void);
MUSL_EXPORT void endspent(void);
MUSL_EXPORT struct spwd *getspent(void);
MUSL_EXPORT struct spwd *fgetspent(FILE *);
MUSL_EXPORT struct spwd *sgetspent(const char *);
MUSL_EXPORT int putspent(const struct spwd *, FILE *);

MUSL_EXPORT struct spwd *getspnam(const char *);
MUSL_EXPORT int getspnam_r(const char *, struct spwd *, char *, size_t, struct spwd **);

MUSL_EXPORT int lckpwdf(void);
MUSL_EXPORT int ulckpwdf(void);

#ifdef __cplusplus
}
#endif

#endif
