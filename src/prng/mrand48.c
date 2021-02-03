#include <stdlib.h>
#include <inttypes.h>
#include "rand48.h"

MUSL_EXPORT long jrand48(unsigned short s[3])
{
	return (int32_t)(__rand48_step(s, __seed48+3) >> 16);
}

MUSL_EXPORT long mrand48(void)
{
	return jrand48(__seed48);
}
