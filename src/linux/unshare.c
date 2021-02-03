#define _GNU_SOURCE
#include <sched.h>
#include "syscall.h"

MUSL_EXPORT int unshare(int flags)
{
	return syscall(SYS_unshare, flags);
}
