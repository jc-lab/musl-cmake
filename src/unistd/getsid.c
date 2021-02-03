#include <unistd.h>
#include "syscall.h"

MUSL_EXPORT pid_t getsid(pid_t pid)
{
	return syscall(SYS_getsid, pid);
}
