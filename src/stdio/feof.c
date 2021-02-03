#include "stdio_impl.h"

#undef feof

MUSL_EXPORT int feof(FILE *f)
{
	FLOCK(f);
	int ret = !!(f->flags & F_EOF);
	FUNLOCK(f);
	return ret;
}

weak_alias(feof, feof_unlocked);
weak_alias(feof, _IO_feof_unlocked);
