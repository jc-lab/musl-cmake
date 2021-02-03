#include <sys/socket.h>
#include "syscall.h"

MUSL_EXPORT int accept(int fd, struct sockaddr *restrict addr, socklen_t *restrict len)
{
	return socketcall_cp(accept, fd, addr, len, 0, 0, 0);
}
