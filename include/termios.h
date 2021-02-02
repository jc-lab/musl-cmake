#ifndef	_TERMIOS_H
#define	_TERMIOS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#define __NEED_pid_t
#define __NEED_struct_winsize

#include <bits/alltypes.h>

typedef unsigned char cc_t;
typedef unsigned int speed_t;
typedef unsigned int tcflag_t;

#define NCCS 32

#include <bits/termios.h>

MUSL_EXPORT speed_t cfgetospeed (const struct termios *);
MUSL_EXPORT speed_t cfgetispeed (const struct termios *);
MUSL_EXPORT int cfsetospeed (struct termios *, speed_t);
MUSL_EXPORT int cfsetispeed (struct termios *, speed_t);

MUSL_EXPORT int tcgetattr (int, struct termios *);
MUSL_EXPORT int tcsetattr (int, int, const struct termios *);

MUSL_EXPORT int tcgetwinsize (int, struct winsize *);
MUSL_EXPORT int tcsetwinsize (int, const struct winsize *);

MUSL_EXPORT int tcsendbreak (int, int);
MUSL_EXPORT int tcdrain (int);
MUSL_EXPORT int tcflush (int, int);
MUSL_EXPORT int tcflow (int, int);

MUSL_EXPORT pid_t tcgetsid (int);

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
MUSL_EXPORT void cfmakeraw(struct termios *);
MUSL_EXPORT int cfsetspeed(struct termios *, speed_t);
#endif

#ifdef __cplusplus
}
#endif

#endif
