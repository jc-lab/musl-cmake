#include "complex_impl.h"

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
MUSL_EXPORT long double complex clogl(long double complex z)
{
	return clog(z);
}
#else
// FIXME
MUSL_EXPORT long double complex clogl(long double complex z)
{
	long double r, phi;

	r = cabsl(z);
	phi = cargl(z);
	return CMPLXL(logl(r), phi);
}
#endif
