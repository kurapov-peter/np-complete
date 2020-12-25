
set(test_list run_all.cpp
    sat/parser_tests.cpp
    clique/graph_test.cpp
    clique/clique_test.cpp
)

add_executable(tests ${test_list})
target_link_libraries(tests gtest clique)

enable_testing()

add_test(CNFParserTest "./tests")
add_test(CliqueTest "./tests")
