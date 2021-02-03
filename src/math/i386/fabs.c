#include <math.h>

MUSL_EXPORT double fabs(double x)
{
	__asm__ ("fabs" : "+t"(x));
	return x;
}
