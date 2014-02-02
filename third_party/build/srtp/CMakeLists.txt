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
  ../../srtp/crypto/math/datatypes.c
  ../../srtp/crypto/math/gf2_8.c
  ../../srtp/crypto/math/math.c
  ../../srtp/crypto/math/stat.c
  ../../srtp/crypto/replay/*.c
  ../../srtp/crypto/rng/ctr_prng.c
  ../../srtp/crypto/rng/prng.c
  ../../srtp/crypto/rng/rand_source.c
)

file(GLOB_RECURSE SRTP_OPENSSL_SRC
  ../../srtp/crypto/hash/hmac_ossl.c
)

file(GLOB_RECURSE SRTP_NOOPENSSL_SRC
  ../../srtp/crypto/hash/sha1.c
)

if(WITH_SSL)
  add_definitions(-DOPENSSL)
  list(REMOVE_ITEM SRTP_SRC ${SRTP_NOOPENSSL_SRC})
else()
  list(REMOVE_ITEM SRTP_SRC ${SRTP_OPENSSL_SRC})
endif()

file(GLOB_RECURSE SRTP_INC
  ../../srtp/include/*.h config.h)

include_directories(AFTER SYSTEM  . ../../srtp/include/ ../../srtp/crypto/include/ ../../srtp)
if(WITH_BUILTIN_OPENSSL)
  include_directories(AFTER SYSTEM  ../..)
endif()
add_definitions(-DHAVE_CONFIG_H)

add_library(srtp OBJECT ${SRTP_SRC} ${SRTP_INC})
