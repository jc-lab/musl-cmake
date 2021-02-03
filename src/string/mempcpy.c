#define _GNU_SOURCE
#include <string.h>

MUSL_EXPORT void *mempcpy(void *dest, const void *src, size_t n)
{
	return (char *)memcpy(dest, src, n) + n;
}
