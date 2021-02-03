#include "complex_impl.h"

MUSL_EXPORT double carg(double complex z)
{
	return atan2(cimag(z), creal(z));
}
