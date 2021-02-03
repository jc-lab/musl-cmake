#include <spawn.h>

MUSL_EXPORT int posix_spawnattr_setsigdefault(posix_spawnattr_t *restrict attr, const sigset_t *restrict def)
{
	attr->__def = *def;
	return 0;
}
