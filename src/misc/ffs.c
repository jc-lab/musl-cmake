#include <strings.h>
#include "atomic.h"

MUSL_EXPORT int ffs(int i)
{
	return i ? a_ctz_l(i)+1 : 0;
}
