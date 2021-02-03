#include <stdlib.h>
#include <stdint.h>

static uint64_t seed;

MUSL_EXPORT void srand(unsigned s)
{
	seed = s-1;
}

MUSL_EXPORT int rand(void)
{
	seed = 6364136223846793005ULL*seed + 1;
	return seed>>33;
}
