#include <sys/fsuid.h>
#include "syscall.h"

MUSL_EXPORT int setfsgid(gid_t gid)
{
	return syscall(SYS_setfsgid, gid);
}
