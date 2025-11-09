#include "resistor_color_duo.h"
#include <unordered_map>

namespace resistor_color_duo {
    std::unordered_map<std::string_view, int> color_map = {
        {"black", 0},
        {"brown", 1},
        {"red", 2},
        {"orange", 3},
        {"yellow", 4},
        {"green", 5},
        {"blue", 6},
        {"violet", 7},
        {"grey", 8},
        {"white", 9}
    };

    int value(const std::vector<std::string_view> & colors) {
        return color_map[colors[0]] * 10 + color_map[colors[1]];
    }

}  // namespace resistor_color_duo
