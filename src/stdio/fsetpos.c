#include "stdio_impl.h"

MUSL_EXPORT int fsetpos(FILE *f, const fpos_t *pos)
{
	return __fseeko(f, *(const long long *)pos, SEEK_SET);
}

weak_alias(fsetpos, fsetpos64);
