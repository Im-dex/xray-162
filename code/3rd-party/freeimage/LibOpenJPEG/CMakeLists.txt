cmake_minimum_required(VERSION 3.8)

project(libopenjpeg)

set(HEADER_FILES bio.h
                 cio.h
                 dwt.h
                 event.h
                 function_list.h
                 image.h
                 indexbox_manager.h
                 invert.h
                 j2k.h
                 jp2.h
                 mct.h
                 mqc.h
                 openjpeg.h
                 opj_clock.h
                 opj_config.h
                 opj_config_private.h
                 opj_includes.h
                 opj_intmath.h
                 opj_inttypes.h
                 opj_malloc.h
                 opj_stdint.h
                 pi.h
                 raw.h
                 t1.h
                 t1_luts.h
                 t2.h
                 tcd.h
                 tgt.h)

set(SOURCE_FILES bio.c
                 cio.c
                 dwt.c
                 event.c
                 function_list.c
                 image.c
                 invert.c
                 j2k.c
                 jp2.c
                 mct.c
                 mqc.c
                 openjpeg.c
                 opj_clock.c
                 pi.c
                 raw.c
                 t1.c
                 t2.c
                 tcd.c
                 tgt.c)

source_group("Header Files" FILES ${HEADER_FILES})
source_group("Source Files" FILES ${SOURCE_FILES})

add_definitions(-DOPJ_STATIC -D_CRT_SECURE_NO_DEPRECATE)

add_library(libopenjpeg STATIC ${HEADER_FILES} ${SOURCE_FILES})