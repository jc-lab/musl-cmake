#include <math.h>

#if __riscv_flen >= 32

MUSL_EXPORT float fmaxf(float x, float y)
{
	__asm__ ("fmax.s %0, %1, %2" : "=f"(x) : "f"(x), "f"(y));
	return x;
}

#else

#include "../fmaxf.c"

#endif
