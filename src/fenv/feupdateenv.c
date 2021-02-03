#include <fenv.h>

MUSL_EXPORT int feupdateenv(const fenv_t *envp)
{
	int ex = fetestexcept(FE_ALL_EXCEPT);
	fesetenv(envp);
	feraiseexcept(ex);
	return 0;
}
