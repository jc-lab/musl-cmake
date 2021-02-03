#include <dirent.h>
#include "__dirent.h"

MUSL_EXPORT int dirfd(DIR *d)
{
	return d->fd;
}
