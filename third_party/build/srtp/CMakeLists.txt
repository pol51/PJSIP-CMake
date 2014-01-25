file(GLOB_RECURSE SRTP_SRC
  ../../srtp/srtp/*.c
  ../../srtp/tables/*.c
  ../../srtp/pjlib/*.c
  ../../srtp/crypto/ae_xfm/*.c
  ../../srtp/crypto/cipher/*.c
  ../../srtp/crypto/hash/*.c
  ../../srtp/crypto/kernel/alloc.c
  ../../srtp/crypto/kernel/crypto_kernel.c
  ../../srtp/crypto/kernel/key.c
  ../../srtp/crypto/math/gf2_8.c
  ../../srtp/crypto/math/math.c
  ../../srtp/crypto/math/stat.c
  ../../srtp/crypto/replay/*.c
  ../../srtp/crypto/rng/ctr_prng.c
  ../../srtp/crypto/rng/prng.c
  ../../srtp/crypto/rng/rand_source.c
)

file(GLOB_RECURSE SRTP_INC
  ../../srtp/include/*.h config.h)

include_directories(AFTER SYSTEM  . ../../srtp/include/ ../../srtp/crypto/include/ ../../srtp)
add_definitions(-DHAVE_CONFIG_H)

add_library(srtp OBJECT ${SRTP_SRC} ${SRTP_INC})
