cmake_minimum_required(VERSION 3.8)

project(nvapi)

file(GLOB HEADERS *.h)

add_library(nvapi INTERFACE)
set_property(TARGET nvapi PROPERTY INTERFACE_LINK_LIBRARIES ${CMAKE_CURRENT_SOURCE_DIR}/nvapi.lib)
target_include_directories(nvapi INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# trick to show the project in IDE
add_custom_target(nvapi-src SOURCES ${HEADERS})