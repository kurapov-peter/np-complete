#ifndef HAMILTONIANPATHPROBLEM_GRAPH_H
#define HAMILTONIANPATHPROBLEM_GRAPH_H

#include <sstream>
#include <vector>

class graph {
 public:
  typedef size_t vertex;
  typedef std::vector<bool> incidence_list;

  explicit graph(size_t vertex_number);
  void add_edge(vertex outcoming_vertex, vertex incoming_vertex);
  size_t get_size() const { return incidence_matrix_.size() - 1; }
  bool is_incident(vertex outcoming_vertex, vertex incoming_vertex) const;

  std::string to_string() const;

 private:
  std::vector<incidence_list> incidence_matrix_;
};

#endif  // HAMILTONIANPATHPROBLEM_GRAPH_H
