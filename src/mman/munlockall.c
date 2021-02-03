#include <sys/mman.h>
#include "syscall.h"

MUSL_EXPORT int munlockall(void)
{
	return syscall(SYS_munlockall);
}
