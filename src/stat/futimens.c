#include <sys/stat.h>

MUSL_EXPORT int futimens(int fd, const struct timespec times[2])
{
	return utimensat(fd, 0, times, 0);
}
