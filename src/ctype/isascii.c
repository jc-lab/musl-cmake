#include <ctype.h>
#undef isascii

MUSL_EXPORT int isascii(int c)
{
	return !(c&~0x7f);
}
