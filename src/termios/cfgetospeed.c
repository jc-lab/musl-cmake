#define _BSD_SOURCE
#include <termios.h>
#include <sys/ioctl.h>

MUSL_EXPORT speed_t cfgetospeed(const struct termios *tio)
{
	return tio->c_cflag & CBAUD;
}

MUSL_EXPORT speed_t cfgetispeed(const struct termios *tio)
{
	return cfgetospeed(tio);
}
