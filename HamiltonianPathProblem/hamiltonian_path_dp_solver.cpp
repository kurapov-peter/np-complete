#include "hamiltonian_path_dp_solver.h"

#include <algorithm>
#include <iostream>

hamiltonian_path_dp_solver::hamiltonian_path_dp_solver(graph&& graph_to_solve)
    : graph_(graph_to_solve),
      mask_max(get_mask(graph_.get_size())),
      starting_vertex(0) {
  initialize_dynamic_matrix();
}

void hamiltonian_path_dp_solver::initialize_dynamic_matrix() {
  dynamic_matrix.resize(graph_.get_size());
  for (auto& masks : dynamic_matrix) {
    masks.resize(mask_max);
  }
  for (size_t vertex = 0; vertex < graph_.get_size(); vertex++)
    dynamic_matrix[vertex][get_mask(vertex)] = true;
}
size_t hamiltonian_path_dp_solver::get_mask(size_t vertex) const {
  return 1 << vertex;
}

void hamiltonian_path_dp_solver::solve() {
  for (size_t mask = 0; mask < mask_max; mask++) {
    for (size_t vertex = 0; vertex < graph_.get_size(); vertex++) {
      if (is_vertex_in_mask(mask, vertex)) {
        for (size_t vertex_ = 0; vertex_ < graph_.get_size(); vertex_++) {
          if (is_included_to_path(vertex, mask, vertex_)) {
            dynamic_matrix[vertex][mask] = true;
            break;
          }
        }
      }
    }
  }
  check_solution_exist();
}

void hamiltonian_path_dp_solver::check_solution_exist() {
  for (size_t vertex = 0; vertex < graph_.get_size(); vertex++)
    if (dynamic_matrix[vertex][get_mask(graph_.get_size()) - 1]) {
      is_solution_found = true;
      starting_vertex = vertex;
      return;
    }
}

bool hamiltonian_path_dp_solver::is_vertex_in_mask(size_t mask,
                                                   size_t vertex) const {
  return mask & get_mask(vertex);
}

std::string hamiltonian_path_dp_solver::get_solution() {
  std::vector<size_t> answer;
  answer.push_back(starting_vertex + 1);
  for (size_t vertex = starting_vertex, mask = mask_max - 1;
       answer.size() < graph_.get_size();) {
    for (size_t vertex_ = 0; vertex_ < graph_.get_size(); vertex_++) {
      if (is_included_to_path(vertex, mask, vertex_)) {
        answer.push_back(vertex_ + 1);
        mask ^= get_mask(vertex);
        vertex = vertex_;
        continue;
      }
    }
  }
  return prepare_answer_string(answer);
}

std::string hamiltonian_path_dp_solver::prepare_answer_string(
    const std::vector<size_t>& answer) const {
  std::stringstream answer_;
  for (size_t vertex = 0; vertex < answer.size(); vertex++) {
    answer_ << answer[answer.size() - vertex - 1] << ' ';
  }
  std::string answer_string = answer_.str();
  answer_string.pop_back();
  return answer_string;
}

bool hamiltonian_path_dp_solver::is_included_to_path(size_t vertex, size_t mask,
                                                     size_t vertex_) {
  return is_vertex_in_mask(mask, vertex_) &&
         graph_.is_incident(vertex_ + 1, vertex + 1) && vertex != vertex_ &&
         dynamic_matrix[vertex_][mask ^ get_mask(vertex)];
}
