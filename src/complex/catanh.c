#include "complex_impl.h"

/* atanh = -i atan(i z) */

MUSL_EXPORT double complex catanh(double complex z)
{
	z = catan(CMPLX(-cimag(z), creal(z)));
	return CMPLX(cimag(z), -creal(z));
}
