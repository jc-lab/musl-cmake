#define _GNU_SOURCE
#include <math.h>

MUSL_EXPORT int finite(double x)
{
	return isfinite(x);
}
