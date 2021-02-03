#include <math.h>

MUSL_EXPORT float floorf(float x)
{
	__asm__ ("frintm %s0, %s1" : "=w"(x) : "w"(x));
	return x;
}
