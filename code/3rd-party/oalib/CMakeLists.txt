cmake_minimum_required(VERSION 3.8)

project(oalib)

file(GLOB HEADERS include/*.h)
file(GLOB SRC src/*.c)

include_directories(include)

source_group("include" FILES ${HEADERS})
source_group("src" FILES ${SRC})

add_library(oalib STATIC ${HEADERS} ${SRC})
target_include_directories(oalib PUBLIC include)