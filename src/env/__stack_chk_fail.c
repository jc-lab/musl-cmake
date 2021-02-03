#include <string.h>
#include <stdint.h>
#include "pthread_impl.h"

MUSL_EXPORT uintptr_t __stack_chk_guard;

MUSL_EXPORT void __init_ssp(void *entropy)
{
	if (entropy) memcpy(&__stack_chk_guard, entropy, sizeof(uintptr_t));
	else __stack_chk_guard = (uintptr_t)&__stack_chk_guard * 1103515245;

	__pthread_self()->canary = __stack_chk_guard;
}

MUSL_EXPORT void __stack_chk_fail(void)
{
	a_crash();
}

hidden void __stack_chk_fail_local(void);

weak_alias(__stack_chk_fail, __stack_chk_fail_local);
