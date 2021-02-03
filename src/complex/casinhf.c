#include "complex_impl.h"

MUSL_EXPORT float complex casinhf(float complex z)
{
	z = casinf(CMPLXF(-cimagf(z), crealf(z)));
	return CMPLXF(cimagf(z), -crealf(z));
}
