#include <unistd.h>
#include "syscall.h"

MUSL_EXPORT gid_t getgid(void)
{
	return __syscall(SYS_getgid);
}
