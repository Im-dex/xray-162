cmake_minimum_required(VERSION 3.8)

project(FreeImage)

set(HEADER_FILES Source/CacheFile.h
                 Source/DeprecationManager/DeprecationMgr.h
                 Source/Metadata/FIRational.h
                 Source/FreeImage.h
                 Source/FreeImageIO.h
                 Source/Metadata/FreeImageTag.h
                 Source/FreeImage/J2KHelper.h
                 Source/Plugin.h
                 Source/FreeImage/PSDParser.h
                 Source/Quantizers.h
                 Source/ToneMapping.h
                 Source/Utilities.h
                 Source/MapIntrospector.h)

set(SOURCE_FILES_METADATA Source/Metadata/Exif.cpp
                          Source/Metadata/FIRational.cpp
                          Source/Metadata/FreeImageTag.cpp
                          Source/Metadata/IPTC.cpp
                          Source/Metadata/TagConversion.cpp
                          Source/Metadata/TagLib.cpp
                          Source/Metadata/XTIFF.cpp)

set(SOURCE_FILES_CONVERSION Source/FreeImage/Conversion.cpp
                            Source/FreeImage/Conversion16_555.cpp
                            Source/FreeImage/Conversion16_565.cpp
                            Source/FreeImage/Conversion24.cpp
                            Source/FreeImage/Conversion32.cpp
                            Source/FreeImage/Conversion4.cpp
                            Source/FreeImage/Conversion8.cpp
                            Source/FreeImage/ConversionFloat.cpp
                            Source/FreeImage/ConversionRGB16.cpp
                            Source/FreeImage/ConversionRGBF.cpp
                            Source/FreeImage/ConversionType.cpp
                            Source/FreeImage/ConversionUINT16.cpp
                            Source/FreeImage/Halftoning.cpp
                            Source/FreeImage/tmoColorConvert.cpp
                            Source/FreeImage/tmoDrago03.cpp
                            Source/FreeImage/tmoFattal02.cpp
                            Source/FreeImage/tmoReinhard05.cpp
                            Source/FreeImage/ToneMapping.cpp
                            Source/FreeImage/ConversionRGBAF.cpp
                            Source/FreeImage/ConversionRGBA16.cpp)

set(SOURCE_FILES_PLUGINS Source/FreeImage/J2KHelper.cpp
                         Source/FreeImage/MNGHelper.cpp
                         Source/FreeImage/Plugin.cpp
                         Source/FreeImage/PluginBMP.cpp
                         Source/FreeImage/PluginCUT.cpp
                         Source/FreeImage/PluginDDS.cpp
                         Source/FreeImage/PluginEXR.cpp
                         Source/FreeImage/PluginG3.cpp
                         Source/FreeImage/PluginGIF.cpp
                         Source/FreeImage/PluginHDR.cpp
                         Source/FreeImage/PluginICO.cpp
                         Source/FreeImage/PluginIFF.cpp
                         Source/FreeImage/PluginJ2K.cpp
                         Source/FreeImage/PluginJNG.cpp
                         Source/FreeImage/PluginJP2.cpp
                         Source/FreeImage/PluginJPEG.cpp
                         Source/FreeImage/PluginJXR.cpp
                         Source/FreeImage/PluginKOALA.cpp
                         Source/FreeImage/PluginMNG.cpp
                         Source/FreeImage/PluginPCD.cpp
                         Source/FreeImage/PluginPCX.cpp
                         Source/FreeImage/PluginPFM.cpp
                         Source/FreeImage/PluginPICT.cpp
                         Source/FreeImage/PluginPNG.cpp
                         Source/FreeImage/PluginPNM.cpp
                         Source/FreeImage/PluginPSD.cpp
                         Source/FreeImage/PluginRAS.cpp
                         Source/FreeImage/PluginRAW.cpp
                         Source/FreeImage/PluginSGI.cpp
                         Source/FreeImage/PluginTARGA.cpp
                         Source/FreeImage/PluginTIFF.cpp
                         Source/FreeImage/PluginWBMP.cpp
                         Source/FreeImage/PluginWebP.cpp
                         Source/FreeImage/PluginXBM.cpp
                         Source/FreeImage/PluginXPM.cpp
                         Source/FreeImage/PSDParser.cpp
                         Source/FreeImage/TIFFLogLuv.cpp)

