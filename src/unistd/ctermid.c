#include <stdio.h>
#include <string.h>

MUSL_EXPORT char *ctermid(char *s)
{
	return s ? strcpy(s, "/dev/tty") : "/dev/tty";
}
