#include "complex_impl.h"

// FIXME

MUSL_EXPORT float complex cacosf(float complex z)
{
	z = casinf(z);
	return CMPLXF((float)M_PI_2 - crealf(z), -cimagf(z));
}
