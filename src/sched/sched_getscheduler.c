#include <sched.h>
#include <errno.h>
#include "syscall.h"

MUSL_EXPORT int sched_getscheduler(pid_t pid)
{
	return __syscall_ret(-ENOSYS);
}
