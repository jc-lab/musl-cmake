#include <semaphore.h>

MUSL_EXPORT int sem_wait(sem_t *sem)
{
	return sem_timedwait(sem, 0);
}
