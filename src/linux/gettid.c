#define _GNU_SOURCE
#include <unistd.h>
#include "pthread_impl.h"

MUSL_EXPORT pid_t gettid(void)
{
	return __pthread_self()->tid;
}
