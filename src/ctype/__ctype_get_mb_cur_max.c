#include <stdlib.h>
#include "locale_impl.h"

MUSL_EXPORT size_t __ctype_get_mb_cur_max()
{
	return MB_CUR_MAX;
}
