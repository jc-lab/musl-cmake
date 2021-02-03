#include <unistd.h>
#include "syscall.h"

MUSL_EXPORT int fdatasync(int fd)
{
	return syscall_cp(SYS_fdatasync, fd);
}
