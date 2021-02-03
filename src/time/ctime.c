#include <time.h>

MUSL_EXPORT char *ctime(const time_t *t)
{
	struct tm *tm = localtime(t);
	if (!tm) return 0;
	return asctime(tm);
}
