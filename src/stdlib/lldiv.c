#include <stdlib.h>

MUSL_EXPORT lldiv_t lldiv(long long num, long long den)
{
	return (lldiv_t){ num/den, num%den };
}
