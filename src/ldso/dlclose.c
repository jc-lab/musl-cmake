#include <dlfcn.h>
#include "dynlink.h"

MUSL_EXPORT int dlclose(void *p)
{
	return __dl_invalid_handle(p);
}
