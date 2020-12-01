#pragma once

#include <utility>
#include <unordered_set>

#include <coroutine>

#include "graph.h"
#include "generator.hpp"
#include "set_index_converter.h"


class MisGenerator
{
public:
    MisGenerator(const Graph& graph,
                 const std::unordered_set<std::size_t>& vertex_set)
        : graph(graph)
        , vertex_set(vertex_set)
    {
        traversed_set.reserve((1ull << vertex_set.size()));
    }

    cppcoro::generator<std::size_t> next()
    {
        bool is_maximal = true;

        for (const auto vertex : vertex_set)
            if (stack_set.find(vertex) == stack_set.end())
            {
                if (independent(vertex))
                {
                    stack_set.insert(vertex);

                    for (auto is : next())
                        co_yield is;

                    stack_set.erase(vertex);
                    is_maximal = false;
                }
            }

        if (is_maximal) {
            auto index = SetIndexConverter::set_to_index(stack_set);
            if (traversed_set.find(index) == traversed_set.end())
                co_yield index;
        }
    }

private:
    const Graph& graph;
    const std::unordered_set<std::size_t>& vertex_set;

    std::unordered_set<std::uint64_t> traversed_set;

    std::unordered_set<std::size_t> stack_set;

    bool independent(std::size_t vertex) const
    {
        for (const auto v : stack_set) {
            if (graph.has_edge(v, vertex))
                return false;
        }

        return true;
    }
};