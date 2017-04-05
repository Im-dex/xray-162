cmake_minimum_required(VERSION 3.8)

project(bugtrap)

file(GLOB HEADERS *.h)
file(GLOB SRC *.cpp)
file(GLOB RES *.rc)

source_group("headers" FILES ${HEADERS})
source_group("src" FILES ${SRC})
source_group("resources" FILES ${RES})

add_definitions(-D_NEW_ -DBUGTRAP_EXPORTS -D_WINSOCK_DEPRECATED_NO_WARNINGS)

add_compile_options("/Yustdafx.h")
set_source_files_properties(StdAfx.cpp PROPERTIES COMPILE_FLAGS /Yc)

add_library(bugtrap SHARED ${HEADERS} ${SRC} ${RES})
target_link_libraries(bugtrap zlib minizip ws2_32 version shlwapi wininet comctl32)