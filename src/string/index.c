#define _BSD_SOURCE
#include <string.h>
#include <strings.h>

MUSL_EXPORT char *index(const char *s, int c)
{
	return strchr(s, c);
}
