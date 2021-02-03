#define _GNU_SOURCE
#include <unistd.h>
#include "syscall.h"
#include "libc.h"

MUSL_EXPORT int setresgid(gid_t rgid, gid_t egid, gid_t sgid)
{
	return __setxid(SYS_setresgid, rgid, egid, sgid);
}
