#include "complex_impl.h"

MUSL_EXPORT long double complex conjl(long double complex z)
{
	return CMPLXL(creall(z), -cimagl(z));
}
