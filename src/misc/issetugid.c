#define _BSD_SOURCE
#include <unistd.h>
#include "libc.h"

MUSL_EXPORT int issetugid(void)
{
	return libc.secure;
}
