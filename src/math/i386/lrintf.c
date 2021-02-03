#include <math.h>

MUSL_EXPORT long lrintf(float x)
{
	long r;
	__asm__ ("fistpl %0" : "=m"(r) : "t"(x) : "st");
	return r;
}
