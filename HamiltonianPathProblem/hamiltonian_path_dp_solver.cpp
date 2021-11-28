#include "hamiltonian_path_dp_solver.h"

#include <iostream>

hamiltonian_path_dp_solver::hamiltonian_path_dp_solver(graph&& graph_to_solve)
    : graph_(graph_to_solve), mask_max(1 << graph_.get_size()) {
  initialize_dynamic_matrix();
}

void hamiltonian_path_dp_solver::initialize_dynamic_matrix() {
  dynamic_matrix.resize(graph_.get_size());
  for (auto& masks : dynamic_matrix) {
    masks.resize(mask_max);
//    for (auto& mask : masks) mask = INT32_MAX / 2;
  }
//  dynamic_matrix[0][0] = 0;
  for (size_t vertex = 0; vertex < graph_.get_size(); vertex++)
    dynamic_matrix[vertex][1 << vertex] = true;
}

//void hamiltonian_path_dp_solver::solve() {
//  for (size_t first_vertex = 0; first_vertex < graph_.get_size() - 1;
//       first_vertex++) {
//    int cost = find_cheapest(first_vertex, mask_max - 1);
//    if (cost != INT32_MAX / 2) {
//      is_solution_found = true;
//      starting_vertex = first_vertex;
//      return;
//    }
//    for (auto& masks : dynamic_matrix) {
//      for (auto& mask : masks) {
//        mask = INT32_MAX / 2;
//      }
//    }
//  }
//}

void hamiltonian_path_dp_solver::solve() {
  for (size_t mask = 0; mask < mask_max; mask++) {
    for (size_t vertex = 0; vertex < graph_.get_size(); vertex++) {
      if (mask & (1 << vertex)) {
        for (size_t vertex_ = 0; vertex_ < graph_.get_size(); vertex_++) {
          if (mask & (1 << vertex_) && graph_.is_incident(vertex_ + 1, vertex + 1) && vertex != vertex_ && dynamic_matrix[vertex_][mask ^ (1 << vertex)]) {
            dynamic_matrix[vertex][mask] = true;
            break;
          }
        }
      }
    }
  }
  for (size_t vertex = 0; vertex < graph_.get_size(); vertex++)
    if (dynamic_matrix[vertex][(1 << graph_.get_size()) - 1]) {
      is_solution_found = true;
      return;
    }
}

//int hamiltonian_path_dp_solver::find_cheapest(graph::vertex first_vertex,
//                                              size_t mask) {
//  if (is_element_visited(first_vertex, mask))
//    return dynamic_matrix[first_vertex][mask];
//
//  for (size_t vertex = 0; vertex < graph_.get_size(); vertex++) {
//    if (is_need_update(first_vertex, mask, vertex))
//      dynamic_matrix[first_vertex][mask] =
//          get_updated(first_vertex, mask, vertex);
//  }
//  return dynamic_matrix[first_vertex][mask];
//}

//int hamiltonian_path_dp_solver::get_updated(graph::vertex first_vertex,
//                                            size_t mask, size_t vertex) {
//  return std::min(dynamic_matrix[first_vertex][mask],
//                  find_cheapest(vertex, mask - (1 << vertex)) + 1);
//}

//bool hamiltonian_path_dp_solver::is_need_update(graph::vertex first_vertex,
//                                                size_t mask,
//                                                size_t vertex) const {
//  return graph_.is_incident(first_vertex + 1, vertex + 1) &&
//         (1 << vertex) & mask;
//}

//bool hamiltonian_path_dp_solver::is_element_visited(graph::vertex first_vertex,
//                                                    size_t mask) {
//  return dynamic_matrix[first_vertex][mask] != INT32_MAX / 2;
//}

std::string hamiltonian_path_dp_solver::get_solution() {
  size_t vertex = starting_vertex;
  size_t mask = mask_max - 1;
  std::stringstream answer_head, answer_tail;
  answer_head << vertex + 1 << ' ';
  while (mask != 0) {
    for (size_t vertex_ = 0; vertex_ < graph_.get_size(); vertex_++) {
      if (is_included_to_answer(vertex, mask, vertex_)) {
        if (vertex_ + 1 == graph_.get_size())
          std::swap(answer_tail, answer_head);
        else if (vertex_ != starting_vertex)
          answer_head << vertex_ + 1 << ' ';
        vertex = vertex_;
        mask -= (1 << vertex_);
        continue;
      }
    }
  }
  return answer_head.str() + answer_tail.str();
}
bool hamiltonian_path_dp_solver::is_included_to_answer(size_t vertex,
                                                       size_t mask,
                                                       size_t vertex_) {
  return graph_.is_incident(vertex + 1, vertex_ + 1) && (1 << vertex_) & mask &&
         dynamic_matrix[vertex][mask] ==
             dynamic_matrix[vertex_][mask - (1 << vertex_)] + 1;
}
