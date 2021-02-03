#include <unistd.h>
#include "syscall.h"

MUSL_EXPORT pid_t setsid(void)
{
	return syscall(SYS_setsid);
}
