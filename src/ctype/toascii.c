#include <ctype.h>

/* nonsense function that should NEVER be used! */
MUSL_EXPORT int toascii(int c)
{
	return c & 0x7f;
}
