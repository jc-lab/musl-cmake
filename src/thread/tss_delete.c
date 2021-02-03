#include <threads.h>
#include <pthread.h>

MUSL_EXPORT void tss_delete(tss_t key)
{
	__pthread_key_delete(key);
}
