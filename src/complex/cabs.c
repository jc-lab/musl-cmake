#include "complex_impl.h"

MUSL_EXPORT double cabs(double complex z)
{
	return hypot(creal(z), cimag(z));
}
