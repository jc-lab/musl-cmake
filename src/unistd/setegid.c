#include <unistd.h>
#include "libc.h"
#include "syscall.h"

MUSL_EXPORT int setegid(gid_t egid)
{
	return __setxid(SYS_setresgid, -1, egid, -1);
}
