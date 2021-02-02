#ifndef	_PTY_H
#define	_PTY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <termios.h>
#include <sys/ioctl.h>

MUSL_EXPORT int openpty(int *, int *, char *, const struct termios *, const struct winsize *);
MUSL_EXPORT int forkpty(int *, char *, const struct termios *, const struct winsize *);

#ifdef __cplusplus
}
#endif

#endif
