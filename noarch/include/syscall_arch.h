#define __SYSCALL_LL_E(x) (x)
#define __SYSCALL_LL_O(x) (x)

extern long __musl__syscall0(long n);
extern long __musl__syscall1(long n, long a1);
extern long __musl__syscall2(long n, long a1, long a2);
extern long __musl__syscall3(long n, long a1, long a2, long a3);
extern long __musl__syscall4(long n, long a1, long a2, long a3, long a4);
extern long __musl__syscall5(long n, long a1, long a2, long a3, long a4, long a5);
extern long __musl__syscall6(long n, long a1, long a2, long a3, long a4, long a5, long a6);

static __inline long __syscall0(long n)
{
  return __musl__syscall0(n);
}

static __inline long __syscall1(long n, long a1)
{
  return __musl__syscall1(n, a1);
}

static __inline long __syscall2(long n, long a1, long a2)
{
  return __musl__syscall2(n, a1, a2);
}

static __inline long __syscall3(long n, long a1, long a2, long a3)
{
  return __musl__syscall3(n, a1, a2, a3);
}

static __inline long __syscall4(long n, long a1, long a2, long a3, long a4)
{
  return __musl__syscall4(n, a1, a2, a3, a4);
}

static __inline long __syscall5(long n, long a1, long a2, long a3, long a4, long a5)
{
  return __musl__syscall5(n, a1, a2, a3, a4, a5);
}

static __inline long __syscall6(long n, long a1, long a2, long a3, long a4, long a5, long a6)
{
  return __musl__syscall6(n, a1, a2, a3, a4, a5, a6);
}

#define VDSO_USEFUL
#define VDSO_CGT_SYM "__vdso_clock_gettime"
#define VDSO_CGT_VER "LINUX_2.6"
#define VDSO_GETCPU_SYM "__vdso_getcpu"
#define VDSO_GETCPU_VER "LINUX_2.6"

#define IPC_64 0
