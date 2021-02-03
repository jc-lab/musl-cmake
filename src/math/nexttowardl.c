#include <math.h>

MUSL_EXPORT long double nexttowardl(long double x, long double y)
{
	return nextafterl(x, y);
}
