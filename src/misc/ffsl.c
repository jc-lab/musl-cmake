#include <strings.h>
#include "atomic.h"

MUSL_EXPORT int ffsl(long i)
{
	return i ? a_ctz_l(i)+1 : 0;
}
