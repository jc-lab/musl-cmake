#ifndef	_UNISTD_H
#define	_UNISTD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#define STDIN_FILENO  0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#ifdef __cplusplus
#define NULL 0L
#else
#define NULL ((void*)0)
#endif

#define __NEED_size_t
#define __NEED_ssize_t
#define __NEED_uid_t
#define __NEED_gid_t
#define __NEED_off_t
#define __NEED_pid_t
#define __NEED_intptr_t
#define __NEED_useconds_t

#include <bits/alltypes.h>

MUSL_EXPORT int pipe(int [2]);
MUSL_EXPORT int pipe2(int [2], int);
MUSL_EXPORT int close(int);
MUSL_EXPORT int posix_close(int, int);
MUSL_EXPORT int dup(int);
MUSL_EXPORT int dup2(int, int);
MUSL_EXPORT int dup3(int, int, int);
MUSL_EXPORT off_t lseek(int, off_t, int);
MUSL_EXPORT int fsync(int);
MUSL_EXPORT int fdatasync(int);

MUSL_EXPORT ssize_t read(int, void *, size_t);
MUSL_EXPORT ssize_t write(int, const void *, size_t);
MUSL_EXPORT ssize_t pread(int, void *, size_t, off_t);
MUSL_EXPORT ssize_t pwrite(int, const void *, size_t, off_t);

MUSL_EXPORT int chown(const char *, uid_t, gid_t);
MUSL_EXPORT int fchown(int, uid_t, gid_t);
MUSL_EXPORT int lchown(const char *, uid_t, gid_t);
MUSL_EXPORT int fchownat(int, const char *, uid_t, gid_t, int);

MUSL_EXPORT int link(const char *, const char *);
MUSL_EXPORT int linkat(int, const char *, int, const char *, int);
MUSL_EXPORT int symlink(const char *, const char *);
MUSL_EXPORT int symlinkat(const char *, int, const char *);
MUSL_EXPORT ssize_t readlink(const char *__restrict, char *__restrict, size_t);
MUSL_EXPORT ssize_t readlinkat(int, const char *__restrict, char *__restrict, size_t);
MUSL_EXPORT int unlink(const char *);
MUSL_EXPORT int unlinkat(int, const char *, int);
MUSL_EXPORT int rmdir(const char *);
MUSL_EXPORT int truncate(const char *, off_t);
MUSL_EXPORT int ftruncate(int, off_t);

#define F_OK 0
#define R_OK 4
#define W_OK 2
#define X_OK 1

MUSL_EXPORT int access(const char *, int);
MUSL_EXPORT int faccessat(int, const char *, int, int);

MUSL_EXPORT int chdir(const char *);
MUSL_EXPORT int fchdir(int);
MUSL_EXPORT char *getcwd(char *, size_t);

MUSL_EXPORT unsigned alarm(unsigned);
MUSL_EXPORT unsigned sleep(unsigned);
MUSL_EXPORT int pause(void);

MUSL_EXPORT pid_t fork(void);
MUSL_EXPORT pid_t _Fork(void);
MUSL_EXPORT int execve(const char *, char *const [], char *const []);
MUSL_EXPORT int execv(const char *, char *const []);
MUSL_EXPORT int execle(const char *, const char *, ...);
MUSL_EXPORT int execl(const char *, const char *, ...);
MUSL_EXPORT int execvp(const char *, char *const []);
MUSL_EXPORT int execlp(const char *, const char *, ...);
MUSL_EXPORT int fexecve(int, char *const [], char *const []);
MUSL_EXPORT _Noreturn void _exit(int);

MUSL_EXPORT pid_t getpid(void);
MUSL_EXPORT pid_t getppid(void);
MUSL_EXPORT pid_t getpgrp(void);
MUSL_EXPORT pid_t getpgid(pid_t);
MUSL_EXPORT int setpgid(pid_t, pid_t);
MUSL_EXPORT pid_t setsid(void);
MUSL_EXPORT pid_t getsid(pid_t);
MUSL_EXPORT char *ttyname(int);
MUSL_EXPORT int ttyname_r(int, char *, size_t);
MUSL_EXPORT int isatty(int);
MUSL_EXPORT pid_t tcgetpgrp(int);
MUSL_EXPORT int tcsetpgrp(int, pid_t);

