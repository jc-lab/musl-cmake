#include <math.h>

/*
MUSL_EXPORT special cases:
	logb(+-0) = -inf, and raise divbyzero
	logb(+-inf) = +inf
	logb(nan) = nan
*/

MUSL_EXPORT double logb(double x)
{
	if (!isfinite(x))
		return x * x;
	if (x == 0)
		return -1/(x*x);
	return ilogb(x);
}
