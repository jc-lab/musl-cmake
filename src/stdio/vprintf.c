#include <stdio.h>

MUSL_EXPORT int vprintf(const char *restrict fmt, va_list ap)
{
	return vfprintf(stdout, fmt, ap);
}
