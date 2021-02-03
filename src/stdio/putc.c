#include <stdio.h>
#include "putc.h"

MUSL_EXPORT int putc(int c, FILE *f)
{
	return do_putc(c, f);
}

weak_alias(putc, _IO_putc);
