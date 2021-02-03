#define _GNU_SOURCE
#include <utmpx.h>
#include <stddef.h>
#include <errno.h>

MUSL_EXPORT void endutxent(void)
{
}

MUSL_EXPORT void setutxent(void)
{
}

MUSL_EXPORT struct utmpx *getutxent(void)
{
	return NULL;
}

MUSL_EXPORT struct utmpx *getutxid(const struct utmpx *ut)
{
	return NULL;
}

MUSL_EXPORT struct utmpx *getutxline(const struct utmpx *ut)
{
	return NULL;
}

MUSL_EXPORT struct utmpx *pututxline(const struct utmpx *ut)
{
	return NULL;
}

MUSL_EXPORT void updwtmpx(const char *f, const struct utmpx *u)
{
}

static int __utmpxname(const char *f)
{
	errno = ENOTSUP;
	return -1;
}

weak_alias(endutxent, endutent);
weak_alias(setutxent, setutent);
weak_alias(getutxent, getutent);
weak_alias(getutxid, getutid);
weak_alias(getutxline, getutline);
weak_alias(pututxline, pututline);
weak_alias(updwtmpx, updwtmp);
weak_alias(__utmpxname, utmpname);
weak_alias(__utmpxname, utmpxname);
