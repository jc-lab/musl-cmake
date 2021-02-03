#include <signal.h>

MUSL_EXPORT int __libc_current_sigrtmax()
{
	return _NSIG-1;
}