MUSL_EXPORT uid_t getuid(void);
MUSL_EXPORT uid_t geteuid(void);
MUSL_EXPORT gid_t getgid(void);
MUSL_EXPORT gid_t getegid(void);
MUSL_EXPORT int getgroups(int, gid_t []);
MUSL_EXPORT int setuid(uid_t);
MUSL_EXPORT int seteuid(uid_t);
MUSL_EXPORT int setgid(gid_t);
MUSL_EXPORT int setegid(gid_t);

MUSL_EXPORT char *getlogin(void);
MUSL_EXPORT int getlogin_r(char *, size_t);
MUSL_EXPORT int gethostname(char *, size_t);
MUSL_EXPORT char *ctermid(char *);

MUSL_EXPORT int getopt(int, char * const [], const char *);
extern char *optarg;
extern int optind, opterr, optopt;

MUSL_EXPORT long pathconf(const char *, int);
MUSL_EXPORT long fpathconf(int, int);
MUSL_EXPORT long sysconf(int);
MUSL_EXPORT size_t confstr(int, char *, size_t);

#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define F_ULOCK 0
#define F_LOCK  1
#define F_TLOCK 2
#define F_TEST  3
MUSL_EXPORT int setreuid(uid_t, uid_t);
MUSL_EXPORT int setregid(gid_t, gid_t);
MUSL_EXPORT int lockf(int, int, off_t);
MUSL_EXPORT long gethostid(void);
MUSL_EXPORT int nice(int);
MUSL_EXPORT void sync(void);
MUSL_EXPORT pid_t setpgrp(void);
MUSL_EXPORT char *crypt(const char *, const char *);
MUSL_EXPORT void encrypt(char *, int);
MUSL_EXPORT void swab(const void *__restrict, void *__restrict, ssize_t);
#endif

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE) \
 || (defined(_XOPEN_SOURCE) && _XOPEN_SOURCE+0 < 700)
MUSL_EXPORT int usleep(unsigned);
MUSL_EXPORT unsigned ualarm(unsigned, unsigned);
#endif

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define L_SET 0
#define L_INCR 1
#define L_XTND 2
MUSL_EXPORT int brk(void *);
MUSL_EXPORT void *sbrk(intptr_t);
MUSL_EXPORT pid_t vfork(void);
MUSL_EXPORT int vhangup(void);
MUSL_EXPORT int chroot(const char *);
MUSL_EXPORT int getpagesize(void);
MUSL_EXPORT int getdtablesize(void);
MUSL_EXPORT int sethostname(const char *, size_t);
MUSL_EXPORT int getdomainname(char *, size_t);
MUSL_EXPORT int setdomainname(const char *, size_t);
MUSL_EXPORT int setgroups(size_t, const gid_t *);
MUSL_EXPORT char *getpass(const char *);
MUSL_EXPORT int daemon(int, int);
MUSL_EXPORT void setusershell(void);
MUSL_EXPORT void endusershell(void);
MUSL_EXPORT char *getusershell(void);
MUSL_EXPORT int acct(const char *);
MUSL_EXPORT long syscall(long, ...);
MUSL_EXPORT int execvpe(const char *, char *const [], char *const []);
MUSL_EXPORT int issetugid(void);
MUSL_EXPORT int getentropy(void *, size_t);
extern int optreset;
#endif

#ifdef _GNU_SOURCE
extern char **environ;
MUSL_EXPORT int setresuid(uid_t, uid_t, uid_t);
MUSL_EXPORT int setresgid(gid_t, gid_t, gid_t);
MUSL_EXPORT int getresuid(uid_t *, uid_t *, uid_t *);
MUSL_EXPORT int getresgid(gid_t *, gid_t *, gid_t *);
MUSL_EXPORT char *get_current_dir_name(void);
MUSL_EXPORT int syncfs(int);
MUSL_EXPORT int euidaccess(const char *, int);
MUSL_EXPORT int eaccess(const char *, int);
MUSL_EXPORT ssize_t copy_file_range(int, off_t *, int, off_t *, size_t, unsigned);
MUSL_EXPORT pid_t gettid(void);
#endif

#if defined(_LARGEFILE64_SOURCE) || defined(_GNU_SOURCE)
#define lseek64 lseek
#define pread64 pread
#define pwrite64 pwrite
#define truncate64 truncate
#define ftruncate64 ftruncate
#define lockf64 lockf
#define off64_t off_t
#endif

#define POSIX_CLOSE_RESTART     0

#define _XOPEN_VERSION          700
#define _XOPEN_UNIX             1
#define _XOPEN_ENH_I18N         1

