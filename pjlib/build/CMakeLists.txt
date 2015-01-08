set(PJLIB_SRC
  ../src/pj/activesock.c
  ../src/pj/addr_resolv_sock.c
  ../src/pj/array.c
  ../src/pj/config.c
  ../src/pj/errno.c
  ../src/pj/except.c
  ../src/pj/guid.c
  ../src/pj/guid_simple.c
  ../src/pj/hash.c
  ../src/pj/ip_helper_generic.c
  ../src/pj/list.c
  ../src/pj/lock.c
  ../src/pj/log.c
  ../src/pj/ioqueue_select.c
  ../src/pj/os_info.c
  ../src/pj/os_time_common.c
  ../src/pj/os_timestamp_common.c
  ../src/pj/pool.c
  ../src/pj/pool_buf.c
  ../src/pj/pool_caching.c
  ../src/pj/pool_policy_malloc.c
  ../src/pj/rand.c
  ../src/pj/sock_common.c
  ../src/pj/sock_qos_common.c
  ../src/pj/string.c
  ../src/pj/timer.c
  ../src/pj/types.c
  ../src/pj/sock_select.c)

set(PJLIB_INC
  ../include/pj/activesock.h
  ../include/pj/addr_resolv.h
  ../include/pj/array.h
  ../include/pj/assert.h
  ../include/pj/config.h
  ../include/pj/config_site.h
  ../include/pj/config_site_sample.h
  ../include/pj/errno.h
  ../include/pj/file_access.h
  ../include/pj/file_io.h
  ../include/pj/ip_helper.h
  ../include/pj/lock.h
  ../include/pj/log.h
  ../include/pj/os.h
  ../include/pj/pool.h
  ../include/pj/sock.h
  ../include/pj/sock_select.h
  ../include/pj/string.h
  ../include/pj/types.h
  ../include/pj/compat/errno.h
  ../include/pj/compat/socket.h
  ../include/pj/compat/stdarg.h
  ../include/pj/compat/string.h)

if(WITH_SSL)
  set(PJLIB_SRC ${PJLIB_SRC}
    ../src/pj/ssl_sock_common.c
    ../src/pj/ssl_sock_dump.c
    ../src/pj/ssl_sock_ossl.c)
endif()

if(WITH_BUILTIN_OPENSSL)
  include_directories(BEFORE SYSTEM ../../third_party/openssl ../../third_party ${CMAKE_BINARY_DIR}/third_party/build/openssl ${CMAKE_BINARY_DIR}/third_party/build/openssl/openssl/crypto)
endif()

if(TARGET_LINUX OR TARGET_MACOSX OR TARGET_ANDROID OR TARGET_IOS)
  set(PJLIB_SRC ${PJLIB_SRC}
    ../src/pj/addr_resolv_sock.c
    ../src/pj/file_access_unistd.c
    ../src/pj/file_io_ansi.c
    ../src/pj/ioqueue_select.c
    ../src/pj/log_writer_stdout.c
    ../src/pj/os_core_unix.c
    ../src/pj/os_error_unix.c
    ../src/pj/os_time_unix.c
    ../src/pj/os_timestamp_posix.c
    ../src/pj/sock_bsd.c
    ../src/pj/sock_qos_bsd.c)

  if(TARGET_LINUX)
    set(PJLIB_INC ${PJLIB_INC} ../include/pj/compat/os_linux.h)

  elseif(TARGET_MACOSX)
    set(PJLIB_INC ${PJLIB_INC} ../include/pj/compat/os_darwinos.h)

  elseif(TARGET_IOS)
    set(PJLIB_SRC ${PJLIB_SRC}
      ../src/pj/os_info_iphone.m)

  elseif(TARGET_ANDROID)
    set(PJLIB_INC ${PJLIB_INC} ../include/pj/compat/os_android.h)

    list(REMOVE_ITEM PJLIB_SRC ../src/pj/os_core_unix.c)
    set(PJLIB_SRC ${PJLIB_SRC} ../src/pj/os_core_android.c)
    list(REMOVE_ITEM PJLIB_SRC ../src/pj/log_writer_stdout.c)
    set(PJLIB_SRC ${PJLIB_SRC} ../src/pj/log_writer_logcat.c)
  endif()
endif()

add_library(pjlib OBJECT ${PJLIB_SRC} ${PJLIB_INC})
