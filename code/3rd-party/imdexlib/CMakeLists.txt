cmake_minimum_required(VERSION 3.8)

project(imdexlib)

file(GLOB HEADERS *.hpp)

add_library(imdexlib INTERFACE)
target_sources(imdexlib INTERFACE ${HEADERS})

# trick to show the project in IDE
add_custom_target(imdexlib-src SOURCES ${HEADERS})