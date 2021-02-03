#include "complex_impl.h"

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
MUSL_EXPORT long double complex csinl(long double complex z)
{
	return csin(z);
}
#else
MUSL_EXPORT long double complex csinl(long double complex z)
{
	z = csinhl(CMPLXL(-cimagl(z), creall(z)));
	return CMPLXL(cimagl(z), -creall(z));
}
#endif
