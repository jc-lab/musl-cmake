#include <threads.h>

MUSL_EXPORT void cnd_destroy(cnd_t *c)
{
	/* For private cv this is a no-op */
}
