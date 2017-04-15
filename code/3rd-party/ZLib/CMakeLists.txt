cmake_minimum_required(VERSION 3.8)

project(zlib)

set(HEADER_FILES crc32.h
                 deflate.h
                 gzguts.h
                 inffast.h
                 inffixed.h
                 inflate.h
                 inftrees.h
                 trees.h
                 zconf.h
                 zlib.h
                 zutil.h)

set(SOURCE_FILES adler32.c
                 compress.c
                 crc32.c
                 deflate.c
                 gzclose.c
                 gzlib.c
                 gzread.c
                 gzwrite.c
                 infback.c
                 inffast.c
                 inflate.c
                 inftrees.c
                 trees.c
                 uncompr.c
                 zutil.c)

source_group("Header Files" FILES ${HEADER_FILES})
source_group("Source Files" FILES ${SOURCE_FILES})

add_definitions(-D_CRT_SECURE_NO_DEPRECATE -D_CRT_SECURE_NO_WARNINGS -D_SCL_SECURE_NO_WARNINGS)

add_library(zlib STATIC ${HEADER_FILES}
                        ${SOURCE_FILES})