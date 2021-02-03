#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>

MUSL_EXPORT int tcsetpgrp(int fd, pid_t pgrp)
{
	int pgrp_int = pgrp;
	return ioctl(fd, TIOCSPGRP, &pgrp_int);
}
