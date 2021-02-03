#include <termios.h>
#include <sys/ioctl.h>

MUSL_EXPORT int tcflush(int fd, int queue)
{
	return ioctl(fd, TCFLSH, queue);
}
