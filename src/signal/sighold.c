#include <signal.h>

MUSL_EXPORT int sighold(int sig)
{
	sigset_t mask;

	sigemptyset(&mask);
	if (sigaddset(&mask, sig) < 0) return -1;
	return sigprocmask(SIG_BLOCK, &mask, 0);
}
