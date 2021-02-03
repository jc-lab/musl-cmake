#include "pthread_impl.h"

MUSL_EXPORT int pthread_condattr_init(pthread_condattr_t *a)
{
	*a = (pthread_condattr_t){0};
	return 0;
}
