#include "pthread_impl.h"

MUSL_EXPORT int pthread_mutexattr_init(pthread_mutexattr_t *a)
{
	*a = (pthread_mutexattr_t){0};
	return 0;
}
