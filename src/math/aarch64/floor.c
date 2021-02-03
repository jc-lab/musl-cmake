#include <math.h>

MUSL_EXPORT double floor(double x)
{
	__asm__ ("frintm %d0, %d1" : "=w"(x) : "w"(x));
	return x;
}
