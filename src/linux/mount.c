#include <sys/mount.h>
#include "syscall.h"

MUSL_EXPORT int mount(const char *special, const char *dir, const char *fstype, unsigned long flags, const void *data)
{
	return syscall(SYS_mount, special, dir, fstype, flags, data);
}

MUSL_EXPORT int umount(const char *special)
{
	return syscall(SYS_umount2, special, 0);
}

MUSL_EXPORT int umount2(const char *special, int flags)
{
	return syscall(SYS_umount2, special, flags);
}
