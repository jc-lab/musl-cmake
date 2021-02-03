#include <math.h>

MUSL_EXPORT double ldexp(double x, int n)
{
	return scalbn(x, n);
}
