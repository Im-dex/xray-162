cmake_minimum_required(VERSION 3.8)

project(DPlay)

file(GLOB HEADERS *.h)

add_library(DPlay INTERFACE)
target_sources(DPlay INTERFACE ${HEADERS})

# trick to show the project in IDE
add_custom_target(DPlay-src SOURCES ${HEADERS})