#define _POSIX_VERSION          200809L
#define _POSIX2_VERSION         _POSIX_VERSION

#define _POSIX_ADVISORY_INFO    _POSIX_VERSION
#define _POSIX_CHOWN_RESTRICTED 1
#define _POSIX_IPV6             _POSIX_VERSION
#define _POSIX_JOB_CONTROL      1
#define _POSIX_MAPPED_FILES     _POSIX_VERSION
#define _POSIX_MEMLOCK          _POSIX_VERSION
#define _POSIX_MEMLOCK_RANGE    _POSIX_VERSION
#define _POSIX_MEMORY_PROTECTION _POSIX_VERSION
#define _POSIX_MESSAGE_PASSING  _POSIX_VERSION
#define _POSIX_FSYNC            _POSIX_VERSION
#define _POSIX_NO_TRUNC         1
#define _POSIX_RAW_SOCKETS      _POSIX_VERSION
#define _POSIX_REALTIME_SIGNALS _POSIX_VERSION
#define _POSIX_REGEXP           1
#define _POSIX_SAVED_IDS        1
#define _POSIX_SHELL            1
#define _POSIX_SPAWN            _POSIX_VERSION
#define _POSIX_VDISABLE         0

#define _POSIX_THREADS          _POSIX_VERSION
#define _POSIX_THREAD_PROCESS_SHARED _POSIX_VERSION
#define _POSIX_THREAD_SAFE_FUNCTIONS _POSIX_VERSION
#define _POSIX_THREAD_ATTR_STACKADDR _POSIX_VERSION
#define _POSIX_THREAD_ATTR_STACKSIZE _POSIX_VERSION
#define _POSIX_THREAD_PRIORITY_SCHEDULING _POSIX_VERSION
#define _POSIX_THREAD_CPUTIME   _POSIX_VERSION
#define _POSIX_TIMERS           _POSIX_VERSION
#define _POSIX_TIMEOUTS         _POSIX_VERSION
#define _POSIX_MONOTONIC_CLOCK  _POSIX_VERSION
#define _POSIX_CPUTIME          _POSIX_VERSION
#define _POSIX_CLOCK_SELECTION  _POSIX_VERSION
#define _POSIX_BARRIERS         _POSIX_VERSION
#define _POSIX_SPIN_LOCKS       _POSIX_VERSION
#define _POSIX_READER_WRITER_LOCKS _POSIX_VERSION
#define _POSIX_ASYNCHRONOUS_IO  _POSIX_VERSION
#define _POSIX_SEMAPHORES       _POSIX_VERSION
#define _POSIX_SHARED_MEMORY_OBJECTS _POSIX_VERSION

#define _POSIX2_C_BIND          _POSIX_VERSION

#include <bits/posix.h>



#define _PC_LINK_MAX	0
#define _PC_MAX_CANON	1
#define _PC_MAX_INPUT	2
#define _PC_NAME_MAX	3
#define _PC_PATH_MAX	4
#define _PC_PIPE_BUF	5
#define _PC_CHOWN_RESTRICTED	6
#define _PC_NO_TRUNC	7
#define _PC_VDISABLE	8
#define _PC_SYNC_IO	9
#define _PC_ASYNC_IO	10
#define _PC_PRIO_IO	11
#define _PC_SOCK_MAXBUF	12
#define _PC_FILESIZEBITS	13
#define _PC_REC_INCR_XFER_SIZE	14
#define _PC_REC_MAX_XFER_SIZE	15
#define _PC_REC_MIN_XFER_SIZE	16
#define _PC_REC_XFER_ALIGN	17
#define _PC_ALLOC_SIZE_MIN	18
#define _PC_SYMLINK_MAX	19
#define _PC_2_SYMLINKS	20

