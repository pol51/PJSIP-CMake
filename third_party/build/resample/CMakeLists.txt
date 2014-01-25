set(RESAMPLE_SRC
  ../../resample/src/largefilter.h
  ../../resample/src/resample.h
  ../../resample/src/resamplesubs.c
  ../../resample/include/resamplesubs.h
  ../../resample/src/smallfilter.h
  ../../resample/src/stddefs.h
  config.h)

include_directories(BEFORE SYSTEM  . ../../resample/include)

add_library(resample OBJECT ${RESAMPLE_SRC})
