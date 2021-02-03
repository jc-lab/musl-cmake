#include <sys/mman.h>
#include "syscall.h"

MUSL_EXPORT int munlock(const void *addr, size_t len)
{
	return syscall(SYS_munlock, addr, len);
}
