cmake_minimum_required(VERSION 3.8)

project(ETools)

set(KERNEL CreateDX.cpp
           ETools.cpp
           ETools_cm.cpp
           Intersect.cpp
           StdAfx.cpp
           xrXRC.cpp
           D3DX_Wrapper.h
           ETools.h
           StdAfx.h
           xrXRC.h)

set(VIPM object.cpp
         object_sliding.cpp
         PropSlimTools.cpp
         ArbitraryList.h
         BinaryHeap.h
         DLink.h
         mesh.h
         object.h
         object_sliding.h
         PropSlimTools.h
         quad.h)

set(OGG_ENCODER audio.cpp
                encode.cpp
                ogg_enc.cpp
                platform.cpp
                resample.cpp
                audio.h
                encode.h
                platform.h
                resample.h)

source_group("Kernel" FILES ${KERNEL})
source_group("VIPM" FILES ${VIPM})
source_group("OGG encoder" FILES ${OGG_ENCODER})

add_definitions(-DETOOLS_EXPORTS -D_SECURE_SCL=0)

include_directories(${DXSDK_INCLUDE_DIR})
link_directories(${DXSDK_LIB_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

add_compile_options("/Yustdafx.h" /fp:fast /GR)
set_source_files_properties(stdafx.cpp PROPERTIES COMPILE_FLAGS /Yc)

add_library(ETools SHARED ${KERNEL}
                          ${VIPM}
                          ${OGG_ENCODER})
target_link_libraries(ETools xrCore xrQSlim xrCDB libogg libvorbis libvorbisfile dxerr2015 d3dx9 ColorPicker)