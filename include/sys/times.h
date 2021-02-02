#ifndef	_SYS_TIMES_H
#define	_SYS_TIMES_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#define __NEED_clock_t
#include <bits/alltypes.h>

struct tms {
	clock_t tms_utime;
	clock_t tms_stime;
	clock_t tms_cutime;
	clock_t tms_cstime;
};

MUSL_EXPORT clock_t times (struct tms *);

#ifdef __cplusplus
}
#endif

#endif

