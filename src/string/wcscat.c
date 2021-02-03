#include <wchar.h>

MUSL_EXPORT wchar_t *wcscat(wchar_t *restrict dest, const wchar_t *restrict src)
{
	wcscpy(dest + wcslen(dest), src);
	return dest;
}
