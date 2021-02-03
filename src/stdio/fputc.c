#include <stdio.h>
#include "putc.h"

MUSL_EXPORT int fputc(int c, FILE *f)
{
	return do_putc(c, f);
}
