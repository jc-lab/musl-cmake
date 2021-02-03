#include "complex_impl.h"

// FIXME

/* log(z) = log(|z|) + i arg(z) */

MUSL_EXPORT double complex clog(double complex z)
{
	double r, phi;

	r = cabs(z);
	phi = carg(z);
	return CMPLX(log(r), phi);
}
