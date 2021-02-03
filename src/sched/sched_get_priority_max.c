#include <sched.h>
#include "syscall.h"

MUSL_EXPORT int sched_get_priority_max(int policy)
{
	return syscall(SYS_sched_get_priority_max, policy);
}

MUSL_EXPORT int sched_get_priority_min(int policy)
{
	return syscall(SYS_sched_get_priority_min, policy);
}
