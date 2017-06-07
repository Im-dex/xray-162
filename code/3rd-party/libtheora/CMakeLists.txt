cmake_minimum_required(VERSION 3.8)

project(libtheora)

file(GLOB HEADERS include/theora/*.h)
file(GLOB X86_SRC lib/x86_vc/*.h lib/x86_vc/*.c)
file(GLOB SRC lib/*.c lib/*.h)
list(REMOVE_ITEM SRC ${CMAKE_CURRENT_SOURCE_DIR}/lib/encoder_disabled.c)

source_group("include" FILES ${HEADERS})
source_group("src" FILES ${SRC} ${X86_SRC})

include_directories(include ../libogg/include)

add_definitions(-D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -D_BIND_TO_CURRENT_CRT_VERSION
                -DLIBTHEORA_EXPORTS)
if (ARCH_X86)
    add_definitions(-DOC_X86_ASM)
endif()

add_compile_options(/wd4244 /wd4267 /wd4057 /wd4100 /wd4245)

add_library(libtheora STATIC ${HEADERS} ${SRC} ${X86_SRC})
target_link_libraries(libtheora libogg)
target_include_directories(libtheora PUBLIC include)