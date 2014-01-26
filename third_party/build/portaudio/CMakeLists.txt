file(GLOB_RECURSE PORTAUDIO_SRC
  ../../portaudio/src/common/*.c ../../portaudio/src/common/*.h
  ../../portaudio/include/*.h)

if(TARGET_LINUX)
  add_definitions(-DHAVE_SYS_SOUNDCARD_H=1)

  file(GLOB_RECURSE PORTAUDIO_OS_SRC
    ../../portaudio/src/os/unix/*.c ../../portaudio/src/os/unix/*.h
    ../../portaudio/src/hostapi/alsa/*.c ../../portaudio/src/hostapi/alsa/*.h # TODO add a build flag for alsa
    ../../portaudio/src/hostapi/oss/*.c ../../portaudio/src/hostapi/oss/*.h)  # TODO add a build flag for oss
  include_directories(AFTER SYSTEM ../../portaudio/src/os/unix/)
endif()

include_directories(AFTER SYSTEM  . ../../portaudio/include/ ../../portaudio/src/common/)

add_library(portaudio OBJECT ${PORTAUDIO_SRC} ${PORTAUDIO_OS_SRC})
