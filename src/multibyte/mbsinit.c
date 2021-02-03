#include <wchar.h>

MUSL_EXPORT int mbsinit(const mbstate_t *st)
{
	return !st || !*(unsigned *)st;
}
