cmake_minimum_required(VERSION 3.8)

project(eax)

add_library(eax INTERFACE)
target_sources(eax INTERFACE eax.h eaxac3.h)

# trick to show the project in IDE
add_custom_target(eax-src SOURCES eax.h eaxac3.h)