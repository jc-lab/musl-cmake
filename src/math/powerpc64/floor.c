#include <math.h>

#ifdef _ARCH_PWR5X

MUSL_EXPORT double floor(double x)
{
	__asm__ ("frim %0, %1" : "=d"(x) : "d"(x));
	return x;
}

#else

#include "../floor.c"

#endif
