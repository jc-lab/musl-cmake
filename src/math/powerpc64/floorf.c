#include <math.h>

#ifdef _ARCH_PWR5X

MUSL_EXPORT float floorf(float x)
{
	__asm__ ("frim %0, %1" : "=f"(x) : "f"(x));
	return x;
}

#else

#include "../floorf.c"

#endif
