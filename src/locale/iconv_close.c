#include <iconv.h>
#include <stdlib.h>

MUSL_EXPORT int iconv_close(iconv_t cd)
{
	if (!((size_t)cd & 1)) free((void *)cd);
	return 0;
}
