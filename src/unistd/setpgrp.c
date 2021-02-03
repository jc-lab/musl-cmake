#include <unistd.h>

MUSL_EXPORT pid_t setpgrp(void)
{
	return setpgid(0, 0);
}
