#include <math.h>

MUSL_EXPORT float fabsf(float x)
{
	__asm__ ("fabs" : "+t"(x));
	return x;
}
