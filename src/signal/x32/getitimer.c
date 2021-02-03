#include <sys/time.h>
#include "syscall.h"

MUSL_EXPORT int getitimer(int which, struct itimerval *old)
{
	return syscall(SYS_getitimer, which, old);
}
