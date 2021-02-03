#define _GNU_SOURCE
#include <sys/uio.h>
#include "syscall.h"

MUSL_EXPORT ssize_t process_vm_writev(pid_t pid, const struct iovec *lvec, unsigned long liovcnt, const struct iovec *rvec, unsigned long riovcnt, unsigned long flags)
{
	return syscall(SYS_process_vm_writev, pid, lvec, liovcnt, rvec, riovcnt, flags);
}

MUSL_EXPORT ssize_t process_vm_readv(pid_t pid, const struct iovec *lvec, unsigned long liovcnt, const struct iovec *rvec, unsigned long riovcnt, unsigned long flags)
{
	return syscall(SYS_process_vm_readv, pid, lvec, liovcnt, rvec, riovcnt, flags);
}
