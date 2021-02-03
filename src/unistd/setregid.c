#include <unistd.h>
#include "syscall.h"
#include "libc.h"

MUSL_EXPORT int setregid(gid_t rgid, gid_t egid)
{
	return __setxid(SYS_setregid, rgid, egid, 0);
}
