#ifndef _UTMP_H
#define _UTMP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <utmpx.h>

#define ACCOUNTING 9
#define UT_NAMESIZE 32
#define UT_HOSTSIZE 256
#define UT_LINESIZE 32

struct lastlog {
	time_t ll_time;
	char ll_line[UT_LINESIZE];
	char ll_host[UT_HOSTSIZE];
};

#define ut_time ut_tv.tv_sec
#define ut_name ut_user
#define ut_addr ut_addr_v6[0]
#define utmp utmpx
#define e_exit __e_exit
#define e_termination __e_termination

MUSL_EXPORT void         endutent(void);
MUSL_EXPORT struct utmp *getutent(void);
MUSL_EXPORT struct utmp *getutid(const struct utmp *);
MUSL_EXPORT struct utmp *getutline(const struct utmp *);
MUSL_EXPORT struct utmp *pututline(const struct utmp *);
MUSL_EXPORT void         setutent(void);

MUSL_EXPORT void updwtmp(const char *, const struct utmp *);
MUSL_EXPORT int utmpname(const char *);

MUSL_EXPORT int login_tty(int);

#define _PATH_UTMP "/dev/null/utmp"
#define _PATH_WTMP "/dev/null/wtmp"

#define UTMP_FILE _PATH_UTMP
#define WTMP_FILE _PATH_WTMP
#define UTMP_FILENAME _PATH_UTMP
#define WTMP_FILENAME _PATH_WTMP

#ifdef __cplusplus
}
#endif

#endif
