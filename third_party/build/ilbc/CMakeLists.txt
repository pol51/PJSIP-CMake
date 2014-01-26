file(GLOB_RECURSE ILBC_SRC ../../ilbc/*.h config.h)
set(ILBC_SRC ${ILBC_SRC}
  ../../ilbc/anaFilter.c
  ../../ilbc/constants.c
  ../../ilbc/createCB.c
  ../../ilbc/doCPLC.c
  ../../ilbc/enhancer.c
  ../../ilbc/filter.c
  ../../ilbc/FrameClassify.c
  ../../ilbc/gainquant.c
  ../../ilbc/getCBvec.c
  ../../ilbc/helpfun.c
  ../../ilbc/hpInput.c
  ../../ilbc/hpOutput.c
  ../../ilbc/iCBConstruct.c
  ../../ilbc/iCBSearch.c
  ../../ilbc/iLBC_decode.c
  ../../ilbc/iLBC_encode.c
  ../../ilbc/LPCdecode.c
  ../../ilbc/LPCencode.c
  ../../ilbc/lsf.c
  ../../ilbc/packing.c
  ../../ilbc/StateConstructW.c
  ../../ilbc/StateSearchW.c
  ../../ilbc/syntFilter.c)

include_directories(AFTER SYSTEM  . ../../ilbc/)
add_library(ilbc OBJECT ${ILBC_SRC})
