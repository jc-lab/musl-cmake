#include <sys/mman.h>
#include "syscall.h"

MUSL_EXPORT int mlockall(int flags)
{
	return syscall(SYS_mlockall, flags);
}
