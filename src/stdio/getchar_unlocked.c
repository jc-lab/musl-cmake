#include "stdio_impl.h"

MUSL_EXPORT int getchar_unlocked(void)
{
	return getc_unlocked(stdin);
}
