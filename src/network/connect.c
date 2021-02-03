#include <sys/socket.h>
#include "syscall.h"

MUSL_EXPORT int connect(int fd, const struct sockaddr *addr, socklen_t len)
{
	return socketcall_cp(connect, fd, addr, len, 0, 0, 0);
}
