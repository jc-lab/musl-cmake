#include <unistd.h>
#include "syscall.h"

MUSL_EXPORT pid_t getppid(void)
{
	return __syscall(SYS_getppid);
}
