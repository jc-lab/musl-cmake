#include <math.h>

#if __riscv_flen >= 32

MUSL_EXPORT float sqrtf(float x)
{
	__asm__ ("fsqrt.s %0, %1" : "=f"(x) : "f"(x));
	return x;
}

#else

#include "../sqrtf.c"

#endif
