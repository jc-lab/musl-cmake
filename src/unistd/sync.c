#include <unistd.h>
#include "syscall.h"

MUSL_EXPORT void sync(void)
{
	__syscall(SYS_sync);
}
