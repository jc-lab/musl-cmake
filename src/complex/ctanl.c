#include "complex_impl.h"

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
MUSL_EXPORT long double complex ctanl(long double complex z)
{
	return ctan(z);
}
#else
MUSL_EXPORT long double complex ctanl(long double complex z)
{
	z = ctanhl(CMPLXL(-cimagl(z), creall(z)));
	return CMPLXL(cimagl(z), -creall(z));
}
#endif
