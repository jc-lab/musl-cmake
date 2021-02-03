#define _BSD_SOURCE
#include <unistd.h>
#include <errno.h>
#include "syscall.h"

MUSL_EXPORT int brk(void *end)
{
	return __syscall_ret(-ENOMEM);
}
