#include <sys/sysinfo.h>
#include <unistd.h>

MUSL_EXPORT int get_nprocs_conf()
{
	return sysconf(_SC_NPROCESSORS_CONF);
}

MUSL_EXPORT int get_nprocs()
{
	return sysconf(_SC_NPROCESSORS_ONLN);
}

MUSL_EXPORT long get_phys_pages()
{
	return sysconf(_SC_PHYS_PAGES);	
}

MUSL_EXPORT long get_avphys_pages()
{
	return sysconf(_SC_AVPHYS_PAGES);	
}
