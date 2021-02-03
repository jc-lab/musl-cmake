#define _GNU_SOURCE
#include <signal.h>
#include <string.h>

MUSL_EXPORT int sigisemptyset(const sigset_t *set)
{
	for (size_t i=0; i<_NSIG/8/sizeof *set->__bits; i++)
		if (set->__bits[i]) return 0;
	return 1;
}
