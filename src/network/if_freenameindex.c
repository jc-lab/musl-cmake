#include <net/if.h>
#include <stdlib.h>

MUSL_EXPORT void if_freenameindex(struct if_nameindex *idx)
{
	free(idx);
}
