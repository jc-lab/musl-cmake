#include <resolv.h>

/* This is completely unused, and exists purely to satisfy broken apps. */

MUSL_EXPORT struct __res_state *__res_state()
{
	static struct __res_state res;
	return &res;
}
