#include <signal.h>
#include "syscall.h"

MUSL_EXPORT int kill(pid_t pid, int sig)
{
	return syscall(SYS_kill, pid, sig);
}
