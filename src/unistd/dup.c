#include <unistd.h>
#include "syscall.h"

MUSL_EXPORT int dup(int fd)
{
	return syscall(SYS_dup, fd);
}
