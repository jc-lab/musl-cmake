#include "pthread_impl.h"

MUSL_EXPORT int pthread_mutex_getprioceiling(const pthread_mutex_t *restrict m, int *restrict ceiling)
{
	return EINVAL;
}
