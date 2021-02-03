#include <math.h>

MUSL_EXPORT long double ldexpl(long double x, int n)
{
	return scalbnl(x, n);
}
