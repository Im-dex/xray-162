cmake_minimum_required(VERSION 3.8)

project(xrCDB)

set(ENGINE_SRC ISpatial.h ISpatial.cpp ISpatial_q_box.cpp ISpatial_q_frustum.cpp
               ISpatial_q_ray.cpp ISpatial_verify.cpp xr_area.h xr_area_query.cpp
               xr_area.cpp xr_area_raypick.cpp xr_collide_defs.h xrXRC.cpp xrXRC.h)

set(KERNEL_SRC Frustum.cpp Frustum.h stdafx.h stdafx.cpp xrCDB.h xrCDB.cpp xrCDB_box.cpp
               xrCDB_Collector.cpp xrCDB_frustum.cpp xrCDB_ray.cpp)
              
file(GLOB OPCODE_SRC_OPC OPC_*.h OPC_*.cpp)
set(OPCODE_SRC ${OPCODE_SRC_OPC} Opcode.h Opcode.cpp)

source_group("engine" FILES ${ENGINE_SRC})
source_group("Kernel" FILES ${KERNEL_SRC})
source_group("Opcode" FILES ${OPCODE_SRC})

add_definitions(-DXRCDB_EXPORTS)

add_compile_options("/Yustdafx.h" /fp:fast /GR)
set_source_files_properties(stdafx.cpp PROPERTIES COMPILE_FLAGS /Yc)

add_library(xrCDB SHARED ${ENGINE_SRC} ${KERNEL_SRC} ${OPCODE_SRC})
target_link_libraries(xrCDB xrAPI xrCore winmm)