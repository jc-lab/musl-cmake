#include <sys/times.h>
#include "syscall.h"

MUSL_EXPORT clock_t times(struct tms *tms)
{
	return __syscall(SYS_times, tms);
}
