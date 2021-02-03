#include <wchar.h>
#include <wctype.h>

MUSL_EXPORT int wcscasecmp(const wchar_t *l, const wchar_t *r)
{
	return wcsncasecmp(l, r, -1);
}
