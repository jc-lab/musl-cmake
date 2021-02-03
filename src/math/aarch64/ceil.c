#include <math.h>

MUSL_EXPORT double ceil(double x)
{
	__asm__ ("frintp %d0, %d1" : "=w"(x) : "w"(x));
	return x;
}
