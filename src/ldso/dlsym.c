#include <dlfcn.h>
#include "dynlink.h"

MUSL_EXPORT void *dlsym(void *restrict p, const char *restrict s)
{
	return __dlsym(p, s, 0);
}
