#include <sys/stat.h>
#include "syscall.h"

MUSL_EXPORT int mkdirat(int fd, const char *path, mode_t mode)
{
	return syscall(SYS_mkdirat, fd, path, mode);
}
