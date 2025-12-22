#pragma once
#include <array>
#include <string_view>

namespace kindergarten_garden {

    enum class Plants {
        clover, grass, violets, radishes
    };

    std::array<Plants, 4> plants(std::string_view, std::string_view);

}  // namespace kindergarten_garden
