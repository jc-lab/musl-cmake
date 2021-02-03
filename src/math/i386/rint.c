#include <math.h>

MUSL_EXPORT double rint(double x)
{
	__asm__ ("frndint" : "+t"(x));
	return x;
}
