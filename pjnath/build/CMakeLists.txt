file(GLOB PJNATH_SRC ../src/pjnath/*.c ../include/pjnath/*.h)

add_library(pjnath OBJECT ${PJNATH_SRC})
