cmake_minimum_required(VERSION 3.8)

project(bugtrap)

file(GLOB HEADERS *.h)
file(GLOB SRC *.cpp)
file(GLOB RES *.rc)

source_group("headers" FILES ${HEADERS})
source_group("src" FILES ${SRC})
source_group("resources" FILES ${RES})

add_definitions(-D_USRDLL -DBUGTRAP_EXPORTS)

add_compile_options("/Yustdafx.h" /GR-)
set_source_files_properties(stdafx.cpp PROPERTIES COMPILE_FLAGS /Yc)

add_library(bugtrap SHARED ${HEADERS} ${SRC} ${RES})
target_link_libraries(bugtrap PRIVATE zlib minizip ws2_32 comctl32 shlwapi version wininet)
SET_TARGET_PROPERTIES(bugtrap PROPERTIES LINK_FLAGS "nothrownew.obj")