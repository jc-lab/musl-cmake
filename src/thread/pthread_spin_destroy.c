#include "pthread_impl.h"

MUSL_EXPORT int pthread_spin_destroy(pthread_spinlock_t *s)
{
	return 0;
}
