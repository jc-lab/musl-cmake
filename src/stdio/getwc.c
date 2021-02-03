#include "stdio_impl.h"
#include <wchar.h>

MUSL_EXPORT wint_t getwc(FILE *f)
{
	return fgetwc(f);
}
