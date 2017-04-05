cmake_minimum_required(VERSION 3.8)

project(crypto)

file(GLOB HEADERS *.h)
file(GLOB SRC *.cpp)
file(GLOB OPENSSL_HEADERS openssl/openssl/*.h)
file(GLOB OPENSSL_SRC openssl/src/*.c)

source_group("include" FILES ${HEADERS})
source_group("src" FILES ${SRC})
source_group("openssl\\include" FILES ${OPENSSL_HEADERS})
source_group("openssl\\src" FILES ${OPENSSL_SRC})

include_directories(openssl)

add_definitions(-DCRYPTO_BUILD -DCRYPTO_AS_SHARED_LIBRARY -D_CRT_SECURE_NO_WARNINGS)

add_compile_options(/fp:fast)

add_library(crypto SHARED ${HEADERS} ${SRC} ${OPENSSL_HEADERS} ${OPENSSL_SRC})
target_link_libraries(crypto xrCore)