#define _SC_ARG_MAX	0
#define _SC_CHILD_MAX	1
#define _SC_CLK_TCK	2
#define _SC_NGROUPS_MAX	3
#define _SC_OPEN_MAX	4
#define _SC_STREAM_MAX	5
#define _SC_TZNAME_MAX	6
#define _SC_JOB_CONTROL	7
#define _SC_SAVED_IDS	8
#define _SC_REALTIME_SIGNALS	9
#define _SC_PRIORITY_SCHEDULING	10
#define _SC_TIMERS	11
#define _SC_ASYNCHRONOUS_IO	12
#define _SC_PRIORITIZED_IO	13
#define _SC_SYNCHRONIZED_IO	14
#define _SC_FSYNC	15
#define _SC_MAPPED_FILES	16
#define _SC_MEMLOCK	17
#define _SC_MEMLOCK_RANGE	18
#define _SC_MEMORY_PROTECTION	19
#define _SC_MESSAGE_PASSING	20
#define _SC_SEMAPHORES	21
#define _SC_SHARED_MEMORY_OBJECTS	22
#define _SC_AIO_LISTIO_MAX	23
#define _SC_AIO_MAX	24
#define _SC_AIO_PRIO_DELTA_MAX	25
#define _SC_DELAYTIMER_MAX	26
#define _SC_MQ_OPEN_MAX	27
#define _SC_MQ_PRIO_MAX	28
#define _SC_VERSION	29
#define _SC_PAGE_SIZE	30
#define _SC_PAGESIZE	30 /* !! */
#define _SC_RTSIG_MAX	31
#define _SC_SEM_NSEMS_MAX	32
#define _SC_SEM_VALUE_MAX	33
#define _SC_SIGQUEUE_MAX	34
#define _SC_TIMER_MAX	35
#define _SC_BC_BASE_MAX	36
#define _SC_BC_DIM_MAX	37
#define _SC_BC_SCALE_MAX	38
#define _SC_BC_STRING_MAX	39
#define _SC_COLL_WEIGHTS_MAX	40
#define _SC_EXPR_NEST_MAX	42
#define _SC_LINE_MAX	43
#define _SC_RE_DUP_MAX	44
#define _SC_2_VERSION	46
#define _SC_2_C_BIND	47
#define _SC_2_C_DEV	48
#define _SC_2_FORT_DEV	49
#define _SC_2_FORT_RUN	50
#define _SC_2_SW_DEV	51
#define _SC_2_LOCALEDEF	52
#define _SC_UIO_MAXIOV	60 /* !! */
#define _SC_IOV_MAX	60
#define _SC_THREADS	67
#define _SC_THREAD_SAFE_FUNCTIONS	68
#define _SC_GETGR_R_SIZE_MAX	69
#define _SC_GETPW_R_SIZE_MAX	70
#define _SC_LOGIN_NAME_MAX	71
#define _SC_TTY_NAME_MAX	72
#define _SC_THREAD_DESTRUCTOR_ITERATIONS	73
#define _SC_THREAD_KEYS_MAX	74
#define _SC_THREAD_STACK_MIN	75
#define _SC_THREAD_THREADS_MAX	76
#define _SC_THREAD_ATTR_STACKADDR	77
#define _SC_THREAD_ATTR_STACKSIZE	78
#define _SC_THREAD_PRIORITY_SCHEDULING	79
#define _SC_THREAD_PRIO_INHERIT	80
#define _SC_THREAD_PRIO_PROTECT	81
#define _SC_THREAD_PROCESS_SHARED	82
#define _SC_NPROCESSORS_CONF	83
#define _SC_NPROCESSORS_ONLN	84
#define _SC_PHYS_PAGES	85
#define _SC_AVPHYS_PAGES	86
#define _SC_ATEXIT_MAX	87
#define _SC_PASS_MAX	88
#define _SC_XOPEN_VERSION	89
#define _SC_XOPEN_XCU_VERSION	90
#define _SC_XOPEN_UNIX	91
#define _SC_XOPEN_CRYPT	92
#define _SC_XOPEN_ENH_I18N	93
#define _SC_XOPEN_SHM	94
#define _SC_2_CHAR_TERM	95
#define _SC_2_UPE	97
#define _SC_XOPEN_XPG2	98
#define _SC_XOPEN_XPG3	99
#define _SC_XOPEN_XPG4	100
#define _SC_NZERO	109
#define _SC_XBS5_ILP32_OFF32	125
#define _SC_XBS5_ILP32_OFFBIG	126
#define _SC_XBS5_LP64_OFF64	127
#define _SC_XBS5_LPBIG_OFFBIG	128
#define _SC_XOPEN_LEGACY	129
#define _SC_XOPEN_REALTIME	130
#define _SC_XOPEN_REALTIME_THREADS	131
#define _SC_ADVISORY_INFO	132
#define _SC_BARRIERS	133
#define _SC_CLOCK_SELECTION	137
#define _SC_CPUTIME	138
#define _SC_THREAD_CPUTIME	139
#define _SC_MONOTONIC_CLOCK	149
#define _SC_READER_WRITER_LOCKS	153
#define _SC_SPIN_LOCKS	154
#define _SC_REGEXP	155
#define _SC_SHELL	157
#define _SC_SPAWN	159
#define _SC_SPORADIC_SERVER	160
#define _SC_THREAD_SPORADIC_SERVER	161
#define _SC_TIMEOUTS	164
#define _SC_TYPED_MEMORY_OBJECTS	165
#define _SC_2_PBS	168
#define _SC_2_PBS_ACCOUNTING	169
#define _SC_2_PBS_LOCATE	170
#define _SC_2_PBS_MESSAGE	171
#define _SC_2_PBS_TRACK	172
#define _SC_SYMLOOP_MAX	173
#define _SC_STREAMS	174
#define _SC_2_PBS_CHECKPOINT	175
#define _SC_V6_ILP32_OFF32	176
#define _SC_V6_ILP32_OFFBIG	177
#define _SC_V6_LP64_OFF64	178
#define _SC_V6_LPBIG_OFFBIG	179
#define _SC_HOST_NAME_MAX	180
#define _SC_TRACE	181
#define _SC_TRACE_EVENT_FILTER	182
#define _SC_TRACE_INHERIT	183
#define _SC_TRACE_LOG	184

