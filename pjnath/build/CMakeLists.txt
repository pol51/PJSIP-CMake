file(GLOB PJNATH_SRC ../src/pjnath/*.c ../include/pjnath/*.h)

add_library(pjnath ${PJNATH_SRC})
target_link_libraries(pjnath pjlib pjlib-util)
