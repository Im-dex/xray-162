cmake_minimum_required(VERSION 3.8)

project(libtiff4)

set(HEADER_FILES t4.h
                 tif_config.h
                 tif_dir.h
                 tif_fax3.h
                 tif_predict.h
                 tiff.h
                 tiffconf.h
                 tiffio.h
                 tiffiop.h
                 tiffvers.h
                 uvcode.h)

set(SOURCE_FILES tif_aux.c
                 tif_close.c
                 tif_codec.c
                 tif_color.c
                 tif_compress.c
                 tif_dir.c
                 tif_dirinfo.c
                 tif_dirread.c
                 tif_dirwrite.c
                 tif_dumpmode.c
                 tif_error.c
                 tif_extension.c
                 tif_fax3.c
                 tif_fax3sm.c
                 tif_flush.c
                 tif_getimage.c
                 tif_jpeg.c
                 tif_luv.c
                 tif_lzma.c
                 tif_lzw.c
                 tif_next.c
                 tif_ojpeg.c
                 tif_open.c
                 tif_packbits.c
                 tif_pixarlog.c
                 tif_predict.c
                 tif_print.c
                 tif_read.c
                 tif_strip.c
                 tif_swab.c
                 tif_thunder.c
                 tif_tile.c
                 tif_version.c
                 tif_warning.c
                 tif_write.c
                 tif_zip.c)

source_group("Header Files" FILES ${HEADER_FILES})
source_group("Source Files" FILES ${SOURCE_FILES})

add_definitions(-D_CRT_SECURE_NO_DEPRECATE)

add_library(libtiff4 STATIC ${HEADER_FILES}
                            ${SOURCE_FILES})