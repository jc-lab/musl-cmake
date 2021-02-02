#ifndef	_SYS_IO_H
#define	_SYS_IO_H
#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#include <bits/io.h>

MUSL_EXPORT int iopl(int);
MUSL_EXPORT int ioperm(unsigned long, unsigned long, int);

#ifdef __cplusplus
}
#endif
#endif
