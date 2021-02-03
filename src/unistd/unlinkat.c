#include <unistd.h>
#include "syscall.h"

MUSL_EXPORT int unlinkat(int fd, const char *path, int flag)
{
	return syscall(SYS_unlinkat, fd, path, flag);
}
