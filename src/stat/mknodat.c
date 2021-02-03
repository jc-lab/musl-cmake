#include <sys/stat.h>
#include "syscall.h"

MUSL_EXPORT int mknodat(int fd, const char *path, mode_t mode, dev_t dev)
{
	return syscall(SYS_mknodat, fd, path, mode, dev);
}
