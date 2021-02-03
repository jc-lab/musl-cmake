#include <sched.h>
#include "syscall.h"

MUSL_EXPORT int sched_yield()
{
	return syscall(SYS_sched_yield);
}
