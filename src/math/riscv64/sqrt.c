#include <math.h>

#if __riscv_flen >= 64

MUSL_EXPORT double sqrt(double x)
{
	__asm__ ("fsqrt.d %0, %1" : "=f"(x) : "f"(x));
	return x;
}

#else

#include "../sqrt.c"

#endif
