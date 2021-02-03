#define _GNU_SOURCE
#include <unistd.h>
#include "syscall.h"

MUSL_EXPORT int vhangup(void)
{
	return syscall(SYS_vhangup);
}
