#ifndef _THREADS_H
#define _THREADS_H

#include <features.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
typedef unsigned long thrd_t;
#else
typedef struct __pthread *thrd_t;
#define thread_local _Thread_local
#endif

typedef int once_flag;
typedef unsigned tss_t;
MUSL_EXPORT typedef int (*thrd_start_t)(void *);
MUSL_EXPORT typedef void (*tss_dtor_t)(void *);

#define __NEED_cnd_t
#define __NEED_mtx_t

#include <bits/alltypes.h>

#define TSS_DTOR_ITERATIONS 4

enum {
	thrd_success  = 0,
	thrd_busy     = 1,
	thrd_error    = 2,
	thrd_nomem    = 3,
	thrd_timedout = 4,
};

enum {
	mtx_plain     = 0,
	mtx_recursive = 1,
	mtx_timed     = 2,
};

#define ONCE_FLAG_INIT 0

MUSL_EXPORT int thrd_create(thrd_t *, thrd_start_t, void *);
_Noreturn void thrd_exit(int);

MUSL_EXPORT int thrd_detach(thrd_t);
MUSL_EXPORT int thrd_join(thrd_t, int *);

MUSL_EXPORT int thrd_sleep(const struct timespec *, struct timespec *);
MUSL_EXPORT void thrd_yield(void);

MUSL_EXPORT thrd_t thrd_current(void);
MUSL_EXPORT int thrd_equal(thrd_t, thrd_t);
#ifndef __cplusplus
#define thrd_equal(A, B) ((A) == (B))
#endif

MUSL_EXPORT void call_once(once_flag *, void (*)(void));

MUSL_EXPORT int mtx_init(mtx_t *, int);
MUSL_EXPORT void mtx_destroy(mtx_t *);

MUSL_EXPORT int mtx_lock(mtx_t *);
MUSL_EXPORT int mtx_timedlock(mtx_t *__restrict, const struct timespec *__restrict);
MUSL_EXPORT int mtx_trylock(mtx_t *);
MUSL_EXPORT int mtx_unlock(mtx_t *);

MUSL_EXPORT int cnd_init(cnd_t *);
MUSL_EXPORT void cnd_destroy(cnd_t *);

MUSL_EXPORT int cnd_broadcast(cnd_t *);
MUSL_EXPORT int cnd_signal(cnd_t *);

MUSL_EXPORT int cnd_timedwait(cnd_t *__restrict, mtx_t *__restrict, const struct timespec *__restrict);
MUSL_EXPORT int cnd_wait(cnd_t *, mtx_t *);

MUSL_EXPORT int tss_create(tss_t *, tss_dtor_t);
MUSL_EXPORT void tss_delete(tss_t);

MUSL_EXPORT int tss_set(tss_t, void *);
MUSL_EXPORT void *tss_get(tss_t);

#if _REDIR_TIME64
__REDIR(thrd_sleep, __thrd_sleep_time64);
__REDIR(mtx_timedlock, __mtx_timedlock_time64);
__REDIR(cnd_timedwait, __cnd_timedwait_time64);
#endif

#ifdef __cplusplus
}
#endif

#endif
