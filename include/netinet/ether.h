#ifndef _NETINET_ETHER_H
#define _NETINET_ETHER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <netinet/if_ether.h>

MUSL_EXPORT char *ether_ntoa (const struct ether_addr *);
MUSL_EXPORT struct ether_addr *ether_aton (const char *);
MUSL_EXPORT char *ether_ntoa_r (const struct ether_addr *, char *);
MUSL_EXPORT struct ether_addr *ether_aton_r (const char *, struct ether_addr *);
MUSL_EXPORT int ether_line(const char *, struct ether_addr *, char *);
MUSL_EXPORT int ether_ntohost(char *, const struct ether_addr *);
MUSL_EXPORT int ether_hostton(const char *, struct ether_addr *);

#ifdef __cplusplus
}
#endif

#endif
