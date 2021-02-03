#include <unistd.h>
#include "syscall.h"

MUSL_EXPORT int fsync(int fd)
{
	return syscall_cp(SYS_fsync, fd);
}
