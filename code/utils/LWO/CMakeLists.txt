cmake_minimum_required(VERSION 3.8)

project(LWO)

file(GLOB SRC *.h *.c *.cpp)

source_group("sources" FILES ${SRC})

add_definitions(-DLWO_EXPORTS -D_CRT_SECURE_NO_WARNINGS)

add_library(LWO SHARED ${SRC})
target_link_libraries(LWO odbc32 odbccp32)