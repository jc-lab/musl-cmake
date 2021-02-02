#ifndef _SYS_UIO_H
#define _SYS_UIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#define __NEED_size_t
#define __NEED_ssize_t
#define __NEED_struct_iovec

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define __NEED_off_t
#endif

#ifdef _GNU_SOURCE
#define __NEED_pid_t
#endif

#include <bits/alltypes.h>

#define UIO_MAXIOV 1024

MUSL_EXPORT ssize_t readv (int, const struct iovec *, int);
MUSL_EXPORT ssize_t writev (int, const struct iovec *, int);

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
MUSL_EXPORT ssize_t preadv (int, const struct iovec *, int, off_t);
MUSL_EXPORT ssize_t pwritev (int, const struct iovec *, int, off_t);
#if defined(_LARGEFILE64_SOURCE) || defined(_GNU_SOURCE)
#define preadv64 preadv
#define pwritev64 pwritev
#define off64_t off_t
#endif
#endif

#ifdef _GNU_SOURCE
MUSL_EXPORT ssize_t process_vm_writev(pid_t, const struct iovec *, unsigned long, const struct iovec *, unsigned long, unsigned long);
MUSL_EXPORT ssize_t process_vm_readv(pid_t, const struct iovec *, unsigned long, const struct iovec *, unsigned long, unsigned long);
#endif

#ifdef __cplusplus
}
#endif

#endif
