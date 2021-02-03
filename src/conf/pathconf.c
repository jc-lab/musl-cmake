#include <unistd.h>

MUSL_EXPORT long pathconf(const char *path, int name)
{
	return fpathconf(-1, name);
}
