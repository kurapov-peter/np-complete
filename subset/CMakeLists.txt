set(SOURCE_SSET main.cpp)
set (SOURCE_LIB SSet.cpp)

add_library(sset STATIC ${SOURCE_LIB})
add_executable(main ${SOURCE_SSET})
target_link_libraries(main sset)

add_executable(bench_subset set_bench.cpp)
target_link_libraries(bench_subset sset benchmark::benchmark)
