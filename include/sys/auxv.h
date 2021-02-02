#ifndef _SYS_AUXV_H
#define _SYS_AUXV_H

#ifdef __cplusplus
extern "C" {
#endif

#include <elf.h>
#include <bits/hwcap.h>

MUSL_EXPORT unsigned long getauxval(unsigned long);

#ifdef __cplusplus
}
#endif

#endif
