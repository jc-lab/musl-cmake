#define _GNU_SOURCE
#include <unistd.h>
#include "syscall.h"

MUSL_EXPORT int chroot(const char *path)
{
	return syscall(SYS_chroot, path);
}
