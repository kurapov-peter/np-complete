
#include "graph_generator.hpp"

#include <cassert>
#include <iostream>

namespace graph
{

Graph graphWithClique(size_t graphSize, size_t cliqueSize)
{
    assert(graphSize >= cliqueSize);
    Graph graph;
    
    for(size_t i = 0; i < graphSize; i++)
        graph.addVertex(i);

    for(size_t i = 1; i < graphSize; i++)
        graph.addEdge(i - 1, i);
    for(size_t i = 0; i < cliqueSize; i++)
        for(size_t j = i + 1; j < cliqueSize; j++)
            graph.addEdge(i, j);

    return graph;
}

}// namespace graph
