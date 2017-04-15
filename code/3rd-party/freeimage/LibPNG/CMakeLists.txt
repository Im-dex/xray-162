cmake_minimum_required(VERSION 3.8)

project(libpng)

set(HEADER_FILES png.h
                 pngconf.h
                 pngdebug.h
                 pnginfo.h
                 pnglibconf.h
                 pngpriv.h
                 pngstruct.h)

set(SOURCE_FILES png.c
                 pngerror.c
                 pngget.c
                 pngmem.c
                 pngpread.c
                 pngread.c
                 pngrio.c
                 pngrtran.c
                 pngrutil.c
                 pngset.c
                 pngtrans.c
                 pngwio.c
                 pngwrite.c
                 pngwtran.c
                 pngwutil.c)

source_group("Header Files" FILES ${HEADER_FILES})
source_group("Source Files" FILES ${SOURCE_FILES})

include_directories(../../zlib)

add_definitions(-D_CRT_SECURE_NO_DEPRECATE)

add_library(libpng STATIC ${HEADER_FILES}
                          ${SOURCE_FILES})