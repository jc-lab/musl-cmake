#include <math.h>

#if __riscv_flen >= 64

MUSL_EXPORT double fmin(double x, double y)
{
	__asm__ ("fmin.d %0, %1, %2" : "=f"(x) : "f"(x), "f"(y));
	return x;
}

#else

#include "../fmin.c"

#endif
