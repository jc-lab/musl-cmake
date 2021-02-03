#include <sys/personality.h>
#include "syscall.h"
#ifdef SYS_personality
MUSL_EXPORT int personality(unsigned long persona)
{
	return syscall(SYS_personality, persona);
}
#endif
