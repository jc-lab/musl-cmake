#define _GNU_SOURCE
#include <math.h>

MUSL_EXPORT double significand(double x)
{
	return scalbn(x, -ilogb(x));
}
