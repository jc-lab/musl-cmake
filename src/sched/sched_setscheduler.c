#include <sched.h>
#include <errno.h>
#include "syscall.h"

MUSL_EXPORT int sched_setscheduler(pid_t pid, int sched, const struct sched_param *param)
{
	return __syscall_ret(-ENOSYS);
}
