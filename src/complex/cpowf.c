#include "complex_impl.h"

MUSL_EXPORT float complex cpowf(float complex z, float complex c)
{
	return cexpf(c * clogf(z));
}
