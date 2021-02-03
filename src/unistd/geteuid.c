#include <unistd.h>
#include "syscall.h"

MUSL_EXPORT uid_t geteuid(void)
{
	return __syscall(SYS_geteuid);
}
