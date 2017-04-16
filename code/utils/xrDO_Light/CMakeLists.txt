cmake_minimum_required(VERSION 3.8)

project(xrDO_Light)

set(KERNEL _d3d_extensions.h
           defines.h
           StdAfx.h
           StdAfx.cpp
           xrDO_Light.cpp)

set(KERNEL_LOG cl_log.h
               cl_log.cpp)

set(KERNEL_GENERIC std_classes.h)

set(KERNEL_RESOURCES resource.h
                     resource.rc)

source_group("Kernel" FILES ${KERNEL})
source_group("Kernel\\Log" FILES ${KERNEL_LOG})
source_group("Kernel\\Generic" FILES ${KERNEL_GENERIC})
source_group("Kernel\\Resources" FILES ${KERNEL_RESOURCES})

include_directories(${DXSDK_INCLUDE_DIR})

add_definitions(-D_SECURE_SCL=0)

add_compile_options(/fp:fast /GR "/Yustdafx.h")
set_source_files_properties(stdafx.cpp PROPERTIES COMPILE_FLAGS /Yc)

add_executable(xrDO_Light ${KERNEL}
                          ${KERNEL_LOG}
                          ${KERNEL_GENERIC}
                          ${KERNEL_RESOURCES})
set_target_properties(xrDO_Light PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")
target_link_libraries(xrDO_Light xrCDB xrCore xrLC_Light comctl32 winmm)