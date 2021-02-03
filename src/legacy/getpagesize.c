#define _GNU_SOURCE
#include <unistd.h>
#include "libc.h"

MUSL_EXPORT int getpagesize(void)
{
	return PAGE_SIZE;
}
