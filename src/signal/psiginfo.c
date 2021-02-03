#include <signal.h>

MUSL_EXPORT void psiginfo(const siginfo_t *si, const char *msg)
{
	psignal(si->si_signo, msg);
}
