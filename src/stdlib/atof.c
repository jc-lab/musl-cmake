#include <stdlib.h>

MUSL_EXPORT double atof(const char *s)
{
	return strtod(s, 0);
}
