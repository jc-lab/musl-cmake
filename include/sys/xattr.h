#ifndef	_SYS_XATTR_H
#define	_SYS_XATTR_H
#ifdef __cplusplus
extern "C" {
#endif

#define __NEED_ssize_t
#define __NEED_size_t
#include <bits/alltypes.h>

#define XATTR_CREATE 1
#define XATTR_REPLACE 2

MUSL_EXPORT ssize_t getxattr(const char *, const char *, void *, size_t);
MUSL_EXPORT ssize_t lgetxattr(const char *, const char *, void *, size_t);
MUSL_EXPORT ssize_t fgetxattr(int, const char *, void *, size_t);
MUSL_EXPORT ssize_t listxattr(const char *, char *, size_t);
MUSL_EXPORT ssize_t llistxattr(const char *, char *, size_t);
MUSL_EXPORT ssize_t flistxattr(int, char *, size_t);
MUSL_EXPORT int setxattr(const char *, const char *, const void *, size_t, int);
MUSL_EXPORT int lsetxattr(const char *, const char *, const void *, size_t, int);
MUSL_EXPORT int fsetxattr(int, const char *, const void *, size_t, int);
MUSL_EXPORT int removexattr(const char *, const char *);
MUSL_EXPORT int lremovexattr(const char *, const char *);
MUSL_EXPORT int fremovexattr(int, const char *);

#define __UAPI_DEF_XATTR        0

#ifdef __cplusplus
}
#endif
#endif
