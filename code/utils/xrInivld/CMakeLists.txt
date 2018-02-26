cmake_minimum_required(VERSION 3.8)

project(xrInivld)

file(GLOB SRC *.h *.cpp)

add_executable(xrInivld ${SRC})
target_link_libraries(xrInivld PRIVATE xrCore)

set_target_properties(xrInivld PROPERTIES FOLDER utils)