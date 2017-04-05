cmake_minimum_required(VERSION 3.8)

project(libvorbisfile)

include_directories(../libogg/include ../libvorbis/include ../libvorbis/lib)

add_definitions(-DLIBVORBISFILE_EXPORTS)

add_library(libvorbisfile STATIC vorbisfile.c ../libvorbis/include/vorbis/vorbisfile.h)
target_link_libraries(libvorbisfile libvorbis)