#include <math.h>

MUSL_EXPORT float ldexpf(float x, int n)
{
	return scalbnf(x, n);
}
