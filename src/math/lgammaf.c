#include <math.h>
#include "libm.h"

MUSL_EXPORT float lgammaf(float x)
{
	return __lgammaf_r(x, &__signgam);
}
