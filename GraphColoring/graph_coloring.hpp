#ifndef GRAPH_COLORING_HPP
#define GRAPH_COLORING_HPP

namespace coloring {

class Graph;

void GreedyColoring(Graph &G);
void BruteForceColoring(Graph &G);
void DSaturColoring(Graph &G);
void RLFColoring(Graph &G);

}  // namespace coloring

#endif
