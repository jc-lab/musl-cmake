#include <inttypes.h>

MUSL_EXPORT intmax_t imaxabs(intmax_t a)
{
	return a>0 ? a : -a;
}
