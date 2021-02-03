#include <unistd.h>
#include "syscall.h"

MUSL_EXPORT pid_t getpgrp(void)
{
	return __syscall(SYS_getpgid, 0);
}
