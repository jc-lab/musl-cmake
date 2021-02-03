#include <stdlib.h>
#include "syscall.h"

MUSL_WEAK _Noreturn void _Exit(int ec)
{
	__syscall(SYS_exit_group, ec);
	for (;;) __syscall(SYS_exit, ec);
}
