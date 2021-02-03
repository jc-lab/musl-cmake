#include <wchar.h>

MUSL_EXPORT int wcscasecmp_l(const wchar_t *l, const wchar_t *r, locale_t locale)
{
	return wcscasecmp(l, r);
}
