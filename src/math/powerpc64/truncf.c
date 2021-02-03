#include <math.h>

#ifdef _ARCH_PWR5X

MUSL_EXPORT float truncf(float x)
{
	__asm__ ("friz %0, %1" : "=f"(x) : "f"(x));
	return x;
}

#else

#include "../truncf.c"

#endif
