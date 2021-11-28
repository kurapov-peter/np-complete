#include <iostream>

#include "hamiltonian_path_dp_solver.h"

int main() {
  size_t n, m;
  std::cin >> n >> m;
  graph graph_to_solve(n);
  for (size_t edge = 0; edge < m; edge++) {
    size_t outcoming_vertex, incoming_vertex;
    std::cin >> outcoming_vertex >> incoming_vertex;
    graph_to_solve.add_edge(outcoming_vertex, incoming_vertex);
  }
//  for (size_t vertex = 0; vertex < n; vertex++) {
//    graph_to_solve.add_edge(vertex + 1, n + 1);
//    graph_to_solve.add_edge(n + 1, vertex + 1);
//  }
  hamiltonian_path_dp_solver solver(std::move(graph_to_solve));
  solver.solve();

  if (solver.is_solution_exist()) {
    std::cout << "Solution exists! Hamiltonian path is: ";
  //            << solver.get_solution() << std::endl;
  } else {
    std::cout << "Solution does not exist!" << std::endl;
  }
  return 0;
}
