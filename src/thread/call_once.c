#include <threads.h>
#include <pthread.h>

MUSL_EXPORT void call_once(once_flag *flag, void (*func)(void))
{
	__pthread_once(flag, func);
}
