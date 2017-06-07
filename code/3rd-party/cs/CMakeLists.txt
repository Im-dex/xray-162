cmake_minimum_required(VERSION 3.8)

project(cs)

file(GLOB_RECURSE SRC *.h)

add_library(cs INTERFACE)
target_sources(ati INTERFACE ${SRC})

# trick to show the project in IDE
add_custom_target(cs-src SOURCES ${SRC})