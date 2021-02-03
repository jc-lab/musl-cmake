#include <sys/wait.h>
#include "syscall.h"

MUSL_EXPORT pid_t waitpid(pid_t pid, int *status, int options)
{
	return syscall_cp(SYS_wait4, pid, status, options, 0);
}
