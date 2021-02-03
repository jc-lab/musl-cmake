#include <termios.h>
#include <sys/ioctl.h>

MUSL_EXPORT int tcflow(int fd, int action)
{
	return ioctl(fd, TCXONC, action);
}
