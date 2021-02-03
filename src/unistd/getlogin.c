#include <unistd.h>
#include <stdlib.h>

MUSL_EXPORT char *getlogin(void)
{
	return getenv("LOGNAME");
}
