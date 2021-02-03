#include <math.h>

/* uses LLONG_MAX > 2^53, see comments in lrint.c */

MUSL_EXPORT long long llrint(double x)
{
	return rint(x);
}
