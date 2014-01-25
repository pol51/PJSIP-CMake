cmake_minimum_required(VERSION 2.8.8)

project(pjsip)

set(CMAKE_VERBOSE_MAKEFILE ON)

# os specific
set(TARGET_LINUX OFF CACHE BOOL "target os is linux")

if(TARGET_LINUX)
  set(CMAKE_SYSTEM_NAME Linux)
  add_definitions(-DPJ_LINUX=1 -DPA_USE_ALSA=1 -DPA_USE_OSS=0 -DHAVE_SYS_SOUNDCARD_H)
  set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} -fPIC)
  set(OS_LIBS asound ssl rt m)
endif()

# subfolders
set(PJSIP_SUBDIRECTORIES pjlib pjlib-util pjnath pjmedia)

foreach(SUBDIRECTORY ${PJSIP_SUBDIRECTORIES})
  set(PJSIP_INCLUDES ${PJSIP_INCLUDES} ${SUBDIRECTORY}/include/)
endforeach()
include_directories(${CMAKE_FIND_ROOT_PATH}/usr/include})
include_directories(AFTER SYSTEM . ${PJSIP_INCLUDES} ${CMAKE_BINARY_DIR})

add_subdirectory(third_party/build)
foreach(SUBDIRECTORY ${PJSIP_SUBDIRECTORIES})
  add_subdirectory(${SUBDIRECTORY}/build)
  set(TARGET_OBJECTS_LIST ${TARGET_OBJECTS_LIST} $<TARGET_OBJECTS:${SUBDIRECTORY}>)
endforeach()

# target
add_library(${PROJECT_NAME} SHARED ${TARGET_OBJECTS_LIST} ${THIRDPARTY_OBJECTS_LIST})
target_link_libraries(${PROJECT_NAME} ${OS_LIBS})
