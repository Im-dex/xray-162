cmake_minimum_required(VERSION 3.8)

project(zlib)

file(GLOB HEADERS *.h)
file(GLOB SRC *.c)
list(REMOVE_ITEM SRC "${CMAKE_CURRENT_SOURCE_DIR}/example.c")
list(REMOVE_ITEM SRC "${CMAKE_CURRENT_SOURCE_DIR}/minigzip.c")

source_group("include" FILES ${HEADERS})
source_group("src" FILES ${SRC})

add_definitions(-D_SECURE_SCL=0 -D_CRT_SECURE_NO_WARNINGS)

add_library(zlib STATIC ${HEADERS} ${SRC})