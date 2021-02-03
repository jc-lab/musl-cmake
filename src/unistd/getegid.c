#include <unistd.h>
#include "syscall.h"

MUSL_EXPORT gid_t getegid(void)
{
	return __syscall(SYS_getegid);
}