set(SOURCE_FILES_DEPRECATIONMGR Source/DeprecationManager/Deprecated.cpp
                                Source/DeprecationManager/DeprecationMgr.cpp)

set(TOOLKIT_FILES Source/FreeImageToolkit/Background.cpp
                  Source/FreeImageToolkit/BSplineRotate.cpp
                  Source/FreeImageToolkit/Channels.cpp
                  Source/FreeImageToolkit/ClassicRotate.cpp
                  Source/FreeImageToolkit/Colors.cpp
                  Source/FreeImageToolkit/CopyPaste.cpp
                  Source/FreeImageToolkit/Display.cpp
                  Source/FreeImageToolkit/Flip.cpp
                  Source/FreeImageToolkit/JPEGTransform.cpp
                  Source/FreeImageToolkit/MultigridPoissonSolver.cpp
                  Source/FreeImageToolkit/Rescale.cpp
                  Source/FreeImageToolkit/Resize.cpp
                  Source/FreeImageToolkit/Resize.h)

set(SOURCE_FILES_MULTIPAGING Source/FreeImage/CacheFile.cpp
                             Source/FreeImage/MultiPage.cpp
                             Source/FreeImage/ZLibInterface.cpp)

set(SOURCE_FILES_QUANTIZERS Source/FreeImage/NNQuantizer.cpp
                            Source/FreeImage/WuQuantizer.cpp
                            Source/FreeImage/LFPQuantizer.cpp)

set(SOURCE_FILES Source/FreeImage/BitmapAccess.cpp
                 Source/FreeImage/ColorLookup.cpp
                 Source/FreeImage/FreeImage.cpp
                 Source/FreeImage/FreeImageC.c
                 Source/FreeImage/FreeImageIO.cpp
                 Source/FreeImage/GetType.cpp
                 Source/FreeImage/MemoryIO.cpp
                 Source/FreeImage/PixelAccess.cpp
                 FreeImage.rc)

source_group("Header Files" FILES ${HEADER_FILES})
source_group("Source Files\\Metadata" FILES ${SOURCE_FILES_METADATA})
source_group("Source Files\\Conversion" FILES ${SOURCE_FILES_CONVERSION})
source_group("Source Files\\Plugins" FILES ${SOURCE_FILES_PLUGINS})
source_group("Source Files\\DeprecationMgr" FILES ${SOURCE_FILES_DEPRECATIONMGR})
source_group("Toolkit Files" FILES ${TOOLKIT_FILES})
source_group("Source Files\\MultiPaging" FILES ${SOURCE_FILES_MULTIPAGING})
source_group("Source Files\\Quantizers" FILES ${SOURCE_FILES_QUANTIZERS})
source_group("Source Files" FILES ${SOURCE_FILES})

include_directories(Source ../../zlib Source/DeprecationManager ../OpenEXR ../OpenEXR/Half ../OpenEXR/Iex
                    ../OpenEXR/IlmImf ../OpenEXR/Imath ../OpenEXR/IlmThread ../LibJXR/jxrgluelib
                    ../LibJXR/image/sys)

add_definitions(-D_USRDLL -DOPJ_STATIC -DFREEIMAGE_EXPORTS -D_CRT_SECURE_NO_DEPRECATE -DLIBRAW_NODLL)
add_compile_options(/Zp16)

add_library(FreeImage SHARED ${SOURCE_FILES_CONVERSION}
                             ${SOURCE_FILES_DEPRECATIONMGR}
                             ${TOOLKIT_FILES}
                             ${HEADER_FILES}
                             ${SOURCE_FILES_METADATA}
                             ${SOURCE_FILES_MULTIPAGING}
                             ${SOURCE_FILES_PLUGINS}
                             ${SOURCE_FILES}
                             ${SOURCE_FILES_QUANTIZERS})
target_include_directories(FreeImage PUBLIC Source)
target_link_libraries(FreeImage zlib libjpeg libjxr libopenjpeg libpng libraw libtiff4 libwebp openexr)