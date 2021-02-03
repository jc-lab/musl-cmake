#include <signal.h>
#include "syscall.h"

MUSL_EXPORT int sigsuspend(const sigset_t *mask)
{
	return syscall_cp(SYS_rt_sigsuspend, mask, _NSIG/8);
}
