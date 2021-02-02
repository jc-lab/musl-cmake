#ifndef _SYS_FSUID_H
#define _SYS_FSUID_H

#ifdef __cplusplus
extern "C" {
#endif

#define __NEED_uid_t
#define __NEED_gid_t

#include <bits/alltypes.h>

MUSL_EXPORT int setfsuid(uid_t);
MUSL_EXPORT int setfsgid(gid_t);

#ifdef __cplusplus
}
#endif

#endif
