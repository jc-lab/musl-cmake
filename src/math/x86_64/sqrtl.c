#include <math.h>

MUSL_EXPORT long double sqrtl(long double x)
{
	__asm__ ("fsqrt" : "+t"(x));
	return x;
}
