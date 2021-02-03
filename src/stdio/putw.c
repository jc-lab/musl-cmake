#define _GNU_SOURCE
#include <stdio.h>

MUSL_EXPORT int putw(int x, FILE *f)
{
	return (int)fwrite(&x, sizeof x, 1, f)-1;
}
