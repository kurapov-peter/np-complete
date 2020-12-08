set(test_list run_all.cpp
    sat/parser_tests.cpp
    knight_tour/knight_tests.cpp
    ../knight_tour/knight.cpp
)

add_executable(tests ${test_list})
target_link_libraries(tests gtest)


enable_testing()

add_test(CNFParserTest "./tests")
add_test(KnightTest "./tests")
