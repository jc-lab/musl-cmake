#include <stdlib.h>

MUSL_EXPORT void free(void *p)
{
	return __libc_free(p);
}
