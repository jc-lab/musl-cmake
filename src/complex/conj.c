#include "complex_impl.h"

MUSL_EXPORT double complex conj(double complex z)
{
	return CMPLX(creal(z), -cimag(z));
}
