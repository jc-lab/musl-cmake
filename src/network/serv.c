#include <netdb.h>

MUSL_EXPORT void endservent(void)
{
}

MUSL_EXPORT void setservent(int stayopen)
{
}

MUSL_EXPORT struct servent *getservent(void)
{
	return 0;
}
