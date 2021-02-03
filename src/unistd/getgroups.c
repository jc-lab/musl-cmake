#include <unistd.h>
#include "syscall.h"

MUSL_EXPORT int getgroups(int count, gid_t list[])
{
	return syscall(SYS_getgroups, count, list);
}
