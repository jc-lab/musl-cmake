#include <unistd.h>
#include "syscall.h"

MUSL_EXPORT pid_t getpid(void)
{
	return __syscall(SYS_getpid);
}
