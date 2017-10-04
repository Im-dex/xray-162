cmake_minimum_required(VERSION 3.8)

project(boost)

add_library(boost INTERFACE)
target_include_directories(boost INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})