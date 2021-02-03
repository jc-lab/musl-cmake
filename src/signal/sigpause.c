#include <signal.h>

MUSL_EXPORT int sigpause(int sig)
{
	sigset_t mask;
	sigprocmask(0, 0, &mask);
	sigdelset(&mask, sig);
	return sigsuspend(&mask);
}
