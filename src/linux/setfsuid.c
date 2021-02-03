#include <sys/fsuid.h>
#include "syscall.h"

MUSL_EXPORT int setfsuid(uid_t uid)
{
	return syscall(SYS_setfsuid, uid);
}
