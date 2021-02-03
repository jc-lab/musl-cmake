#include <strings.h>
#include "atomic.h"

MUSL_EXPORT int ffsll(long long i)
{
	return i ? a_ctz_64(i)+1 : 0;
}
