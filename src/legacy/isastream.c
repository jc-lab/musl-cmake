#include <stropts.h>
#include <fcntl.h>

MUSL_EXPORT int isastream(int fd)
{
	return fcntl(fd, F_GETFD) < 0 ? -1 : 0;
}
