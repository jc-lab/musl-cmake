#include <sys/utsname.h>
#include "syscall.h"

MUSL_EXPORT int uname(struct utsname *uts)
{
	return syscall(SYS_uname, uts);
}
