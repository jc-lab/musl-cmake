#include <mqueue.h>
#include "syscall.h"

MUSL_EXPORT int mq_setattr(mqd_t mqd, const struct mq_attr *restrict new, struct mq_attr *restrict old)
{
	return syscall(SYS_mq_getsetattr, mqd, new, old);
}
