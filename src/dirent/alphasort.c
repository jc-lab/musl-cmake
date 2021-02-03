#include <string.h>
#include <dirent.h>

MUSL_EXPORT int alphasort(const struct dirent **a, const struct dirent **b)
{
	return strcoll((*a)->d_name, (*b)->d_name);
}

weak_alias(alphasort, alphasort64);
