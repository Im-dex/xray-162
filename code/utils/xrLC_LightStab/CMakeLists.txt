cmake_minimum_required(VERSION 3.8)

project(xrLC_LightStab)

file(GLOB SRC *.h *.cpp)
source_group("" FILES ${SRC})

include_directories(../xrQSlim/src)

add_definitions(-DXRLC_LIGHT_STAB_EXPORTS)
add_compile_options(/fp:fast)

add_library(xrLC_LightStab SHARED ${SRC})
target_link_libraries(xrLC_LightStab xrLC_Light)