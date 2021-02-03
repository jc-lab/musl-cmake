#include <math.h>

MUSL_EXPORT long double fabsl(long double x)
{
	__asm__ ("fabs" : "+t"(x));
	return x;
}
