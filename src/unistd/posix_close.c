#include <unistd.h>

MUSL_EXPORT int posix_close(int fd, int flags)
{
	return close(fd);
}
