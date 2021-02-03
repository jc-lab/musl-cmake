#include <dirent.h>
#include "__dirent.h"

MUSL_EXPORT long telldir(DIR *dir)
{
	return dir->tell;
}
