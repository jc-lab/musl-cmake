#include "complex_impl.h"

MUSL_EXPORT float complex conjf(float complex z)
{
	return CMPLXF(crealf(z), -cimagf(z));
}
