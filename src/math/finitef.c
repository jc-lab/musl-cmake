#define _GNU_SOURCE
#include <math.h>

MUSL_EXPORT int finitef(float x)
{
	return isfinite(x);
}
