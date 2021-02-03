#include <stdlib.h>

MUSL_EXPORT long labs(long a)
{
	return a>0 ? a : -a;
}
