#include "stdio_impl.h"
#include <wchar.h>

MUSL_EXPORT wint_t getwchar(void)
{
	return fgetwc(stdin);
}

weak_alias(getwchar, getwchar_unlocked);
