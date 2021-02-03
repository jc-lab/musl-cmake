#include <math.h>

MUSL_EXPORT float fabsf(float x)
{
	__asm__ ("fabs %0, %1" : "=f"(x) : "f"(x));
	return x;
}
