#include <stdlib.h>

MUSL_EXPORT int abs(int a)
{
	return a>0 ? a : -a;
}
