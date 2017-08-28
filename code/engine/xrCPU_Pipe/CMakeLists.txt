cmake_minimum_required(VERSION 3.8)

project(xrCPU_Pipe)

set(KERNEL StdAfx.cpp
           xrCPU_Pipe.cpp)

set(HEADERS StdAfx.h
            xrCPU_Pipe.h)

set(RESOURCES resource.h
              xrCPU_Pipe.rc)

set(PLC PLC.cpp)

set(SKINNING xrSkin2W.cpp
             xrSkin2W_SSE.cpp
             xrSkin2W_thread.cpp)

set(TTAPI ttapi.cpp
          ttapi.h)

source_group("Kernel" FILES ${KERNEL})
source_group("Headers" FILES ${HEADERS})
source_group("Resources" FILES ${RESOURCES})
source_group("PLC" FILES ${PLC})
source_group("Skinning" FILES ${SKINNING})
source_group("TTAPI" FILES ${TTAPI})

add_definitions(-DXRCPU_PIPE_EXPORTS -D_SECURE_SCL=0)

add_compile_options(/fp:fast /GR "/Yustdafx.h")
set_source_files_properties(stdafx.cpp PROPERTIES COMPILE_FLAGS /Yc)

add_library(xrCPU_Pipe SHARED ${SKINNING}
                              ${RESOURCES}
                              ${HEADERS}
                              ${KERNEL}
                              ${TTAPI}
                              ${PLC})
target_include_directories(xrCPU_Pipe PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(xrCPU_Pipe xrCore)