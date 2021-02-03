#define _GNU_SOURCE
#include <stdio.h>

MUSL_EXPORT int getw(FILE *f)
{
	int x;
	return fread(&x, sizeof x, 1, f) ? x : EOF;
}
