#include <unistd.h>
#include <errno.h>
#include <limits.h>

MUSL_EXPORT char *ttyname(int fd)
{
	static char buf[TTY_NAME_MAX];
	int result;
	if ((result = ttyname_r(fd, buf, sizeof buf))) {
		errno = result;
		return NULL;
	}
	return buf;
}
