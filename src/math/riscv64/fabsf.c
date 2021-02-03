#include <math.h>

#if __riscv_flen >= 32

MUSL_EXPORT float fabsf(float x)
{
	__asm__ ("fabs.s %0, %1" : "=f"(x) : "f"(x));
	return x;
}

#else

#include "../fabsf.c"

#endif
