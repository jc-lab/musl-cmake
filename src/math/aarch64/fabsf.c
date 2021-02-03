#include <math.h>

MUSL_EXPORT float fabsf(float x)
{
	__asm__ ("fabs %s0, %s1" : "=w"(x) : "w"(x));
	return x;
}
