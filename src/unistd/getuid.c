#include <unistd.h>
#include "syscall.h"

MUSL_EXPORT uid_t getuid(void)
{
	return __syscall(SYS_getuid);
}
