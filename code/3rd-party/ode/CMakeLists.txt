cmake_minimum_required(VERSION 3.8)

project(ode)

file(GLOB HEADERS include/ode/*.h)
file(GLOB SRC ode/src/*.cpp ode/src/*.c ode/src/*.h)
file(GLOB CONTRIB contrib/msvc7/ode_default/*.h contrib/msvc7/ode_default/*.cpp)

source_group("include" FILES ${HEADERS})
source_group("src" FILES ${SRC} ${CONTRIB})

include_directories(include)

add_compile_options(/fp:fast /wd4100 /wd4505)
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /DEF:\"${CMAKE_CURRENT_SOURCE_DIR}/config/msvcdefs.def\"")

add_definitions(-DMSVC -DdSINGLE -D_SECURE_SCL=0)
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -DdNODEBUG")

add_library(ode SHARED ${HEADERS} ${SRC} ${CONTRIB})