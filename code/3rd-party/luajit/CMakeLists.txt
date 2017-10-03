cmake_minimum_required(VERSION 3.8)

include(ExternalProject)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(OUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/${ARCH_SUFFIX})

file(WRITE ${OUT_DIR}/makeluajit.bat
           "call \"${VC_ENV_BAT}\" ${ARCH_SUFFIX}
           cd ${SRC_DIR}
           call msvcbuild.bat
           del luajit.exe
           del lua51.exp")

ExternalProject_Add(
    luajit-build
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ${OUT_DIR}/makeluajit.bat
    INSTALL_COMMAND COMMAND ${CMAKE_COMMAND} -E copy ${SRC_DIR}/lua51.dll ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug/lua51.dll
                    COMMAND ${CMAKE_COMMAND} -E copy ${SRC_DIR}/lua51.dll ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/RelWithDebInfo/lua51.dll
                    COMMAND ${CMAKE_COMMAND} -E copy ${SRC_DIR}/lua51.lib ${OUT_DIR}/lua51.lib
                    COMMAND ${CMAKE_COMMAND} -E remove -f ${SRC_DIR}/lua51.dll
                    COMMAND ${CMAKE_COMMAND} -E remove -f ${SRC_DIR}/lua51.lib
                    COMMAND ${CMAKE_COMMAND} -E remove -f ${SRC_DIR}/lj_bcdef.h
                    COMMAND ${CMAKE_COMMAND} -E remove -f ${SRC_DIR}/host/buildvm_arch.h)

add_library(luajit INTERFACE)
set_property(TARGET luajit PROPERTY INTERFACE_LINK_LIBRARIES ${OUT_DIR}/lua51.lib)
target_include_directories(luajit INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_dependencies(luajit luajit-build)