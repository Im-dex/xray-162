cmake_minimum_required(VERSION 3.8)

project(loki)

file(GLOB HEADERS *.h)

add_library(loki INTERFACE)
target_sources(loki INTERFACE ${HEADERS})

# trick to show the project in IDE
add_custom_target(loki-src SOURCES ${HEADERS})