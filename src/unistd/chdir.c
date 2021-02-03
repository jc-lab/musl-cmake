#include <unistd.h>
#include "syscall.h"

MUSL_EXPORT int chdir(const char *path)
{
	return syscall(SYS_chdir, path);
}
