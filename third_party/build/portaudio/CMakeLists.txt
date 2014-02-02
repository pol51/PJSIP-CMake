file(GLOB_RECURSE portaudio_src
  ../../portaudio/src/common/*.c ../../portaudio/src/common/*.h
  ../../portaudio/include/portaudio.h)

if(TARGET_LINUX)
  add_definitions(-DHAVE_SYS_SOUNDCARD_H=1 -DPA_USE_ALSA=1)

  file(GLOB_RECURSE portaudio_os_src
    ../../portaudio/src/os/unix/*.c ../../portaudio/src/os/unix/*.h
    ../../portaudio/include/pa_linux_alsa.h ../../portaudio/src/hostapi/alsa/*.c ../../portaudio/src/hostapi/alsa/*.h) # TODO add a build flag for alsa
  include_directories(AFTER SYSTEM ../../portaudio/src/os/unix/)
endif()

if(TARGET_MACOSX)
  add_definitions(-DPA_USE_COREAUDIO=1)

  file(GLOB_RECURSE portaudio_os_src
    ../../portaudio/src/os/unix/*.c ../../portaudio/src/os/unix/*.h
    ../../portaudio/include/pa_mac_core.h ../../portaudio/src/hostapi/coreaudio/*.c)
  include_directories(AFTER SYSTEM ../../portaudio/src/os/unix/)
endif()

include_directories(AFTER SYSTEM  . ../../portaudio/include/ ../../portaudio/src/common/)

add_library(portaudio OBJECT ${portaudio_src} ${portaudio_os_src})
