#define _GNU_SOURCE
#include <time.h>
#include <sys/time.h>

MUSL_EXPORT int stime(const time_t *t)
{
	struct timeval tv = { .tv_sec = *t, .tv_usec = 0 };
	return settimeofday(&tv, (void *)0);
}
