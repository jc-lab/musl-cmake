#include "complex_impl.h"

//FIXME
MUSL_EXPORT long double complex cexpl(long double complex z)
{
	return cexp(z);
}
