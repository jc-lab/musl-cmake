#include <math.h>

MUSL_EXPORT float nearbyintf(float x)
{
	__asm__ ("frinti %s0, %s1" : "=w"(x) : "w"(x));
	return x;
}
