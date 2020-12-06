set (test_list run_all.cpp
               subset/basic.cpp
)

add_executable(tests ${test_list})
target_link_libraries(tests gtest sset)

enable_testing()

add_test(Basic "./tests")
add_test(Basics "./tests")
