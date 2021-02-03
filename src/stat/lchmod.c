#define _GNU_SOURCE
#include <sys/stat.h>
#include <fcntl.h>

MUSL_EXPORT int lchmod(const char *path, mode_t mode)
{
	return fchmodat(AT_FDCWD, path, mode, AT_SYMLINK_NOFOLLOW);
}
