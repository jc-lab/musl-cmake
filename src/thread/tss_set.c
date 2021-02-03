#include "pthread_impl.h"
#include <threads.h>

MUSL_EXPORT int tss_set(tss_t k, void *x)
{
	struct pthread *self = __pthread_self();
	/* Avoid unnecessary COW */
	if (self->tsd[k] != x) {
		self->tsd[k] = x;
		self->tsd_used = 1;
	}
	return thrd_success;
}
