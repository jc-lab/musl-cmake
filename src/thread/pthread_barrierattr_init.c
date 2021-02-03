#include "pthread_impl.h"

MUSL_EXPORT int pthread_barrierattr_init(pthread_barrierattr_t *a)
{
	*a = (pthread_barrierattr_t){0};
	return 0;
}
