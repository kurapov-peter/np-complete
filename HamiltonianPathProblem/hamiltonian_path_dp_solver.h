#ifndef NP_COMPLETE_HAMILTONIAN_PATH_DP_SOLVER_H
#define NP_COMPLETE_HAMILTONIAN_PATH_DP_SOLVER_H

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
  std::vector<std::vector<bool>> dynamic_matrix;
  bool is_solution_found = false;

  void initialize_dynamic_matrix();
  bool is_included_to_path(size_t vertex, size_t mask, size_t vertex_);
  bool is_vertex_in_mask(size_t mask, size_t vertex) const;
  std::string prepare_answer_string(const std::vector<size_t>& answer) const;
  void check_solution_exist();
  size_t get_mask(size_t vertex) const;
};

#endif  // NP_COMPLETE_HAMILTONIAN_PATH_DP_SOLVER_H
