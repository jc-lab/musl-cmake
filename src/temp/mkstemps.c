#define _BSD_SOURCE
#include <stdlib.h>

MUSL_EXPORT int mkstemps(char *template, int len)
{
	return __mkostemps(template, len, 0);
}

weak_alias(mkstemps, mkstemps64);
