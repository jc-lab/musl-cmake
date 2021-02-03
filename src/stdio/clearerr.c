#include "stdio_impl.h"

MUSL_EXPORT void clearerr(FILE *f)
{
	FLOCK(f);
	f->flags &= ~(F_EOF|F_ERR);
	FUNLOCK(f);
}

weak_alias(clearerr, clearerr_unlocked);
