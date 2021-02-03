#include <sys/file.h>
#include "syscall.h"

MUSL_EXPORT int flock(int fd, int op)
{
	return syscall(SYS_flock, fd, op);
}
