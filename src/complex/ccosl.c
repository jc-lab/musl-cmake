#include "complex_impl.h"

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
MUSL_EXPORT long double complex ccosl(long double complex z)
{
	return ccos(z);
}
#else
MUSL_EXPORT long double complex ccosl(long double complex z)
{
	return ccoshl(CMPLXL(-cimagl(z), creall(z)));
}
#endif
