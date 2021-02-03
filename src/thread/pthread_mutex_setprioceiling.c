#include "pthread_impl.h"

MUSL_EXPORT int pthread_mutex_setprioceiling(pthread_mutex_t *restrict m, int ceiling, int *restrict old)
{
	return EINVAL;
}
