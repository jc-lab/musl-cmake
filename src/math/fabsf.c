#include <math.h>
#include <stdint.h>

MUSL_EXPORT float fabsf(float x)
{
	union {float f; uint32_t i;} u = {x};
	u.i &= 0x7fffffff;
	return u.f;
}
