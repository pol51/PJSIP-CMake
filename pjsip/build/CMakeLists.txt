file(GLOB PJSIP_SRC ../src/pjsip/*.c ../include/pjsip/*.h)
file(GLOB PJSIP-SIMPLE_SRC ../src/pjsip-simple/*.c ../include/pjsip-simple/*.h)
file(GLOB PJSIP-UA_SRC ../src/pjsip-ua/*.c ../include/pjsip-ua/*.h)
file(GLOB PJSUA-LIB_SRC ../src/pjsua-lib/*.c ../include/pjsua-lib/*.h)

ADD_LIBRARY(pjsip OBJECT ${PJSIP_SRC} ${PJSIP-SIMPLE_SRC} ${PJSIP-UA_SRC} ${PJSUA-LIB_SRC})
