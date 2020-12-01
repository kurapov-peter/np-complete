#pragma once

#include <istream>


#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>


class Graph
{
public:
    Graph() = default;

    void add_edge(std::size_t va, std::size_t vb) {
        auto vertex_va = add_vertex(va);
        auto vertex_vb = add_vertex(vb);

        boost::add_edge(vertex_va, vertex_vb, adjacency_list);
    }

    bool has_edge(std::size_t va, std::size_t vb) const {
        return boost::edge(vertex_mapping.at(va), vertex_mapping.at(vb), adjacency_list).second;
    }

    std::size_t get_num_vertices() const { return vertex_mapping.size(); }

    std::size_t brute_force_chromatic_number() const;
    std::size_t lawler_chromatic_number() const;

    friend std::istream& operator>>(std::istream& is, Graph& graph)
    {
        std::size_t num_edges, num_vertices;
        is >> num_vertices >> num_edges;

        for (std::size_t i = 0; i < num_edges; ++i)
        {
            std::size_t va, vb;
            is >> va >> vb;
            graph.add_edge(va, vb);
        }

        return is;
    }

private:
    struct coord_t {
        using kind = boost::vertex_property_tag;
    };

    using VertexProperty = boost::property<coord_t, std::size_t>;

    using InternalGraph = boost::adjacency_list<boost::listS,
                                                boost::listS,
                                                boost::undirectedS,
                                                VertexProperty>;

    using edge_t   = boost::graph_traits<InternalGraph>::edge_descriptor;
    using vertex_t = boost::graph_traits<InternalGraph>::vertex_descriptor;

    InternalGraph adjacency_list;
    std::unordered_map<std::size_t, vertex_t> vertex_mapping;

    vertex_t add_vertex(std::size_t vertex) {
        auto lookup_result = vertex_mapping.find(vertex);

        return (lookup_result == vertex_mapping.end()) ?
               (vertex_mapping[vertex] = boost::add_vertex(vertex, adjacency_list)) :
               (lookup_result->second);
    }
};