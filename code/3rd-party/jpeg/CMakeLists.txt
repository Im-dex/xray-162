cmake_minimum_required(VERSION 3.8)

project(jpeg)

file(GLOB HEADERS *.h)
file(GLOB SRC *.c)

source_group("include" FILES ${HEADERS})
source_group("src" FILES ${SRC})

add_compile_options(/fp:fast /wd4127 /wd4100 /wd4244)

add_library(jpeg STATIC ${HEADERS} ${SRC})