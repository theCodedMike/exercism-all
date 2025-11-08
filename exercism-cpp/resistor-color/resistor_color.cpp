#include "resistor_color.h"
#include <algorithm>

namespace resistor_color {
    std::vector<std::string> ori_colors = {
        "black",
        "brown",
        "red",
        "orange",
        "yellow",
        "green",
        "blue",
        "violet",
        "grey",
        "white"
    };

    long long color_code(const std::string &color) {
        return std::distance(ori_colors.cbegin(), std::find(ori_colors.cbegin(), ori_colors.cend(), color));
    }

    const std::vector<std::string> & colors() {
        return ori_colors;
    }
} // namespace resistor_color
