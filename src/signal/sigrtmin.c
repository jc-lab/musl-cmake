#include <signal.h>

MUSL_EXPORT int __libc_current_sigrtmin()
{
	return 35;
}
