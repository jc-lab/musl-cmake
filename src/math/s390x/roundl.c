#include <math.h>

#if defined(__HTM__) || __ARCH__ >= 9

MUSL_EXPORT long double roundl(long double x)
{
	__asm__ ("fixbra %0, 1, %1, 4" : "=f"(x) : "f"(x));
	return x;
}

#else

#include "../roundl.c"

#endif
