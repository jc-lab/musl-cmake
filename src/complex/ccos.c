#include "complex_impl.h"

/* cos(z) = cosh(i z) */

MUSL_EXPORT double complex ccos(double complex z)
{
	return ccosh(CMPLX(-cimag(z), creal(z)));
}
