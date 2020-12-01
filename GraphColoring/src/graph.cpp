
#include "graph.h"
#include "perm_repeat_generator.h"

#include <tuple>
#include <iostream>
#include <limits>

#include "mis_generator.h"

std::size_t Graph::brute_force_chromatic_number() const
{
    const std::size_t num_vertices = boost::num_vertices(adjacency_list);

    bool should_continue = true;
    std::vector<std::size_t> colors_mapping;

    for (std::size_t num_colors = 1; num_colors <= num_vertices; ++num_colors)
    {
        PermRepeatGenerator generator(num_vertices, num_colors);
        std::tie(should_continue, colors_mapping) = generator.next();

        for (; should_continue; std::tie(should_continue, colors_mapping) = generator.next())
        {
            bool is_correct_mapping = true;

            auto coordinates = boost::get(coord_t(), adjacency_list);

            for (auto [ei, ei_end] = boost::edges(adjacency_list); ei != ei_end; ++ei)
                if (colors_mapping[boost::get(coordinates, boost::source(*ei, adjacency_list))] ==
                    colors_mapping[boost::get(coordinates, boost::target(*ei, adjacency_list))])
                {
                    is_correct_mapping = false;
                    break;
                }

            if (is_correct_mapping)
                return num_colors;
        }
    }

    return num_vertices;
}


std::size_t Graph::lawler_chromatic_number() const
{
    const auto num_vertices = get_num_vertices();
    const std::size_t infinity = std::numeric_limits<std::size_t>::max();

    const std::uint64_t limit = ((std::uint64_t)1ull << num_vertices);

    std::vector<std::size_t> X(limit, infinity);
    X[0] = 0;

    for (std::uint64_t S = 0; S < limit; ++S)
    {
        auto s_vertices = SetIndexConverter::index_to_set(S, num_vertices);

        MisGenerator generator(*this, s_vertices);

        for (const auto I_index : generator.next())
        {
            auto index = S & ~I_index;

            if (X[index] + 1 < X[S])
                X[S] = X[index] + 1;
        }
    }

    return X[limit - 1];
}