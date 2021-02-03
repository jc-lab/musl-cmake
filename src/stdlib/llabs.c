#include <stdlib.h>

MUSL_EXPORT long long llabs(long long a)
{
	return a>0 ? a : -a;
}
