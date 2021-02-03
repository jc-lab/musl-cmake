#include "complex_impl.h"

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
MUSL_EXPORT long double complex cpowl(long double complex z, long double complex c)
{
	return cpow(z, c);
}
#else
MUSL_EXPORT long double complex cpowl(long double complex z, long double complex c)
{
	return cexpl(c * clogl(z));
}
#endif
