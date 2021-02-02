#ifndef _CRYPT_H
#define _CRYPT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

struct crypt_data {
	int initialized;
	char __buf[256];
};

MUSL_EXPORT char *crypt(const char *, const char *);
MUSL_EXPORT char *crypt_r(const char *, const char *, struct crypt_data *);

#ifdef __cplusplus
}
#endif

#endif
