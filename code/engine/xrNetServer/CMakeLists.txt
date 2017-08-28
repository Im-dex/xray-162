cmake_minimum_required(VERSION 3.8)

project(xrNetServer)

file(GLOB SRC *.h *.cpp)

link_directories(${DXSDK_LIB_DIR})
add_definitions(-DXR_NETSERVER_EXPORTS -D_SECURE_SCL=0)

add_compile_options(/fp:fast /GR "/Yustdafx.h")
set_source_files_properties(stdafx.cpp PROPERTIES COMPILE_FLAGS /Yc)

add_library(xrNetServer SHARED ${SRC})
target_include_directories(xrNetServer PRIVATE ${DXSDK_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(xrNetServer dxguid ws2_32 xrCore dxerr2015)