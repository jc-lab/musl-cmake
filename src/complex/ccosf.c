#include "complex_impl.h"

MUSL_EXPORT float complex ccosf(float complex z)
{
	return ccoshf(CMPLXF(-cimagf(z), crealf(z)));
}
