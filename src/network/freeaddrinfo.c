#include <stdlib.h>
#include <stddef.h>
#include <netdb.h>
#include "lookup.h"
#include "lock.h"

MUSL_EXPORT void freeaddrinfo(struct addrinfo *p)
{
	size_t cnt;
	for (cnt=1; p->ai_next; cnt++, p=p->ai_next);
	struct aibuf *b = (void *)((char *)p - offsetof(struct aibuf, ai));
	b -= b->slot;
	LOCK(b->lock);
	if (!(b->ref -= cnt)) free(b);
	else UNLOCK(b->lock);
}
