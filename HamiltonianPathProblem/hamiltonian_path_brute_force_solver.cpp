#include "hamiltonian_path_brute_force_solver.h"

hamiltonian_path_brute_force_solver::hamiltonian_path_brute_force_solver(
    graph&& graph_to_solve)
    : graph_(graph_to_solve) {
  solution.resize(graph_to_solve.get_size() + 1);
}

void hamiltonian_path_brute_force_solver::solve() {
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
  for (graph::vertex v = starting_vertex; v <= graph_.get_size(); v++) {
    fill_next_vertex(v);
    if (!solution[v]) return;
  }
  is_solution_found = true;
}

void hamiltonian_path_brute_force_solver::fill_next_vertex(
    graph::vertex current_vertex) {
  for (solution[current_vertex] = 1;
       solution[current_vertex] <= graph_.get_size();
       solution[current_vertex]++) {
    if (graph_.is_incident(solution[current_vertex - 1],
                           solution[current_vertex])) {
      graph::vertex vertex;
      for (vertex = 1; vertex < current_vertex; vertex++)
        if (solution[vertex] == solution[current_vertex]) break;
      if (vertex == current_vertex) return;
    }
  }
  solution[current_vertex] = 0;
}

std::string hamiltonian_path_brute_force_solver::get_solution() const {
  std::stringstream answer;
  answer << solution[1];
  for (graph::vertex vertex = 2; vertex < solution.size(); vertex++) {
    answer << " -> " << solution[vertex];
  }
  return answer.str();
}