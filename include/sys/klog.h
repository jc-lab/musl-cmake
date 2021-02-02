#ifndef	_SYS_KLOG_H
#define	_SYS_KLOG_H

#ifdef __cplusplus
extern "C" {
#endif

MUSL_EXPORT int klogctl (int, char *, int);

#ifdef __cplusplus
}
#endif

#endif
