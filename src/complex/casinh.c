#include "complex_impl.h"

/* asinh(z) = -i asin(i z) */

MUSL_EXPORT double complex casinh(double complex z)
{
	z = casin(CMPLX(-cimag(z), creal(z)));
	return CMPLX(cimag(z), -creal(z));
}
