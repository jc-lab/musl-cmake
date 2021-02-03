#include <stdlib.h>

MUSL_EXPORT void *realloc(void *p, size_t n)
{
	return __libc_realloc(p, n);
}
