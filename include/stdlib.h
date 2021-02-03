#ifndef _STDLIB_H
#define _STDLIB_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#ifdef __cplusplus
#define NULL 0L
#else
#define NULL ((void*)0)
#endif

#define __NEED_size_t
#define __NEED_wchar_t

#include <bits/alltypes.h>

MUSL_EXPORT int atoi (const char *);
MUSL_EXPORT long atol (const char *);
MUSL_EXPORT long long atoll (const char *);
MUSL_EXPORT double atof (const char *);

MUSL_EXPORT float strtof (const char *__restrict, char **__restrict);
MUSL_EXPORT double strtod (const char *__restrict, char **__restrict);
MUSL_EXPORT long double strtold (const char *__restrict, char **__restrict);

MUSL_EXPORT long strtol (const char *__restrict, char **__restrict, int);
MUSL_EXPORT unsigned long strtoul (const char *__restrict, char **__restrict, int);
MUSL_EXPORT long long strtoll (const char *__restrict, char **__restrict, int);
MUSL_EXPORT unsigned long long strtoull (const char *__restrict, char **__restrict, int);

MUSL_EXPORT int rand (void);
MUSL_EXPORT void srand (unsigned);

MUSL_EXPORT void *malloc (size_t);
MUSL_EXPORT void *calloc (size_t, size_t);
MUSL_EXPORT void *realloc (void *, size_t);
MUSL_EXPORT void free (void *);
MUSL_EXPORT void *aligned_alloc(size_t, size_t);

MUSL_EXPORT _Noreturn void abort (void);
MUSL_EXPORT int atexit (void (*) (void));
MUSL_EXPORT _Noreturn void exit (int);
MUSL_WEAK _Noreturn void _Exit (int);
MUSL_EXPORT int at_quick_exit (void (*) (void));
_Noreturn void quick_exit (int);

MUSL_EXPORT char *getenv (const char *);

MUSL_EXPORT int system (const char *);

MUSL_EXPORT void *bsearch (const void *, const void *, size_t, size_t, int (*)(const void *, const void *));
MUSL_EXPORT void qsort (void *, size_t, size_t, int (*)(const void *, const void *));

MUSL_EXPORT int abs (int);
MUSL_EXPORT long labs (long);
MUSL_EXPORT long long llabs (long long);

typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;
typedef struct { long long quot, rem; } lldiv_t;

MUSL_EXPORT div_t div (int, int);
MUSL_EXPORT ldiv_t ldiv (long, long);
MUSL_EXPORT lldiv_t lldiv (long long, long long);

MUSL_EXPORT int mblen (const char *, size_t);
MUSL_EXPORT int mbtowc (wchar_t *__restrict, const char *__restrict, size_t);
MUSL_EXPORT int wctomb (char *, wchar_t);
MUSL_EXPORT size_t mbstowcs (wchar_t *__restrict, const char *__restrict, size_t);
MUSL_EXPORT size_t wcstombs (char *__restrict, const wchar_t *__restrict, size_t);

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

MUSL_EXPORT size_t __ctype_get_mb_cur_max(void);
#define MB_CUR_MAX (__ctype_get_mb_cur_max())

#define RAND_MAX (0x7fffffff)


#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) \
 || defined(_BSD_SOURCE)

#define WNOHANG    1
#define WUNTRACED  2

#define WEXITSTATUS(s) (((s) & 0xff00) >> 8)
#define WTERMSIG(s) ((s) & 0x7f)
#define WSTOPSIG(s) WEXITSTATUS(s)
#define WIFEXITED(s) (!WTERMSIG(s))
#define WIFSTOPPED(s) ((short)((((s)&0xffff)*0x10001)>>8) > 0x7f00)
#define WIFSIGNALED(s) (((s)&0xffff)-1U < 0xffu)

MUSL_EXPORT int posix_memalign (void **, size_t, size_t);
MUSL_EXPORT int setenv (const char *, const char *, int);
MUSL_EXPORT int unsetenv (const char *);
MUSL_EXPORT int mkstemp (char *);
MUSL_EXPORT int mkostemp (char *, int);
MUSL_EXPORT char *mkdtemp (char *);
MUSL_EXPORT int getsubopt (char **, char *const *, char **);
MUSL_EXPORT int rand_r (unsigned *);

#endif


#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) \
 || defined(_BSD_SOURCE)
MUSL_EXPORT char *realpath (const char *__restrict, char *__restrict);
MUSL_EXPORT long int random (void);
MUSL_EXPORT void srandom (unsigned int);
MUSL_EXPORT char *initstate (unsigned int, char *, size_t);
MUSL_EXPORT char *setstate (char *);
MUSL_EXPORT int putenv (char *);
MUSL_EXPORT int posix_openpt (int);
MUSL_EXPORT int grantpt (int);
MUSL_EXPORT int unlockpt (int);
MUSL_EXPORT char *ptsname (int);
MUSL_EXPORT char *l64a (long);
MUSL_EXPORT long a64l (const char *);
MUSL_EXPORT void setkey (const char *);
MUSL_EXPORT double drand48 (void);
MUSL_EXPORT double erand48 (unsigned short [3]);
MUSL_EXPORT long int lrand48 (void);
MUSL_EXPORT long int nrand48 (unsigned short [3]);
MUSL_EXPORT long mrand48 (void);
MUSL_EXPORT long jrand48 (unsigned short [3]);
MUSL_EXPORT void srand48 (long);
MUSL_EXPORT unsigned short *seed48 (unsigned short [3]);
MUSL_EXPORT void lcong48 (unsigned short [7]);
#endif

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#include <alloca.h>
MUSL_EXPORT char *mktemp (char *);
MUSL_EXPORT int mkstemps (char *, int);
MUSL_EXPORT int mkostemps (char *, int, int);
MUSL_EXPORT void *valloc (size_t);
MUSL_EXPORT void *memalign(size_t, size_t);
MUSL_EXPORT int getloadavg(double *, int);
MUSL_EXPORT int clearenv(void);
#define WCOREDUMP(s) ((s) & 0x80)
#define WIFCONTINUED(s) ((s) == 0xffff)
MUSL_EXPORT void *reallocarray (void *, size_t, size_t);
#endif

#ifdef _GNU_SOURCE
MUSL_EXPORT int ptsname_r(int, char *, size_t);
MUSL_EXPORT char *ecvt(double, int, int *, int *);
MUSL_EXPORT char *fcvt(double, int, int *, int *);
MUSL_EXPORT char *gcvt(double, int, char *);
MUSL_EXPORT char *secure_getenv(const char *);
struct __locale_struct;
MUSL_EXPORT float strtof_l(const char *__restrict, char **__restrict, struct __locale_struct *);
MUSL_EXPORT double strtod_l(const char *__restrict, char **__restrict, struct __locale_struct *);
MUSL_EXPORT long double strtold_l(const char *__restrict, char **__restrict, struct __locale_struct *);
#endif

#if defined(_LARGEFILE64_SOURCE) || defined(_GNU_SOURCE)
#define mkstemp64 mkstemp
#define mkostemp64 mkostemp
#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define mkstemps64 mkstemps
#define mkostemps64 mkostemps
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
