#include <unistd.h>
#include <stdlib.h>

MUSL_EXPORT _Noreturn void _exit(int status)
{
	_Exit(status);
}
