#ifndef _STDIO_H
#define _STDIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#define __NEED_FILE
#define __NEED___isoc_va_list
#define __NEED_size_t

#if __STDC_VERSION__ < 201112L
#define __NEED_struct__IO_FILE
#endif

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) \
 || defined(_BSD_SOURCE)
#define __NEED_ssize_t
#define __NEED_off_t
#define __NEED_va_list
#endif

#include <bits/alltypes.h>

#ifdef __cplusplus
#define NULL 0L
#else
#define NULL ((void*)0)
#endif

#undef EOF
#define EOF (-1)

#undef SEEK_SET
#undef SEEK_CUR
#undef SEEK_END
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#define _IOFBF 0
#define _IOLBF 1
#define _IONBF 2

#define BUFSIZ 1024
#define FILENAME_MAX 4096
#define FOPEN_MAX 1000
#define TMP_MAX 10000
#define L_tmpnam 20

typedef union _G_fpos64_t {
	char __opaque[16];
	long long __lldata;
	double __align;
} fpos_t;

extern FILE *const stdin;
extern FILE *const stdout;
extern FILE *const stderr;

#define stdin  (stdin)
#define stdout (stdout)
#define stderr (stderr)

MUSL_EXPORT FILE *fopen(const char *__restrict, const char *__restrict);
MUSL_EXPORT FILE *freopen(const char *__restrict, const char *__restrict, FILE *__restrict);
MUSL_EXPORT int fclose(FILE *);

MUSL_EXPORT int remove(const char *);
MUSL_EXPORT int rename(const char *, const char *);

MUSL_EXPORT int feof(FILE *);
MUSL_EXPORT int ferror(FILE *);
MUSL_EXPORT int fflush(FILE *);
MUSL_EXPORT void clearerr(FILE *);

MUSL_EXPORT int fseek(FILE *, long, int);
MUSL_EXPORT long ftell(FILE *);
MUSL_EXPORT void rewind(FILE *);

MUSL_EXPORT int fgetpos(FILE *__restrict, fpos_t *__restrict);
MUSL_EXPORT int fsetpos(FILE *, const fpos_t *);

MUSL_EXPORT size_t fread(void *__restrict, size_t, size_t, FILE *__restrict);
MUSL_EXPORT size_t fwrite(const void *__restrict, size_t, size_t, FILE *__restrict);

MUSL_EXPORT int fgetc(FILE *);
MUSL_EXPORT int getc(FILE *);
MUSL_EXPORT int getchar(void);
MUSL_EXPORT int ungetc(int, FILE *);

MUSL_EXPORT int fputc(int, FILE *);
MUSL_EXPORT int putc(int, FILE *);
MUSL_EXPORT int putchar(int);

MUSL_EXPORT char *fgets(char *__restrict, int, FILE *__restrict);
#if __STDC_VERSION__ < 201112L
MUSL_EXPORT char *gets(char *);
#endif

MUSL_EXPORT int fputs(const char *__restrict, FILE *__restrict);
MUSL_EXPORT int puts(const char *);

MUSL_EXPORT int printf(const char *__restrict, ...);
MUSL_EXPORT int fprintf(FILE *__restrict, const char *__restrict, ...);
MUSL_EXPORT int sprintf(char *__restrict, const char *__restrict, ...);
MUSL_EXPORT int snprintf(char *__restrict, size_t, const char *__restrict, ...);

MUSL_EXPORT int vprintf(const char *__restrict, __isoc_va_list);
MUSL_EXPORT int vfprintf(FILE *__restrict, const char *__restrict, __isoc_va_list);
MUSL_EXPORT int vsprintf(char *__restrict, const char *__restrict, __isoc_va_list);
MUSL_EXPORT int vsnprintf(char *__restrict, size_t, const char *__restrict, __isoc_va_list);

MUSL_EXPORT int scanf(const char *__restrict, ...);
MUSL_EXPORT int fscanf(FILE *__restrict, const char *__restrict, ...);
MUSL_EXPORT int sscanf(const char *__restrict, const char *__restrict, ...);
MUSL_EXPORT int vscanf(const char *__restrict, __isoc_va_list);
MUSL_EXPORT int vfscanf(FILE *__restrict, const char *__restrict, __isoc_va_list);
MUSL_EXPORT int vsscanf(const char *__restrict, const char *__restrict, __isoc_va_list);

MUSL_EXPORT void perror(const char *);

MUSL_EXPORT int setvbuf(FILE *__restrict, char *__restrict, int, size_t);
MUSL_EXPORT void setbuf(FILE *__restrict, char *__restrict);

