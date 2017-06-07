cmake_minimum_required(VERSION 3.8)

project(xrAPI)

file(GLOB HEADERS *.h)
file(GLOB SRC *.cpp)

source_group("headers" FILES ${HEADERS})
source_group("src" FILES ${SRC})

add_definitions(-DXRAPI_EXPORTS)

add_compile_options("/Yustdafx.h" /fp:fast)
set_source_files_properties(stdafx.cpp PROPERTIES COMPILE_FLAGS /Yc)

add_library(xrAPI SHARED ${HEADERS} ${SRC})