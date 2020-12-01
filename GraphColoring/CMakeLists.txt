cmake_minimum_required(VERSION 3.10)

project(GraphColoring)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost)

FILE(GLOB LIB_SRCS
    "src/graph.cpp"
    "src/perm_repeat_generator.cpp"
)

FILE(GLOB BENCH_SRCS
    "src/coloring_bench.cpp"
)

include_directories(
    cppcoro
)

set(COLORING_LIB coloring)
add_library(${COLORING_LIB} SHARED ${LIB_SRCS})
target_compile_options(${COLORING_LIB} PUBLIC -O3 -Wall -Werror -Wextra -fcoroutines)
target_link_libraries(${COLORING_LIB} PUBLIC ${Boost_LIBRARIES})

set(EXECUTABLE coloring_bench)

add_executable(${EXECUTABLE} ${BENCH_SRCS})
target_compile_options(${EXECUTABLE} PUBLIC -O3 -Wall -Werror -Wextra)
target_link_libraries(${EXECUTABLE} PUBLIC benchmark::benchmark ${COLORING_LIB})