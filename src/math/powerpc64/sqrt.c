#include <math.h>

MUSL_EXPORT double sqrt(double x)
{
	__asm__ ("fsqrt %0, %1" : "=d"(x) : "d"(x));
	return x;
}
