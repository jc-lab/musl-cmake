#include <math.h>

MUSL_EXPORT double remainder(double x, double y)
{
	int q;
	return remquo(x, y, &q);
}

weak_alias(remainder, drem);
