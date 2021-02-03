#include <math.h>

MUSL_EXPORT double sqrt(double x)
{
	__asm__ ("fsqrt %d0, %d1" : "=w"(x) : "w"(x));
	return x;
}
