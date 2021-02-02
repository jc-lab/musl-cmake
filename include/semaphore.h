#ifndef _SEMAPHORE_H
#define _SEMAPHORE_H
#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#define __NEED_time_t
#define __NEED_struct_timespec
#include <bits/alltypes.h>

#include <fcntl.h>

#define SEM_FAILED ((sem_t *)0)

typedef struct {
	volatile int __val[4*sizeof(long)/sizeof(int)];
} sem_t;

MUSL_EXPORT int    sem_close(sem_t *);
MUSL_EXPORT int    sem_destroy(sem_t *);
MUSL_EXPORT int    sem_getvalue(sem_t *__restrict, int *__restrict);
MUSL_EXPORT int    sem_init(sem_t *, int, unsigned);
MUSL_EXPORT sem_t *sem_open(const char *, int, ...);
MUSL_EXPORT int    sem_post(sem_t *);
MUSL_EXPORT int    sem_timedwait(sem_t *__restrict, const struct timespec *__restrict);
MUSL_EXPORT int    sem_trywait(sem_t *);
MUSL_EXPORT int    sem_unlink(const char *);
MUSL_EXPORT int    sem_wait(sem_t *);

#if _REDIR_TIME64
__REDIR(sem_timedwait, __sem_timedwait_time64);
#endif

#ifdef __cplusplus
}
#endif
#endif
