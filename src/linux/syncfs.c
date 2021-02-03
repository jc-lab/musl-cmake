#define _GNU_SOURCE
#include <unistd.h>
#include "syscall.h"

MUSL_EXPORT int syncfs(int fd)
{
	return syscall(SYS_syncfs, fd);
}
