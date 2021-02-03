#define _GNU_SOURCE
#include <unistd.h>
#include "syscall.h"

MUSL_EXPORT int sethostname(const char *name, size_t len)
{
	return syscall(SYS_sethostname, name, len);
}
