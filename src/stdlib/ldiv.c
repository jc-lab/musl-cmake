#include <stdlib.h>

MUSL_EXPORT ldiv_t ldiv(long num, long den)
{
	return (ldiv_t){ num/den, num%den };
}
