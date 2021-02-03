#include <termios.h>
#include <sys/ioctl.h>

MUSL_EXPORT pid_t tcgetsid(int fd)
{
	int sid;
	if (ioctl(fd, TIOCGSID, &sid) < 0)
		return -1;
	return sid;
}
