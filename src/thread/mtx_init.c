#include "pthread_impl.h"
#include <threads.h>

MUSL_EXPORT int mtx_init(mtx_t *m, int type)
{
	*m = (mtx_t){
		._m_type = ((type&mtx_recursive) ? PTHREAD_MUTEX_RECURSIVE : PTHREAD_MUTEX_NORMAL),
	};
	return thrd_success;
}
