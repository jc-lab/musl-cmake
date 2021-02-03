#include <fenv.h>

/* Dummy functions for archs lacking fenv implementation */

MUSL_EXPORT int feclearexcept(int mask)
{
	return 0;
}

MUSL_EXPORT int feraiseexcept(int mask)
{
	return 0;
}

MUSL_EXPORT int fetestexcept(int mask)
{
	return 0;
}

MUSL_EXPORT int fegetround(void)
{
	return FE_TONEAREST;
}

int __fesetround(int r)
{
	return 0;
}

MUSL_EXPORT int fegetenv(fenv_t *envp)
{
	return 0;
}

MUSL_EXPORT int fesetenv(const fenv_t *envp)
{
	return 0;
}
