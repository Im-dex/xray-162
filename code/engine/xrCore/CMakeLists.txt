cmake_minimum_required(VERSION 3.8)

project(xrCore)

set(COMPRESSOR_LZ LzHuf.h LzHuf.cpp)
set(COMPRESSOR_LZO rt_config1x.h
                   rt_lzo_conf.h rt_lzo_config.h rt_lzo_dict.h rt_lzo_init.cpp
                   rt_lzo_ptr.h rt_lzo1x.h rt_lzo1x_1.cpp rt_lzo1x_9x.cpp
                   rt_lzo1x_d1.cpp rt_lzo1x_d2.cpp rt_lzo1x_d3.cpp rt_lzoconf.h
                   rt_lzodefs.h rt_miniacc.h)
set(COMPRESSOR_RT rt_compressor.cpp rt_compressor.h rt_compressor9.cpp)

set(DEBUG_CORE xrDebug.h xrDebug_macros.h xrDebugNew.cpp)
set_source_files_properties(xrDebug.cpp PROPERTIES HEADER_FILE_ONLY TRUE)
file(GLOB DEBUG_CORE_BLACKBOX_H blackbox/*.h)
file(GLOB DEBUG_CORE_BLACKBOX_CPP blackbox/*.cpp)
set_source_files_properties(${DEBUG_CORE_BLACKBOX_CPP} PROPERTIES COMPILE_FLAGS /Y-)
set(DEBUG_CORE_BLACKBOX ${DEBUG_CORE_BLACKBOX_H} ${DEBUG_CORE_BLACKBOX_CPP})

set(FS FileSystem.cpp FileSystem.h FS.h FS.cpp
       FS_internal.h LocatorAPI.h LocatorAPI.cpp LocatorAPI_defs.h
       LocatorAPI_defs.cpp log.h log.cpp NET_utils.cpp net_utils.h Xr_ini.cpp xr_ini.h)
set(FS_STREAM_READER stream_reader.h stream_reader.cpp)
set(FS_FILE_STREAM_READER file_stream_reader.h file_stream_reader.cpp)

set(INTRUSIVE_PTR intrusive_ptr.h)

set(KERNEL FTimer.h FTimer.cpp resource.h stdafx.h stdafx.cpp xrCore.h xrCore.cpp
           xrCore_platform.h xrCore.rc xr_build_config.h stacktrace_collector.h
           stacktrace_collector.cpp)
           
set(MATH_ _bitwise.h _color.h _compressed_normal.h _compressed_normal.cpp _cylinder.h
          _fbox.h _fbox2.h _flags.h _math.cpp _math.h _matrix.h _matrix33.h _obb.h
          _plane.h _plane2.h _quaternion.h _random.h _rect.h _sphere.h _sphere.cpp
          _types.h _vector2.h _vector3d.h _vector3d_ext.h _vector4.h dump_string.h
          dump_string.cpp vector.h)
set(MATH_CPU cpuid.h cpuid.cpp)
set(MATH_EXT _std_extensions.h _std_extensions.cpp _stl_extensions.h clsid.h clsid.cpp
             fastdelegate.h string_concatenations.h string_concatenations.cpp xr_trims.h
             xr_trims.cpp)
set(MATH_EXT_BUFFER_VECTOR buffer_vector.h buffer_vector_inline.h)
set(MATH_STLEXT FixedMap.h FixedSet.h FixedVector.h xrPool.h)

set(MEM_MGR memory_allocation_stats.cpp memory_usage.cpp xrMemory.cpp xrMemory.h xrMemory_align.h
            xrMemory_align.cpp xrMemory_debug.cpp xrMemory_POOL.cpp xrMEMORY_POOL.h xrMemory_pure.h
            xrMemory_subst_msvc.h xrMemory_subst_msvc.cpp)
set(MEM_MGR_DLMALLOC_ALLOCATOR ptmalloc3/malloc.c ptmalloc3/malloc-2.8.3.h ptmalloc3/sysdeps/win32/win32.c)
set_source_files_properties(ptmalloc3/malloc.c ptmalloc3/sysdeps/win32/win32.c PROPERTIES COMPILE_FLAGS /Y-)
set(MEM_MGR_DLMALLOC_WRAPPER doug_lea_allocator.h doug_lea_allocator.cpp memory_allocator_options.h)

set(MEM_MONITOR memory_monitor.h memory_monitor.cpp)

set(OS os_clipboard.h os_clipboard.cpp)

set(SMEM_STR_LIB crc32.cpp xr_resource.h xr_shared.h xr_shared.cpp xrsharedmem.h xrsharedmem.cpp
                 xrstring.h xrstring.cpp)

source_group("Compression\\lz" FILES ${COMPRESSOR_LZ})
source_group("Compression\\lzo" FILES ${COMPRESSOR_LZO})
source_group("Compression\\rt" FILES ${COMPRESSOR_RT})

source_group("Debug core" FILES ${DEBUG_CORE})
source_group("Debug core\\BlackBox" FILES ${DEBUG_CORE_BLACKBOX})

source_group("FS" FILES ${FS})
source_group("FS\\file stream reader" FILES ${FS_FILE_STREAM_READER})
source_group("FS\\stream reader" FILES ${FS_STREAM_READER})

source_group("intrusive_ptr" FILES ${INTRUSIVE_PTR})

source_group("Kernel" FILES ${KERNEL})

source_group("Math" FILES ${MATH_})
source_group("Math\\CPU" FILES ${MATH_CPU})
source_group("Math\\Extensions" FILES ${MATH_EXT})
source_group("Math\\Extensions\\buffer_vector" FILES ${MATH_EXT_BUFFER_VECTOR})
source_group("Math\\STLext" FILES ${MATH_STLEXT})

source_group("Memory manager" FILES ${MEM_MGR})
source_group("Memory manager\\dlmalloc\\allocator" FILES ${MEM_MGR_DLMALLOC_ALLOCATOR})
source_group("Memory manager\\dlmalloc\\wrapper" FILES ${MEM_MGR_DLMALLOC_WRAPPER})

source_group("memory_monitor" FILES ${MEM_MONITOR})

source_group("OS" FILES ${OS})

source_group("shared memory/string library" FILES ${SMEM_STR_LIB})

add_definitions(-DXRCORE_EXPORTS -D_SECURE_SCL=0)

add_compile_options(/fp:fast "/Yustdafx.h")
set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/stdafx.cpp PROPERTIES COMPILE_FLAGS /Yc)

add_library(xrCore SHARED ${COMPRESSOR_LZ} ${COMPRESSOR_LZO} ${COMPRESSOR_RT}
                          
                          ${DEBUG_CORE} ${DEBUG_CORE_BLACKBOX}
                          
                          ${FS} ${FS_STREAM_READER} ${FS_FILE_STREAM_READER}
                          
                          ${INTRUSIVE_PTR}
                          
                          ${KERNEL}
                          
                          ${MATH_} ${MATH_CPU} ${MATH_EXT} ${MATH_EXT_BUFFER_VECTOR}
                          ${MATH_STLEXT}
                          
                          ${MEM_MGR} ${MEM_MGR_DLMALLOC_ALLOCATOR} ${MEM_MGR_DLMALLOC_WRAPPER}
                          
                          ${MEM_MONITOR}
                          
                          ${OS}
                          
                          ${SMEM_STR_LIB})
target_link_libraries(xrCore PUBLIC dxerr2015 version dbghelp winmm faultrep psapi
                             PRIVATE PowrProf)