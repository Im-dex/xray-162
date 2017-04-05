cmake_minimum_required(VERSION 3.8)

project(xrNetServer)

file(GLOB SRC *.h *.cpp)

include_directories($ENV{DXSDK_DIR}/Include)
link_directories($ENV{DXSDK_DIR}/x86)
add_definitions(-DXR_NETSERVER_EXPORTS -D_SECURE_SCL=0)

add_compile_options(/fp:fast /GR "/Yustdafx.h")
set_source_files_properties(stdafx.cpp PROPERTIES COMPILE_FLAGS /Yc)

add_library(xrNetServer SHARED ${SRC})
target_link_libraries(xrNetServer dxguid ws2_32 xrCore dxerr2015)