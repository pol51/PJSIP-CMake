file(GLOB_RECURSE G7221_SRC ../../g7221/*.c ../../g7221/*.h)

include_directories(AFTER SYSTEM  . ../../ ../../g7221/ ../../g7221/common)

add_library(g7221 OBJECT ${G7221_SRC})
