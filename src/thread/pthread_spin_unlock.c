#include "pthread_impl.h"

MUSL_EXPORT int pthread_spin_unlock(pthread_spinlock_t *s)
{
	a_store(s, 0);
	return 0;
}
