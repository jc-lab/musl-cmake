#include <netinet/in.h>
#include <byteswap.h>

MUSL_EXPORT uint16_t ntohs(uint16_t n)
{
	union { int i; char c; } u = { 1 };
	return u.c ? bswap_16(n) : n;
}
