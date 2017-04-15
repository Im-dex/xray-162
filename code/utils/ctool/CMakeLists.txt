cmake_minimum_required(VERSION 3.8)

project(ctool)

file(GLOB SRC ctool.cpp)
file(GLOB PPMTRAIN_SRC PPMT_SA.hpp PPMTrain.cpp)

source_group("" FILES ${SRC})
source_group("PPMTrain" FILES ${PPMTRAIN_SRC})

add_definitions(-D_CONSOLE -D_CRT_SECURE_NO_WARNINGS)

add_executable(ctool ${SRC} ${PPMTRAIN_SRC})
set_target_properties(ctool PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")