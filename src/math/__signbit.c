#include "libm.h"

// FIXME: macro in math.h
MUSL_EXPORT int __signbit(double x)
{
	union {
		double d;
		uint64_t i;
	} y = { x };
	return y.i>>63;
}