MUSL_EXPORT char *tmpnam(char *);
MUSL_EXPORT FILE *tmpfile(void);

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) \
 || defined(_BSD_SOURCE)
MUSL_EXPORT FILE *fmemopen(void *__restrict, size_t, const char *__restrict);
MUSL_EXPORT FILE *open_memstream(char **, size_t *);
MUSL_EXPORT FILE *fdopen(int, const char *);
MUSL_EXPORT FILE *popen(const char *, const char *);
MUSL_EXPORT int pclose(FILE *);
MUSL_EXPORT int fileno(FILE *);
MUSL_EXPORT int fseeko(FILE *, off_t, int);
MUSL_EXPORT off_t ftello(FILE *);
MUSL_EXPORT int dprintf(int, const char *__restrict, ...);
MUSL_EXPORT int vdprintf(int, const char *__restrict, __isoc_va_list);
MUSL_EXPORT void flockfile(FILE *);
MUSL_EXPORT int ftrylockfile(FILE *);
MUSL_EXPORT void funlockfile(FILE *);
MUSL_EXPORT int getc_unlocked(FILE *);
MUSL_EXPORT int getchar_unlocked(void);
MUSL_EXPORT int putc_unlocked(int, FILE *);
MUSL_EXPORT int putchar_unlocked(int);
MUSL_EXPORT ssize_t getdelim(char **__restrict, size_t *__restrict, int, FILE *__restrict);
MUSL_EXPORT ssize_t getline(char **__restrict, size_t *__restrict, FILE *__restrict);
MUSL_EXPORT int renameat(int, const char *, int, const char *);
MUSL_EXPORT char *ctermid(char *);
#define L_ctermid 20
#endif


#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) \
 || defined(_BSD_SOURCE)
#define P_tmpdir "/tmp"
MUSL_EXPORT char *tempnam(const char *, const char *);
#endif

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define L_cuserid 20
MUSL_EXPORT char *cuserid(char *);
MUSL_EXPORT void setlinebuf(FILE *);
MUSL_EXPORT void setbuffer(FILE *, char *, size_t);
MUSL_EXPORT int fgetc_unlocked(FILE *);
MUSL_EXPORT int fputc_unlocked(int, FILE *);
MUSL_EXPORT int fflush_unlocked(FILE *);
MUSL_EXPORT size_t fread_unlocked(void *, size_t, size_t, FILE *);
MUSL_EXPORT size_t fwrite_unlocked(const void *, size_t, size_t, FILE *);
MUSL_EXPORT void clearerr_unlocked(FILE *);
MUSL_EXPORT int feof_unlocked(FILE *);
MUSL_EXPORT int ferror_unlocked(FILE *);
MUSL_EXPORT int fileno_unlocked(FILE *);
MUSL_EXPORT int getw(FILE *);
MUSL_EXPORT int putw(int, FILE *);
MUSL_EXPORT char *fgetln(FILE *, size_t *);
MUSL_EXPORT int asprintf(char **, const char *, ...);
MUSL_EXPORT int vasprintf(char **, const char *, __isoc_va_list);
#endif

#ifdef _GNU_SOURCE
MUSL_EXPORT char *fgets_unlocked(char *, int, FILE *);
MUSL_EXPORT int fputs_unlocked(const char *, FILE *);

MUSL_EXPORT typedef ssize_t (cookie_read_function_t)(void *, char *, size_t);
MUSL_EXPORT typedef ssize_t (cookie_write_function_t)(void *, const char *, size_t);
MUSL_EXPORT typedef int (cookie_seek_function_t)(void *, off_t *, int);
MUSL_EXPORT typedef int (cookie_close_function_t)(void *);

typedef struct _IO_cookie_io_functions_t {
	cookie_read_function_t *read;
	cookie_write_function_t *write;
	cookie_seek_function_t *seek;
	cookie_close_function_t *close;
} cookie_io_functions_t;

MUSL_EXPORT FILE *fopencookie(void *, const char *, cookie_io_functions_t);
#endif

#if defined(_LARGEFILE64_SOURCE) || defined(_GNU_SOURCE)
#define tmpfile64 tmpfile
#define fopen64 fopen
#define freopen64 freopen
#define fseeko64 fseeko
#define ftello64 ftello
#define fgetpos64 fgetpos
#define fsetpos64 fsetpos
#define fpos64_t fpos_t
#define off64_t off_t
#endif

#ifdef __cplusplus
}
#endif

#endif
