#include <math.h>

#ifdef _ARCH_PWR5X

MUSL_EXPORT long lrintf(float x)
{
	long n;
	__asm__ ("fctid %0, %1" : "=d"(n) : "f"(x));
	return n;
}

#else

#include "../lrintf.c"

#endif
