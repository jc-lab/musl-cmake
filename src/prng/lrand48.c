#include <stdlib.h>
#include <inttypes.h>
#include "rand48.h"

MUSL_EXPORT long nrand48(unsigned short s[3])
{
	return __rand48_step(s, __seed48+3) >> 17;
}

MUSL_EXPORT long lrand48(void)
{
	return nrand48(__seed48);
}
