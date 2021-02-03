#include "complex_impl.h"

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
MUSL_EXPORT long double cargl(long double complex z)
{
	return carg(z);
}
#else
MUSL_EXPORT long double cargl(long double complex z)
{
	return atan2l(cimagl(z), creall(z));
}
#endif
