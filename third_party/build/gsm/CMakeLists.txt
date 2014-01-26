file(GLOB_RECURSE GSM_SRC  ../../gsm/inc/*.h config.h)
set(GSM_SRC ${GSM_SRC}
  ../../gsm/src/add.c
  ../../gsm/src/code.c
  ../../gsm/src/decode.c
  ../../gsm/src/debug.c
  ../../gsm/src/gsm_create.c
  ../../gsm/src/gsm_decode.c
  ../../gsm/src/gsm_destroy.c
  ../../gsm/src/gsm_encode.c
  ../../gsm/src/gsm_explode.c
  ../../gsm/src/gsm_implode.c
  ../../gsm/src/gsm_option.c
  ../../gsm/src/gsm_print.c
  ../../gsm/src/long_term.c
  ../../gsm/src/lpc.c
  ../../gsm/src/preprocess.c
  ../../gsm/src/rpe.c
  ../../gsm/src/short_term.c
  ../../gsm/src/table.c
  ../../gsm/src/toast_alaw.c
  ../../gsm/src/toast_audio.c
  ../../gsm/src/toast_lin.c
  ../../gsm/src/toast_ulaw.c)

include_directories(AFTER SYSTEM  . ../../gsm/inc/)

add_library(gsm OBJECT ${GSM_SRC})
