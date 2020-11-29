
#ifndef CLIQUE_H
#define CLIQUE_H

#include "graph.hpp"

namespace graph {

bool isClique(const Graph &graph);

size_t maxCliqueNaive(const Graph &graph);

}  // namespace graph
#endif
