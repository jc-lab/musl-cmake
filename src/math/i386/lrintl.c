#include <math.h>

MUSL_EXPORT long lrintl(long double x)
{
	long r;
	__asm__ ("fistpl %0" : "=m"(r) : "t"(x) : "st");
	return r;
}
