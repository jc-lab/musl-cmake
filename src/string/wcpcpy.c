#include <wchar.h>

MUSL_EXPORT wchar_t *wcpcpy(wchar_t *restrict d, const wchar_t *restrict s)
{
	return wcscpy(d, s) + wcslen(s);
}
