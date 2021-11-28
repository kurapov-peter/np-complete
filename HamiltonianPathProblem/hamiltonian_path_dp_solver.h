#ifndef NP_COMPLETE_HAMILTONIAN_PATH_DP_SOLVER_H
#define NP_COMPLETE_HAMILTONIAN_PATH_DP_SOLVER_H

#include <map>
#include <vector>

#include "graph.h"

class hamiltonian_path_dp_solver {
 public:
  explicit hamiltonian_path_dp_solver(graph&& graph_to_solve);
  void solve();
  bool is_solution_exist() const { return is_solution_found; }
  std::string get_solution();

 private:
  graph graph_;
  size_t mask_max = 0;
  size_t starting_vertex;
  std::vector<std::vector<int>> dynamic_matrix;
  bool is_solution_found = false;

  int find_cheapest(graph::vertex first_vertex, size_t mask);
  void initialize_dynamic_matrix();
  bool is_element_visited(unsigned long long int first_vertex, size_t mask);
  bool is_need_update(unsigned long long int first_vertex, size_t mask,
                      size_t vertex) const;
  int get_updated(unsigned long long int first_vertex, size_t mask,
                  size_t vertex);
  bool is_included_to_answer(size_t vertex, size_t mask, size_t vertex_);
};

#endif  // NP_COMPLETE_HAMILTONIAN_PATH_DP_SOLVER_H
