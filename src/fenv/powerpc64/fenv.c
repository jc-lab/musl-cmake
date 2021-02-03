#define _GNU_SOURCE
#include <fenv.h>
#include <features.h>

static inline double get_fpscr_f(void)
{
	double d;
	__asm__ __volatile__("mffs %0" : "=d"(d));
	return d;
}

static inline long get_fpscr(void)
{
	return (union {double f; long i;}) {get_fpscr_f()}.i;
}

static inline void set_fpscr_f(double fpscr)
{
	__asm__ __volatile__("mtfsf 255, %0" : : "d"(fpscr));
}

static void set_fpscr(long fpscr)
{
	set_fpscr_f((union {long i; double f;}) {fpscr}.f);
}

MUSL_EXPORT int feclearexcept(int mask)
{
	mask &= FE_ALL_EXCEPT;
	if (mask & FE_INVALID) mask |= FE_ALL_INVALID;
	set_fpscr(get_fpscr() & ~mask);
	return 0;
}

MUSL_EXPORT int feraiseexcept(int mask)
{
	mask &= FE_ALL_EXCEPT;
	if (mask & FE_INVALID) mask |= FE_INVALID_SOFTWARE;
	set_fpscr(get_fpscr() | mask);
	return 0;
}

MUSL_EXPORT int fetestexcept(int mask)
{
	return get_fpscr() & mask & FE_ALL_EXCEPT;
}

MUSL_EXPORT int fegetround(void)
{
	return get_fpscr() & 3;
}

hidden int __fesetround(int r)
{
	set_fpscr(get_fpscr() & ~3L | r);
	return 0;
}

MUSL_EXPORT int fegetenv(fenv_t *envp)
{
	*envp = get_fpscr_f();
	return 0;
}

MUSL_EXPORT int fesetenv(const fenv_t *envp)
{
	set_fpscr_f(envp != FE_DFL_ENV ? *envp : 0);
	return 0;
}
