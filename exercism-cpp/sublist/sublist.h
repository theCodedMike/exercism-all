#pragma once
#include <vector>

namespace sublist {
    enum class List_comparison {
        equal,
        unequal,
        sublist,
        superlist,
    };

    List_comparison sublist(std::vector<int> &&, std::vector<int> &&);
}  // namespace sublist
