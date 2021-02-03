#define _BSD_SOURCE
#include <stdlib.h>

MUSL_EXPORT int mkostemp(char *template, int flags)
{
	return __mkostemps(template, 0, flags);
}

weak_alias(mkostemp, mkostemp64);
