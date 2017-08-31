cmake_minimum_required(VERSION 3.8)

project(imdexlib)

file(GLOB HEADERS *.hpp)

add_library(imdexlib INTERFACE)
target_sources(imdexlib INTERFACE ${HEADERS})

source_group("include" FILES ${HEADERS})

if (BUILD_TESTS)
    enable_testing()

    file(GLOB TEST_SOURCES tests/*.cpp tests/*.hpp)
    source_group("tests" FILES ${TEST_SOURCES})

    add_executable(imdexlib-test ${TEST_SOURCES})
    target_link_libraries(imdexlib-test imdexlib gtest gmock gmock_main)
    set_target_properties(imdexlib-test PROPERTIES FOLDER 3rd-party)
else()
    # trick to show the project in IDE
    add_custom_target(imdexlib-src SOURCES ${HEADERS})
    set_target_properties(imdexlib-src PROPERTIES FOLDER 3rd-party)
endif()