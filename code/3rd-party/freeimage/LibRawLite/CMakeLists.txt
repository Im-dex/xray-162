cmake_minimum_required(VERSION 3.8)

project(libraw)

set(HEADER_FILES_INTERNAL internal/defines.h
                          internal/libraw_internal_funcs.h
                          internal/var_defines.h)

set(SOURCE_FILES_LIBRAW src/libraw_c_api.cpp
                        src/libraw_cxx.cpp
                        src/libraw_datastream.cpp)

set(SOURCE_FILES_INTERNAL internal/dcraw_common.cpp
                          internal/dcraw_fileio.cpp
                          internal/demosaic_packs.cpp)

set(HEADER_FILES_LIBRAW libraw/libraw.h
                        libraw/libraw_alloc.h
                        libraw/libraw_const.h
                        libraw/libraw_datastream.h
                        libraw/libraw_internal.h
                        libraw/libraw_types.h
                        libraw/libraw_version.h)

source_group("Header Files\\internal" FILES ${HEADER_FILES_INTERNAL})
source_group("Source Files\\libraw" FILES ${SOURCE_FILES_LIBRAW})
source_group("Source Files\\internal" FILES ${SOURCE_FILES_INTERNAL})
source_group("Header Files\\libraw" FILES ${HEADER_FILES_LIBRAW})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_definitions(-D_CRT_SECURE_NO_WARNINGS -DLIBRAW_NODLL)

add_library(libraw STATIC ${HEADER_FILES_INTERNAL}
                          ${SOURCE_FILES_LIBRAW}
                          ${SOURCE_FILES_INTERNAL}
                          ${HEADER_FILES_LIBRAW})