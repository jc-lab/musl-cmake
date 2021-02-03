#include <signal.h>
#include "syscall.h"

MUSL_EXPORT int sigpending(sigset_t *set)
{
	return syscall(SYS_rt_sigpending, set, _NSIG/8);
}
