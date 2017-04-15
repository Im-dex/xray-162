cmake_minimum_required(VERSION 3.8)

project(xrCompress)

file(GLOB MAIN_SRC *.h *.cpp)
file(GLOB LZO_INC lzo/*.h)
file(GLOB LZO_SRC lzo/*.c)

source_group("Main" FILES ${MAIN_SRC})
source_group("LZO\\Include" FILES ${LZO_INC})
source_group("LZO\\Sources" FILES ${LZO_SRC})

add_definitions(-D_CONSOLE -D_SECURE_SCL=0)

add_compile_options("/Yustdafx.h" /fp:fast)
set_source_files_properties(stdafx.cpp PROPERTIES COMPILE_FLAGS /Yc)

foreach(src_file ${LZO_SRC})
    set_source_files_properties(${src_file} PROPERTIES COMPILE_FLAGS /Y-)
endforeach()

add_executable(xrCompress ${MAIN_SRC} ${LZO_INC} ${LZO_SRC})
set_target_properties(xrCompress PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
target_link_libraries(xrCompress xrCore winmm)