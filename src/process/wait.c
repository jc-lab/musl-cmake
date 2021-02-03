#include <sys/wait.h>

MUSL_EXPORT pid_t wait(int *status)
{
	return waitpid((pid_t)-1, status, 0);
}
