#include "pthread_impl.h"

MUSL_EXPORT int pthread_spin_init(pthread_spinlock_t *s, int shared)
{
	return *s = 0;
}
