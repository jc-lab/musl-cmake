#include <unistd.h>
#include "syscall.h"

MUSL_EXPORT int symlinkat(const char *existing, int fd, const char *new)
{
	return syscall(SYS_symlinkat, existing, fd, new);
}
