#pragma once

#include <cstdlib>
#include <vector>
#include <utility>

class PermRepeatGenerator
{
public:
    PermRepeatGenerator(std::size_t n, std::size_t r)
        : n(n)
        , r(r)
        , perm_array(std::vector<std::size_t>(n, 1))
        , next_index(n)
    {
        perm_array[n - 1] = 0;
    }

    std::pair<bool, std::vector<std::size_t>> next();

private:
    std::size_t n = 0;
    std::size_t r = 0;

    std::vector<std::size_t> perm_array;

    std::size_t next_index = 0;
};