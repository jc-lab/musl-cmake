#define _GNU_SOURCE
#include <unistd.h>
#include "syscall.h"

MUSL_EXPORT int getresgid(gid_t *rgid, gid_t *egid, gid_t *sgid)
{
	return syscall(SYS_getresgid, rgid, egid, sgid);
}
