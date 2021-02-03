#include <sys/swap.h>
#include "syscall.h"

MUSL_EXPORT int swapon(const char *path, int flags)
{
	return syscall(SYS_swapon, path, flags);
}

MUSL_EXPORT int swapoff(const char *path)
{
	return syscall(SYS_swapoff, path);
}
