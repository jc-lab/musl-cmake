#include <unistd.h>

extern char **__environ;

MUSL_EXPORT int execv(const char *path, char *const argv[])
{
	return execve(path, argv, __environ);
}
