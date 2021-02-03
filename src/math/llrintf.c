#include <math.h>

/* uses LLONG_MAX > 2^24, see comments in lrint.c */

MUSL_EXPORT long long llrintf(float x)
{
	return rintf(x);
}
