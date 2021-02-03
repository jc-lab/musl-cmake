#include <semaphore.h>
#include <sys/mman.h>

MUSL_EXPORT int sem_unlink(const char *name)
{
	return shm_unlink(name);
}
