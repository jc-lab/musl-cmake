#define _GNU_SOURCE
#include <stdlib.h>
#include "libc.h"

MUSL_EXPORT char *secure_getenv(const char *name)
{
	return libc.secure ? NULL : getenv(name);
}
