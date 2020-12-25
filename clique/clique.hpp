
#ifndef CLIQUE_H
#define CLIQUE_H

#include "graph.hpp"

namespace graph {

bool isClique(const Graph &graph);

/* Brute force solver */
size_t maxCliqueBruteForce(const Graph &graph);

/*
 * Bron–Kerbosch algorithm *
 * Branch and bound method *
 */
size_t maxClique(const Graph &graph);

}  // namespace graph
#endif
