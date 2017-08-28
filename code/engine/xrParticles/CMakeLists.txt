cmake_minimum_required(VERSION 3.8)

project(xrParticles)

set(KERNEL psystem.h
           stdafx.h
           stdafx.cpp)

set(PAPI noise.h
         particle_actions.h
         particle_actions_collection.h
         particle_core.h
         particle_effect.h
         particle_manager.h
         noise.cpp
         particle_actions.cpp
         particle_actions_collection.cpp
         particle_actions_collection_io.cpp
         particle_core.cpp
         particle_effect.cpp
         particle_manager.cpp)

source_group("Kernel" FILES ${KERNEL})
source_group("PAPI" FILES ${PAPI})

add_definitions(-DXR_PARTICLES_EXPORTS -D_SECURE_SCL=0)

add_compile_options(/fp:fast /GR "/Yustdafx.h")
set_source_files_properties(stdafx.cpp PROPERTIES COMPILE_FLAGS /Yc)

add_library(xrParticles SHARED ${KERNEL} ${PAPI})
target_include_directories(xrParticles PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(xrParticles xrCore xrCPU_Pipe)