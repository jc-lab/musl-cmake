#include <sys/socket.h>
#include "syscall.h"

MUSL_EXPORT int listen(int fd, int backlog)
{
	return socketcall(listen, fd, backlog, 0, 0, 0, 0);
}
