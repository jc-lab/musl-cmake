#include <sys/stat.h>
#include "syscall.h"

MUSL_EXPORT mode_t umask(mode_t mode)
{
	return syscall(SYS_umask, mode);
}
