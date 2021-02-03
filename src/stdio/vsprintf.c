#include <stdio.h>
#include <limits.h>

MUSL_EXPORT int vsprintf(char *restrict s, const char *restrict fmt, va_list ap)
{
	return vsnprintf(s, INT_MAX, fmt, ap);
}
