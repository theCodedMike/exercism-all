#include "kindergarten_garden.h"
#include <unordered_map>

namespace kindergarten_garden {
    std::unordered_map<char, Plants> plants_map = {
        {'R', Plants::radishes},
        {'C', Plants::clover},
        {'G', Plants::grass},
        {'V', Plants::violets}
    };

    std::array<Plants, 4> plants(const std::string_view diagram, const std::string_view name) {
        const int i = name[0] - 'A';

        const std::size_t idx1 = i * 2;
        const std::size_t idx3 = diagram.size() / 2 + 1 + idx1;

        return {
            plants_map[diagram[idx1]], plants_map[diagram[idx1 + 1]],
            plants_map[diagram[idx3]], plants_map[diagram[idx3 + 1]]
        };
    }
} // namespace kindergarten_garden
