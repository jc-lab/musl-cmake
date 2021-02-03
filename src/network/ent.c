#include <netdb.h>

MUSL_EXPORT void sethostent(int x)
{
}

MUSL_EXPORT struct hostent *gethostent()
{
	return 0;
}

MUSL_EXPORT struct netent *getnetent()
{
	return 0;
}

MUSL_EXPORT void endhostent(void)
{
}

weak_alias(sethostent, setnetent);
weak_alias(endhostent, endnetent);
