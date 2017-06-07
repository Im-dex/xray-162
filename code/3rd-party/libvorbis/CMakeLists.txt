cmake_minimum_required(VERSION 3.8)

project(libvorbis)

file(GLOB HEADERS include/vorbis/*.h)
file(GLOB_RECURSE SRC lib/*.c lib/*.h)
list(REMOVE_ITEM SRC ${CMAKE_CURRENT_SOURCE_DIR}/lib/psytune.c)
list(REMOVE_ITEM SRC ${CMAKE_CURRENT_SOURCE_DIR}/lib/tone.c)

source_group("include" FILES ${HEADERS})
source_group("src" FILES ${SRC})

include_directories(include ../libogg/include)

add_definitions(-DLIBVORBIS_EXPORTS)

add_compile_options(/wd4244 /wd4100 /wd4267 /wd4189 /wd4305 /wd4127 /wd4706)

add_library(libvorbis STATIC ${HEADERS} ${SRC})
target_link_libraries(libvorbis libogg)
target_include_directories(libvorbis PUBLIC include)