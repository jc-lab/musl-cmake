#include "complex_impl.h"

MUSL_EXPORT float complex catanhf(float complex z)
{
	z = catanf(CMPLXF(-cimagf(z), crealf(z)));
	return CMPLXF(cimagf(z), -crealf(z));
}
