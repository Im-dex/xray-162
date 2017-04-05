cmake_minimum_required(VERSION 3.8)

project(libogg)

file(GLOB HEADERS include/ogg/*.h)
file(GLOB SRC src/*.c)

source_group("include" FILES ${HEADERS})
source_group("src" FILES ${SRC})

include_directories(include)

add_definitions(-DLIBOGG_EXPORTS)

add_compile_options(/wd4244)

add_library(libogg STATIC ${HEADERS} ${SRC})
target_include_directories(libogg PUBLIC include)