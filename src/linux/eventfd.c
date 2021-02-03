#include <sys/eventfd.h>
#include <unistd.h>
#include <errno.h>
#include "syscall.h"

MUSL_EXPORT int eventfd(unsigned int count, int flags)
{
	int r = __syscall(SYS_eventfd2, count, flags);
#ifdef SYS_eventfd
	if (r==-ENOSYS && !flags) r = __syscall(SYS_eventfd, count);
#endif
	return __syscall_ret(r);
}

MUSL_EXPORT int eventfd_read(int fd, eventfd_t *value)
{
	return (sizeof(*value) == read(fd, value, sizeof(*value))) ? 0 : -1;
}

MUSL_EXPORT int eventfd_write(int fd, eventfd_t value)
{
	return (sizeof(value) == write(fd, &value, sizeof(value))) ? 0 : -1;
}
