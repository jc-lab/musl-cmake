#define _BSD_SOURCE
#include <stdlib.h>
#include "libc.h"

MUSL_EXPORT void *valloc(size_t size)
{
	return memalign(PAGE_SIZE, size);
}
