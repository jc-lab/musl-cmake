#include <stdio.h>
#include "getc.h"

MUSL_EXPORT int fgetc(FILE *f)
{
	return do_getc(f);
}
