set (test_list run_all.cpp
               subset/bruteforce.cpp
#              subset/optimized.cpp
)

add_executable(tests ${test_list})
target_link_libraries(tests gtest sset)

enable_testing()

add_test(BruteForce "./tests")
#add_test(Optimized "./tests")
