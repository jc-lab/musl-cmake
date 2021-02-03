#include "complex_impl.h"

/* tan(z) = -i tanh(i z) */

MUSL_EXPORT double complex ctan(double complex z)
{
	z = ctanh(CMPLX(-cimag(z), creal(z)));
	return CMPLX(cimag(z), -creal(z));
}
