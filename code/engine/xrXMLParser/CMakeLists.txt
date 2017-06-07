cmake_minimum_required(VERSION 3.8)

project(xrXMLParser)

file(GLOB HEADERS *.h)
file(GLOB SRC *.cpp)

source_group("headers" FILES ${HEADERS})
source_group("src" FILES ${SRC})

add_definitions(-DXRXMLPARSER_EXPORTS -D_SECURE_SCL=0)

add_compile_options(/fp:fast "/Yustdafx.h" /GR)
set_source_files_properties(stdafx.cpp PROPERTIES COMPILE_FLAGS /Yc)

add_library(xrXMLParser SHARED ${HEADERS} ${SRC})
target_link_libraries(xrXMLParser xrCore)