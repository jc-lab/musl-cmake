#include <stdio.h>
#include "getc.h"

MUSL_EXPORT int getchar(void)
{
	return do_getc(stdin);
}
