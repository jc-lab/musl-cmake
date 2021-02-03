#include <sched.h>
#include <errno.h>
#include "syscall.h"

MUSL_EXPORT int sched_setparam(pid_t pid, const struct sched_param *param)
{
	return __syscall_ret(-ENOSYS);
}
