cmake_minimum_required(VERSION 3.8)

project(ati)

add_library(ati INTERFACE)
target_sources(ati INTERFACE atimgpud.h)

# trick to show the project in IDE
add_custom_target(ati-src SOURCES atimgpud.h)


плпвдацЛПАЛППЛорап
