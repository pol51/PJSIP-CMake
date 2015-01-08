set(BUILD_OBJECT_LIBRARY_ONLY ON)
include_directories(BEFORE SYSTEM ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_BINARY_DIR}/openssl/crypto/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../openssl)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../openssl ${CMAKE_CURRENT_BINARY_DIR}/openssl)

