#include <sys/resource.h>
#include "syscall.h"

MUSL_EXPORT int getpriority(int which, id_t who)
{
	int ret = syscall(SYS_getpriority, which, who);
	if (ret < 0) return ret;
	return 20-ret;
}
