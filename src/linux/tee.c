#define _GNU_SOURCE
#include <fcntl.h>
#include "syscall.h"

MUSL_EXPORT ssize_t tee(int src, int dest, size_t len, unsigned flags)
{
	return syscall(SYS_tee, src, dest, len, flags);
}
