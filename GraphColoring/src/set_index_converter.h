#pragma once

#include <unordered_set>
#include <cstdint>

class SetIndexConverter
{
public:
    static std::uint64_t set_to_index(const std::unordered_set<std::size_t>& v_set)
    {
        std::uint64_t result = 0;
        for (const auto vertex : v_set)
            result += (1 << vertex);

        return result;
    }

    static std::unordered_set<std::size_t> index_to_set(std::uint64_t s, std::size_t num_vertices)
    {
        std::unordered_set<std::size_t> new_set;
        for (std::size_t i = 0; i < num_vertices; ++i)
            if ((1 << i) & s)
                new_set.insert(i);

        return new_set;
    }
};