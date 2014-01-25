cmake_minimum_required(VERSION 2.8)

project(pjsip)

set(target_name PJSIP)

set(cmake_verbose_makefile off)

set(PJSIP_SUBDIRECTORY pjlib/build pjlib-util/build)

set(PJSIP_INCLUDES
  .
  pjlib/include/
  pjlib-util/include/)

include_directories(${CMAKE_FIND_ROOT_PATH}/usr/include})
include_directories(after system ${PJSIP_INCLUDES} ${CMAKE_BINARY_DIR})

foreach(SUBDIRECTORY ${PJSIP_SUBDIRECTORY})
  add_subdirectory(${SUBDIRECTORY})
endforeach()

set(TARGET_LINUX off cache bool "target os is linux")

if(TARGET_LINUX)
  set(CMAKE_SYSTEM_NAME Linux)
  add_definitions(-DPJ_LINUX=1 -DPA_USE_ALSA=1 -DPA_USE_OSS=0 -DHAVE_SYS_SOUNDCARD_H)
  set(OS_LIBS asound ssl rt m)
endif()
