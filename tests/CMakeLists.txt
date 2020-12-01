cmake_minimum_required(VERSION 3.10)

project(GraphColoringTests)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
file(RELATIVE_PATH REL_GRAPHCOLORING_ROOT ${CMAKE_INSTALL_PREFIX} ${CMAKE_CURRENT_SOURCE_DIR}/../)

if(REL_GRAPHCOLORING_ROOT STREQUAL "")
    set(REL_GRAPHCOLORING_ROOT ".")
endif()

file(GLOB_RECURSE GraphColoringTests_sources_tests ./*.cpp)
file(GLOB_RECURSE GraphColoringTests_sources_tests_h ./*.h)

# Google Test Initialization
file(GLOB GraphColoringTests_gtest ${CMAKE_CURRENT_SOURCE_DIR}/../googletest/googletest/src/gtest-all.cc)
file(GLOB GraphColoringTests_gtest_h ${CMAKE_CURRENT_SOURCE_DIR}/../googletest/googletest/include/gtest/*.h)

list(APPEND GraphColoringTests_sources ${GraphColoringTests_sources_tests})
list(APPEND GraphColoringTests_sources ${GraphColoringTests_sources_tests_h})
list(APPEND GraphColoringTests_sources ${GraphColoringTests_gtest})
list(APPEND GraphColoringTests_sources ${GraphColoringTests_gtest_h})

add_definitions(-DGTEST_HAS_PTHREAD=0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../googletest/googletest/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../googletest/googletest/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../GraphColoring/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../GraphColoring)

include(GoogleTest)
enable_testing()

if(MSVC)
  foreach(f ${{GraphColoringTests_sources})
    file(RELATIVE_PATH SRCGR ${CMAKE_HOME_DIRECTORY} ${f})
    set(SRCGR "${SRCGR}")

    string(REGEX REPLACE "(.*)(/[^/]*)$" "\\1" SRCGR ${SRCGR})

    string(REPLACE / \\ SRCGR ${SRCGR})
    source_group("${SRCGR}" FILES ${f})
  endforeach()
endif()

link_directories(${GraphColoring_LINKER_LIBS})
link_directories(${CMAKE_CURRENT_LIST_DIR}/../GraphColoring)

add_executable(GraphColoringTests ${GraphColoringTests_sources})
target_compile_options(GraphColoringTests PRIVATE ${GRAPHCOLORING_CXX_FLAGS} ${GRAPHCOLORING_LINK_FLAGS} -Wno-unused-parameter)
target_link_libraries(GraphColoringTests coloring)

install(TARGETS GraphColoringTests DESTINATION ${CMAKE_INSTALL_PREFIX})