cmake_minimum_required(VERSION 3.8)

project(cximage)

file(GLOB HEADERS *.h)
file(GLOB SRC *.cpp)

source_group("include" FILES ${HEADERS})
source_group("src" FILES ${SRC})

add_definitions(-DCXIMAGE_BUILD -DJAS_WIN_MSVC_BUILD -D_CRT_SECURE_NO_WARNINGS
                -D_CRT_SECURE_NO_DEPRECATE)

add_compile_options(/fp:fast /wd4100)
                
add_library(cximage SHARED ${HEADERS} ${SRC} ${RES})
target_link_libraries(cximage jpeg xrCore)