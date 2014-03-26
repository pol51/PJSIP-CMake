file(GLOB_RECURSE SRTP_SRC
  ../../srtp/srtp/*.c
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
  ../../srtp/crypto/cipher/aes_gcm_ossl.c
  ../../srtp/crypto/cipher/aes_icm_ossl.c
  ../../srtp/crypto/hash/hmac_ossl.c
  ../../srtp/crypto/include/aes_gcm_ossl.h
  ../../srtp/crypto/include/aes_icm_ossl.h
  ../../srtp/crypto/rng/rand_source_ossl.c
)

file(GLOB_RECURSE SRTP_NOOPENSSL_SRC
  ../../srtp/crypto/hash/sha1.c
)

list(REMOVE_ITEM SRTP_SRC ${SRTP_OPENSSL_SRC})

file(GLOB_RECURSE SRTP_INC
  ../../srtp/include/*.h config.h)

include_directories(BEFORE SYSTEM  . ../../srtp/include/ ../../srtp/crypto/include/ ../../srtp)
add_definitions(-DHAVE_CONFIG_H)

add_library(srtp OBJECT ${SRTP_SRC} ${SRTP_INC})
