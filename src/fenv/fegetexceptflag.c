#include <fenv.h>

MUSL_EXPORT int fegetexceptflag(fexcept_t *fp, int mask)
{
	*fp = fetestexcept(mask);
	return 0;
}
