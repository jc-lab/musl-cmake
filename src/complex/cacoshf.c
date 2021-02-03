#include "complex_impl.h"

MUSL_EXPORT float complex cacoshf(float complex z)
{
	int zineg = signbit(cimagf(z));

	z = cacosf(z);
	if (zineg) return CMPLXF(cimagf(z), -crealf(z));
	else       return CMPLXF(-cimagf(z), crealf(z));
}
