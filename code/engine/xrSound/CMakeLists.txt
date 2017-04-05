cmake_minimum_required(VERSION 3.8)

project(xrSound)

set(CACHE_SRC SoundRender_Cache.h SoundRender_Cache.cpp)
set(CORE_SRC SoundRender_Core.h SoundRender_Core.cpp SoundRender_Core_Processor.cpp
             SoundRender_Core_SourceManager.cpp SoundRender_Core_StartStop.cpp)
set(CORE_OPENAL_SRC OpenALDeviceList.h OpenALDeviceList.cpp SoundRender_CoreA.h SoundRender_CoreA.cpp)
set(EMITTER_SRC SoundRender_Emitter.h SoundRender_Emitter.cpp SoundRender_Emitter_FSM.cpp
                SoundRender_Emitter_StartStop.cpp SoundRender_Emitter_streamer.cpp)
set(ENV_SRC SoundRender_Environment.h SoundRender_Environment.cpp)
set(KERNEL_SRC cl_intersect.h guids.cpp Sound.h sound.cpp SoundRender.h stdafx.h stdafx.cpp)
set(SOURCE_SRC SoundRender_Source.h SoundRender_Source.cpp SoundRender_Source_loader.cpp)
set(TARGET_SRC SoundRender_Target.h SoundRender_Target.cpp)
set(TARGET_OPENAL_SRC SoundRender_TargetA.h SoundRender_TargetA.cpp)

source_group("Cache" FILES ${CACHE_SRC})
source_group("Core" FILES ${CORE_SRC})
source_group("Core\\OpenAL" FILES ${CORE_OPENAL_SRC})
source_group("Emitter" FILES ${EMITTER_SRC})
source_group("Environment" FILES ${ENV_SRC})
source_group("Kernel" FILES ${KERNEL_SRC})
source_group("Source" FILES ${SOURCE_SRC})
source_group("Target" FILES ${TARGET_SRC})
source_group("Target\\OpenAL" FILES ${TARGET_OPENAL_SRC})

add_definitions(-DXRSOUND_EXPORTS -D_SECURE_SCL=0)

add_compile_options(/fp:fast "/Yustdafx.h" /GR)
set_source_files_properties(stdafx.cpp PROPERTIES COMPILE_FLAGS /Yc)
set_source_files_properties(guids.cpp PROPERTIES COMPILE_FLAGS /Y-)

add_library(xrSound SHARED ${CACHE_SRC} ${CORE_SRC} ${CORE_OPENAL_SRC} ${EMITTER_SRC} ${ENV_SRC} ${KERNEL_SRC}
                           ${SOURCE_SRC} ${TARGET_SRC} ${TARGET_OPENAL_SRC})
target_link_libraries(xrSound libogg libvorbis libvorbisfile openal dsound xrCore xrAPI xrCDB)