

#include "perm_repeat_generator.h"

std::pair<bool, std::vector<std::size_t>> PermRepeatGenerator::next()
{
    for (;;)
    {
        if (perm_array[next_index - 1] == r) {
            if (--next_index == 0)
                return std::make_pair(false, perm_array);
        }
        else {
            perm_array[next_index - 1]++;

            while (next_index < n)
                perm_array[++next_index - 1] = 1;

            return std::make_pair(true, perm_array);
        }
    }
}