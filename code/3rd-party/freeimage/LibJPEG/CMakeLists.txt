cmake_minimum_required(VERSION 3.8)

project(libjpeg)

set(HEADER_FILES jconfig.h
                 jdct.h
                 jerror.h
                 jinclude.h
                 jmemsys.h
                 jmorecfg.h
                 jpegint.h
                 jpeglib.h
                 jversion.h
                 transupp.h)

set(SOURCE_FILES jaricom.c
                 jcapimin.c
                 jcapistd.c
                 jcarith.c
                 jccoefct.c
                 jccolor.c
                 jcdctmgr.c
                 jchuff.c
                 jcinit.c
                 jcmainct.c
                 jcmarker.c
                 jcmaster.c
                 jcomapi.c
                 jcparam.c
                 jcprepct.c
                 jcsample.c
                 jctrans.c
                 jdapimin.c
                 jdapistd.c
                 jdarith.c
                 jdatadst.c
                 jdatasrc.c
                 jdcoefct.c
                 jdcolor.c
                 jddctmgr.c
                 jdhuff.c
                 jdinput.c
                 jdmainct.c
                 jdmarker.c
                 jdmaster.c
                 jdmerge.c
                 jdpostct.c
                 jdsample.c
                 jdtrans.c
                 jerror.c
                 jfdctflt.c
                 jfdctfst.c
                 jfdctint.c
                 jidctflt.c
                 jidctfst.c
                 jidctint.c
                 jmemmgr.c
                 jmemnobs.c
                 jquant1.c
                 jquant2.c
                 jutils.c
                 transupp.c)

source_group("include" FILES ${HEADER_FILES})
source_group("src" FILES ${SOURCE_FILES})

add_definitions(-D_CRT_SECURE_NO_DEPRECATE)

add_library(libjpeg STATIC ${HEADER_FILES} ${SOURCE_FILES})