#define _SC_IPV6	235
#define _SC_RAW_SOCKETS	236
#define _SC_V7_ILP32_OFF32	237
#define _SC_V7_ILP32_OFFBIG	238
#define _SC_V7_LP64_OFF64	239
#define _SC_V7_LPBIG_OFFBIG	240
#define _SC_SS_REPL_MAX	241
#define _SC_TRACE_EVENT_NAME_MAX	242
#define _SC_TRACE_NAME_MAX	243
#define _SC_TRACE_SYS_MAX	244
#define _SC_TRACE_USER_EVENT_MAX	245
#define _SC_XOPEN_STREAMS	246
#define _SC_THREAD_ROBUST_PRIO_INHERIT	247
#define _SC_THREAD_ROBUST_PRIO_PROTECT	248

#define _CS_PATH	0
#define _CS_POSIX_V6_WIDTH_RESTRICTED_ENVS	1
#define _CS_GNU_LIBC_VERSION	2
#define _CS_GNU_LIBPTHREAD_VERSION	3
#define _CS_POSIX_V5_WIDTH_RESTRICTED_ENVS	4
#define _CS_POSIX_V7_WIDTH_RESTRICTED_ENVS	5

#define _CS_POSIX_V6_ILP32_OFF32_CFLAGS	1116
#define _CS_POSIX_V6_ILP32_OFF32_LDFLAGS	1117
#define _CS_POSIX_V6_ILP32_OFF32_LIBS	1118
#define _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS	1119
#define _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS	1120
#define _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS	1121
#define _CS_POSIX_V6_ILP32_OFFBIG_LIBS	1122
#define _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS	1123
#define _CS_POSIX_V6_LP64_OFF64_CFLAGS	1124
#define _CS_POSIX_V6_LP64_OFF64_LDFLAGS	1125
#define _CS_POSIX_V6_LP64_OFF64_LIBS	1126
#define _CS_POSIX_V6_LP64_OFF64_LINTFLAGS	1127
#define _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS	1128
#define _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS	1129
#define _CS_POSIX_V6_LPBIG_OFFBIG_LIBS	1130
#define _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS	1131
#define _CS_POSIX_V7_ILP32_OFF32_CFLAGS	1132
#define _CS_POSIX_V7_ILP32_OFF32_LDFLAGS	1133
#define _CS_POSIX_V7_ILP32_OFF32_LIBS	1134
#define _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS	1135
#define _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS	1136
#define _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS	1137
#define _CS_POSIX_V7_ILP32_OFFBIG_LIBS	1138
#define _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS	1139
#define _CS_POSIX_V7_LP64_OFF64_CFLAGS	1140
#define _CS_POSIX_V7_LP64_OFF64_LDFLAGS	1141
#define _CS_POSIX_V7_LP64_OFF64_LIBS	1142
#define _CS_POSIX_V7_LP64_OFF64_LINTFLAGS	1143
#define _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS	1144
#define _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS	1145
#define _CS_POSIX_V7_LPBIG_OFFBIG_LIBS	1146
#define _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS	1147
#define _CS_V6_ENV	1148
#define _CS_V7_ENV	1149

#ifdef __cplusplus
}
#endif

#endif
