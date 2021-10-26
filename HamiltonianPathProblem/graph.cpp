#include "graph.h"

graph::graph(size_t vertex_number): vertex_number_(vertex_number), incidence_matrix_(vertex_number + 1) {
    for (auto& vertex_incidence_list : incidence_matrix_) {
        vertex_incidence_list.resize(vertex_number + 1);
    }
}

void graph::add_edge(vertex outcoming_vertex, vertex incoming_vertex) {
    incidence_matrix_[outcoming_vertex][incoming_vertex] = true;
}

bool graph::is_incident(vertex outcoming_vertex, vertex incoming_vertex) const {
    return incidence_matrix_[outcoming_vertex][incoming_vertex];
}

void graph::print() const {
    std::cout << vertex_number_ << std::endl;
    for (auto& vertex_incidence_list : incidence_matrix_) {
        for (auto is_incident : vertex_incidence_list) {
            std::cout << is_incident << " ";
        }
        std::cout << std::endl;
    }
}