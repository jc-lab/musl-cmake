#define _GNU_SOURCE 1
#include <sys/mman.h>
#include "syscall.h"

MUSL_EXPORT int memfd_create(const char *name, unsigned flags)
{
	return syscall(SYS_memfd_create, name, flags);
}
