#include <spawn.h>

MUSL_EXPORT int posix_spawnattr_setsigmask(posix_spawnattr_t *restrict attr, const sigset_t *restrict mask)
{
	attr->__mask = *mask;
	return 0;
}
