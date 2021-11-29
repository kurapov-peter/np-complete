#include "hamiltonian_path_brute_force_solver.h"

hamiltonian_path_brute_force_solver::hamiltonian_path_brute_force_solver(
    graph&& graph_to_solve)
    : graph_(graph_to_solve) {
  solution.resize(graph_to_solve.get_size() + 1);
}

void hamiltonian_path_brute_force_solver::solve() {
  if (graph_.get_size() == 1) {
    solution[1] = 1;
    is_solution_found = true;
    return;
  }
  for (graph::vertex starting_vertex = 1; starting_vertex <= graph_.get_size();
       starting_vertex++) {
    solution[1] = starting_vertex;
    solve_from_vertex(2);
    if (is_solution_found) return;
    for (auto& vertex : solution) vertex = 0;
  }
}

void hamiltonian_path_brute_force_solver::solve_from_vertex(
    graph::vertex starting_vertex) {
  while (true) {
    fill_next_vertex(starting_vertex);
    if (!solution[starting_vertex]) return;
    if (starting_vertex == graph_.get_size()) {
      is_solution_found = true;
      return;
    }
    solve_from_vertex(starting_vertex + 1);
    if (is_solution_found) return;
  }
}

void hamiltonian_path_brute_force_solver::fill_next_vertex(
    graph::vertex current_vertex) {
  while (true) {
    solution[current_vertex] =
        (solution[current_vertex] + 1) % (graph_.get_size() + 1);
    if (!solution[current_vertex]) return;
    if (graph_.is_incident(solution[current_vertex - 1],
                           solution[current_vertex])) {
      graph::vertex vertex;
      for (vertex = 1; vertex < current_vertex; vertex++)
        if (solution[vertex] == solution[current_vertex]) break;
      if (vertex == current_vertex) return;
    }
  }
}

std::string hamiltonian_path_brute_force_solver::get_solution() const {
  std::stringstream answer;
  answer << solution[1];
  for (graph::vertex vertex = 2; vertex < solution.size(); vertex++) {
    answer << " -> " << solution[vertex];
  }
  return answer.str();
}