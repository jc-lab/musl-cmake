#define _GNU_SOURCE
#include "stdio_impl.h"
#include <stdio_ext.h>

MUSL_EXPORT void _flushlbf(void)
{
	fflush(0);
}

MUSL_EXPORT int __fsetlocking(FILE *f, int type)
{
	return 0;
}

MUSL_EXPORT int __fwriting(FILE *f)
{
	return (f->flags & F_NORD) || f->wend;
}

MUSL_EXPORT int __freading(FILE *f)
{
	return (f->flags & F_NOWR) || f->rend;
}

MUSL_EXPORT int __freadable(FILE *f)
{
	return !(f->flags & F_NORD);
}

MUSL_EXPORT int __fwritable(FILE *f)
{
	return !(f->flags & F_NOWR);
}

MUSL_EXPORT int __flbf(FILE *f)
{
	return f->lbf >= 0;
}

MUSL_EXPORT size_t __fbufsize(FILE *f)
{
	return f->buf_size;
}

MUSL_EXPORT size_t __fpending(FILE *f)
{
	return f->wend ? f->wpos - f->wbase : 0;
}

MUSL_EXPORT int __fpurge(FILE *f)
{
	f->wpos = f->wbase = f->wend = 0;
	f->rpos = f->rend = 0;
	return 0;
}

weak_alias(__fpurge, fpurge);
