#include <sched.h>
#include <errno.h>
#include "syscall.h"

MUSL_EXPORT int sched_getparam(pid_t pid, struct sched_param *param)
{
	return __syscall_ret(-ENOSYS);
}
