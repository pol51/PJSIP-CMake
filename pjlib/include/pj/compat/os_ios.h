#ifndef __PJ_COMPAT_OS_IOS_H__
#define __PJ_COMPAT_OS_IOS_H__

/**
 * @file os_ios.h
 * @brief Describes operating system specifics
 */

/* Canonical OS name */
#define PJ_OS_NAME "arm-apple-darwin9"

#define PJ_CONFIG_IPHONE      1
#define TARGET_OS_IPHONE      1
#define PJ_IS_LITTLE_ENDIAN   1
#define PJ_IS_BIG_ENDIAN      0
#define PJ_HAS_FLOATING_POINT 1

//set minimal iOS version to 3.1
#ifdef  __IPHONE_OS_VERSION_MIN_REQUIRED
# undef  __IPHONE_OS_VERSION_MIN_REQUIRED
#endif
#define __IPHONE_OS_VERSION_MIN_REQUIRED 30100

/* Headers availability */
#define PJ_HAS_ARPA_INET_H 1
#define PJ_HAS_ASSERT_H 1
#define PJ_HAS_CTYPE_H 1
#define PJ_HAS_ERRNO_H 1
#define PJ_HAS_FCNTL_H 1
#define PJ_HAS_LIMITS_H 1
#define PJ_HAS_NETDB_H 1
#define PJ_HAS_NETINET_IN_SYSTM_H 1
#define PJ_HAS_NETINET_IN_H 1
#define PJ_HAS_NETINET_IP_H 1
#define PJ_HAS_NETINET_TCP_H 1
#define PJ_HAS_NET_IF_H 1
#define PJ_HAS_IFADDRS_H 1
#define PJ_HAS_SEMAPHORE_H 1
#define PJ_HAS_SETJMP_H 1
#define PJ_HAS_STDARG_H 1
#define PJ_HAS_STDDEF_H 1
#define PJ_HAS_STDIO_H 1
#define PJ_HAS_STDINT_H 1
#define PJ_HAS_STDLIB_H 1
#define PJ_HAS_STRING_H 1
#define PJ_HAS_SYS_IOCTL_H 1
#define PJ_HAS_SYS_SELECT_H 1
#define PJ_HAS_SYS_SOCKET_H 1
#define PJ_HAS_SYS_TIME_H 1
#define PJ_HAS_SYS_TIMEB_H 1
#define PJ_HAS_SYS_TYPES_H 1
#define PJ_HAS_SYS_FILIO_H 1
#define PJ_HAS_SYS_SOCKIO_H 1
#define PJ_HAS_SYS_UTSNAME_H 1
#define PJ_HAS_TIME_H 1
#define PJ_HAS_UNISTD_H 1

#define PJ_SOCK_HAS_INET_ATON 1
#define PJ_SOCK_HAS_INET_PTON 1
#define PJ_SOCK_HAS_INET_NTOP 1
#define PJ_SOCK_HAS_GETADDRINFO 1

/* On these OSes, semaphore feature depends on semaphore.h */
#if defined(PJ_HAS_SEMAPHORE_H) && PJ_HAS_SEMAPHORE_H!=0
# define PJ_HAS_SEMAPHORE	1
#else
# define PJ_HAS_SEMAPHORE	0
#endif

/* Set 1 if native sockaddr_in has sin_len member. 
 * Default: 0
 */
#define PJ_SOCKADDR_HAS_LEN 1

/* Does the OS have socklen_t? */
#define PJ_HAS_SOCKLEN_T 1

#if !defined(socklen_t) && (!defined(PJ_HAS_SOCKLEN_T) || PJ_HAS_SOCKLEN_T==0)
# define PJ_HAS_SOCKLEN_T 1
  typedef int socklen_t;
#endif

/**
 * If this macro is set, it tells select I/O Queue that select() needs to
 * be given correct value of nfds (i.e. largest fd + 1). This requires
 * select ioqueue to re-scan the descriptors on each registration and
 * unregistration.
 * If this macro is not set, then ioqueue will always give FD_SETSIZE for
 * nfds argument when calling select().
 *
 * Default: 0
 */
#define PJ_SELECT_NEEDS_NFDS 0

/* Is errno a good way to retrieve OS errors?
 */
#define PJ_HAS_ERRNO_VAR 1

/* When this macro is set, getsockopt(SOL_SOCKET, SO_ERROR) will return
 * the status of non-blocking connect() operation.
 */
#define PJ_HAS_SO_ERROR 1

/* This value specifies the value set in errno by the OS when a non-blocking
 * socket recv() can not return immediate daata.
 */
#define PJ_BLOCKING_ERROR_VAL EAGAIN

/* This value specifies the value set in errno by the OS when a non-blocking
 * socket connect() can not get connected immediately.
 */
#define PJ_BLOCKING_CONNECT_ERROR_VAL EINPROGRESS

/* Default threading is enabled, unless it's overridden. */
#ifndef PJ_HAS_THREADS
# define PJ_HAS_THREADS	    (1)
#endif

/* Do we need high resolution timer? */
#define PJ_HAS_HIGH_RES_TIMER 1

/* Is malloc() available? */
#define PJ_HAS_MALLOC 1

#ifndef PJ_OS_HAS_CHECK_STACK
# define PJ_OS_HAS_CHECK_STACK    0
#endif

/* Unicode? */
#define PJ_NATIVE_STRING_IS_UNICODE 0

/* Pool alignment in bytes */
#define PJ_POOL_ALIGNMENT 4

/* The type of atomic variable value: */
#define PJ_ATOMIC_VALUE_TYPE long

#include "TargetConditionals.h"
#include "Availability.h"

/* Use CFHost API for pj_getaddrinfo() (see ticket #1246) */
#define PJ_GETADDRINFO_USE_CFHOST 1

/* Disable local host resolution in pj_gethostip() (see ticket #1342) */
#define PJ_GETHOSTIP_DISABLE_LOCAL_RESOLUTION 1

/* Is multitasking support available?  (see ticket #1107) */
#define PJ_IPHONE_OS_HAS_MULTITASKING_SUPPORT 	1

/* Disable activesock TCP background mode support */
#define PJ_ACTIVESOCK_TCP_IPHONE_OS_BG		0

/* If 1, use Read/Write mutex emulation for platforms that don't support it */
#define PJ_EMULATE_RWMUTEX 0

/* If 1, pj_thread_create() should enforce the stack size when creating 
 * threads.
 * Default: 0 (let OS decide the thread's stack size).
 */
#define PJ_THREAD_SET_STACK_SIZE 0

/* If 1, pj_thread_create() should allocate stack from the pool supplied.
 * Default: 0 (let OS allocate memory for thread's stack).
 */
#define PJ_THREAD_ALLOCATE_STACK 0

#define PJMEDIA_HAS_SRTP 1

#endif

