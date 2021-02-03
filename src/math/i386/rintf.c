#include <math.h>

MUSL_EXPORT float rintf(float x)
{
	__asm__ ("frndint" : "+t"(x));
	return x;
}
