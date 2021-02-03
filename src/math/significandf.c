#define _GNU_SOURCE
#include <math.h>

MUSL_EXPORT float significandf(float x)
{
	return scalbnf(x, -ilogbf(x));
}
