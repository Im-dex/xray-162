cmake_minimum_required(VERSION 3.8)

project(openal)

file(GLOB HEADERS include/openal/*.h)
file(GLOB SRC OpenAL-Windows/Router/*.cpp OpenAL-Windows/Router/*.h)
file(GLOB RES OpenAL-Windows/Router/*.rc)

source_group("include" FILES ${HEADERS})
source_group("src" FILES ${SRC})
source_group("resources" FILES ${RES})

include_directories(include)

add_definitions(-DROUTER_EXPORTS -D_SECURE_SCL=0)

add_compile_options(/fp:fast)

add_library(openal SHARED ${HEADERS} ${SRC} ${RES})
target_link_libraries(openal winmm)
target_include_directories(openal PUBLIC include)