cmake_minimum_required(VERSION 3.8)

project(libjxr)

set(HEADER_FILES_IMAGE_SYS image/sys/ansi.h
                           image/sys/common.h
                           image/sys/perfTimer.h
                           image/sys/strcodec.h
                           image/sys/strTransform.h
                           image/sys/windowsmediaphoto.h
                           image/sys/xplatform_image.h)

set(HEADER_FILES_IMAGE_DECODE image/decode/decode.h)

set(SOURCE_FILES_IMAGE_SYS image/sys/adapthuff.c
                           image/sys/image.c
                           image/sys/strcodec.c
                           image/sys/strPredQuant.c
                           image/sys/strTransform.c)

set(SOURCE_FILES_IMAGE_ENCODE image/encode/encode.c
                              image/encode/segenc.c
                              image/encode/strenc.c
                              image/encode/strenc_x86.c
                              image/encode/strFwdTransform.c
                              image/encode/strPredQuantEnc.c)

set(HEADER_FILES_JXRGLUELIB jxrgluelib/JXRGlue.h
                            jxrgluelib/JXRMeta.h)

set(HEADER_FILES_IMAGE_X86 image/x86/x86.h)

set(HEADER_FILES_COMMON common/include/guiddef.h
                        common/include/wmsal.h
                        common/include/wmspecstring.h
                        common/include/wmspecstrings_adt.h
                        common/include/wmspecstrings_strict.h
                        common/include/wmspecstrings_undef.h)

set(HEADER_FILES_IMAGE_ENCODE image/encode/encode.h)

set(SOURCE_FILES_IMAGE_DECODE image/decode/decode.c
                              image/decode/JXRTranscode.c
                              image/decode/postprocess.c
                              image/decode/segdec.c
                              image/decode/strdec.c
                              image/decode/strdec_x86.c
                              image/decode/strInvTransform.c
                              image/decode/strPredQuantDec.c)

set(SOURCE_FILES_JXRGLUELIB jxrgluelib/JXRGlue.c
                            jxrgluelib/JXRGlueJxr.c
                            jxrgluelib/JXRGluePFC.c
                            jxrgluelib/JXRMeta.c)

source_group("Header Files\\image\\sys" FILES ${HEADER_FILES_IMAGE_SYS})
source_group("Header Files\\image\\decode" FILES ${HEADER_FILES_IMAGE_DECODE})
source_group("Source Files\\image\\sys" FILES ${SOURCE_FILES_IMAGE_SYS})
source_group("Source Files\\image\\encode" FILES ${SOURCE_FILES_IMAGE_ENCODE})
source_group("Header Files\\jxrgluelib" FILES ${HEADER_FILES_JXRGLUELIB})
source_group("Header Files\\image\\x86" FILES ${HEADER_FILES_IMAGE_X86})
source_group("Header Files\\common" FILES ${HEADER_FILES_COMMON})
source_group("Header Files\\image\\encode" FILES ${HEADER_FILES_IMAGE_ENCODE})
source_group("Source Files\\image\\decode" FILES ${SOURCE_FILES_IMAGE_DECODE})
source_group("Source Files\\jxrgluelib" FILES ${SOURCE_FILES_JXRGLUELIB})

include_directories(image/sys jxrgluelib)

add_definitions(-DDISABLE_PERF_MEASUREMENT)

add_library(libjxr STATIC ${HEADER_FILES_IMAGE_DECODE}
                          ${SOURCE_FILES_IMAGE_ENCODE}
                          ${HEADER_FILES_COMMON}
                          ${HEADER_FILES_IMAGE_X86}
                          ${HEADER_FILES_JXRGLUELIB}
                          ${HEADER_FILES_IMAGE_ENCODE}
                          ${SOURCE_FILES_IMAGE_DECODE}
                          ${HEADER_FILES_IMAGE_SYS}
                          ${SOURCE_FILES_IMAGE_SYS}
                          ${SOURCE_FILES_JXRGLUELIB})