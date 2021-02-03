#include "complex_impl.h"

MUSL_EXPORT float cargf(float complex z)
{
	return atan2f(cimagf(z), crealf(z));
}
