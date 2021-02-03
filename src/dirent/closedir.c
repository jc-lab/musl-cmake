#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include "__dirent.h"

MUSL_EXPORT int closedir(DIR *dir)
{
	int ret = close(dir->fd);
	free(dir);
	return ret;
}
