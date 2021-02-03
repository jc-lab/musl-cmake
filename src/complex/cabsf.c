#include "complex_impl.h"

MUSL_EXPORT float cabsf(float complex z)
{
	return hypotf(crealf(z), cimagf(z));
}
