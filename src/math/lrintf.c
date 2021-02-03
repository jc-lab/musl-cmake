#include <math.h>

/* uses LONG_MAX > 2^24, see comments in lrint.c */

MUSL_EXPORT long lrintf(float x)
{
	return rintf(x);
}
