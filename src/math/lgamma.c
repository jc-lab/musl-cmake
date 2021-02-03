#include <math.h>
#include "libm.h"

MUSL_EXPORT double lgamma(double x)
{
	return __lgamma_r(x, &__signgam);
}
