#include "pwf.h"

static FILE *f;
static char *line;
static struct passwd pw;
static size_t size;

MUSL_EXPORT void setpwent()
{
	if (f) fclose(f);
	f = 0;
}

weak_alias(setpwent, endpwent);

MUSL_EXPORT struct passwd *getpwent()
{
	struct passwd *res;
	if (!f) f = fopen("/etc/passwd", "rbe");
	if (!f) return 0;
	__getpwent_a(f, &pw, &line, &size, &res);
	return res;
}

MUSL_EXPORT struct passwd *getpwuid(uid_t uid)
{
	struct passwd *res;
	__getpw_a(0, uid, &pw, &line, &size, &res);
	return res;
}

MUSL_EXPORT struct passwd *getpwnam(const char *name)
{
	struct passwd *res;
	__getpw_a(name, 0, &pw, &line, &size, &res);
	return res;
}
