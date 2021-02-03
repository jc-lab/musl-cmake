#include <math.h>

MUSL_EXPORT long lroundf(float x)
{
	long n;
	__asm__ ("fcvtas %x0, %s1" : "=r"(n) : "w"(x));
	return n;
}
