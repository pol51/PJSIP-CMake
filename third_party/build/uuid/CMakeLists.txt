file(GLOB_RECURSE UUID_SRC ../../uuid/*.c ../../uuid/*.h)
include_directories(../..)

if(TARGET_ANDROID)
  add_definitions(-DHAVE_INTTYPES_H -DHAVE_UNISTD_H -DHAVE_NETINET_IN_H -DHAVE_SYS_IOCTL_H -DHAVE_STDLIB_H)
endif()

if(TARGET_IOS)
  add_definitions(-DHAVE_UNISTD_H -DHAVE_STDLIB_H)
endif()

if(TARGET_LINUX)
  add_definitions(-DHAVE_INTTYPES_H)
endif()

add_library(uuid OBJECT ${UUID_SRC})
