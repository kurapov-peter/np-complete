set(SOURCE_SSET main.cpp)
set (SOURCE_LIB SSet.cpp)

add_library(sset STATIC ${SOURCE_LIB})
add_executable(main ${SOURCE_SSET})
target_link_libraries(main sset)

add_executable(bench_subset_BF bench_subset_BF.cpp)
target_link_libraries(bench_subset_BF sset benchmark::benchmark)

add_executable(bench_subset_opt bench_subset_opt.cpp)
target_link_libraries(bench_subset_opt sset benchmark::benchmark)

add_executable(bench_subset_optHS bench_subset_optHS.cpp)
target_link_libraries(bench_subset_optHS sset benchmark::benchmark)
