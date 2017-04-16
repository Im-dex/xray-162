cmake_minimum_required(VERSION 3.8)

project(xrDXT)

set(NORMALMAP Image_DXTC.h
              NV_Common.h
              NVI_Convolution.h
              NVI_Image.h
              tga.h
              Image_DXTC.cpp
              NormalMapGen.cpp
              NVI_Convolution.cpp
              NVI_Image.cpp
              tga.cpp)

set(SHARED_SRC ETextureParams.h
               ETextureParams.cpp)

set(ROOT_SPECIAL_CONV dds.h
                      StdAfx.h
                      StdAfx.cpp
                      ReadMe.txt)

set(CONVERT dxtlib.h
            DXT.cpp)

file(GLOB DDS dds/*.h)

source_group("NormalMap" FILES ${NORMALMAP})
source_group("Shared" FILES ${SHARED_SRC})
source_group("" FILES ${ROOT_SPECIAL_CONV})
source_group("Convert" FILES ${CONVERT})
source_group("dds" FILES ${DDS})

add_definitions(-D_SECURE_SCL=0)

add_compile_options(/fp:fast "/Yustdafx.h")
set_source_files_properties(stdafx.cpp PROPERTIES COMPILE_FLAGS /Yc)

add_library(xrDXT SHARED ${NORMALMAP}
                         ${SHARED_SRC}
                         ${ROOT_SPECIAL_CONV}
                         ${CONVERT}
                         ${DDS})
target_link_libraries(xrDXT xrCore)

add_custom_command(TARGET xrDXT POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_CURRENT_SOURCE_DIR}/wrap/x86/nvdxtwrap.dll" $<TARGET_FILE_DIR:xrDXT>
)