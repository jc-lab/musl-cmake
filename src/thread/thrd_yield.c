#include <threads.h>
#include "syscall.h"

MUSL_EXPORT void thrd_yield()
{
	__syscall(SYS_sched_yield);
}
