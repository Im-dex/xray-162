cmake_minimum_required(VERSION 3.8)

project(minizip)

file(GLOB HEADERS *.h)
file(GLOB SRC *.c)
list(REMOVE_ITEM SRC "${CMAKE_CURRENT_SOURCE_DIR}/minizip.c")
list(REMOVE_ITEM SRC "${CMAKE_CURRENT_SOURCE_DIR}/miniunz.c")

source_group("include" FILES ${HEADERS})
source_group("src" FILES ${SRC})

add_definitions(-D_CRT_SECURE_NO_WARNINGS)

add_library(minizip STATIC ${HEADERS} ${SRC})
add_dependencies(minizip zlib)