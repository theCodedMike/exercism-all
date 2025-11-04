#pragma once
#include <utility>
#include <string>

namespace robot_simulator {
    enum class Bearing {
        NORTH,
        EAST,
        SOUTH,
        WEST
    };

    class Robot {
    public:
        Robot() = default;
        Robot(const std::pair<int, int> &position, const Bearing bearing)
            : pos_x(position.first), pox_y(position.second), bearing(bearing) {
        }

        [[nodiscard]]
        std::pair<int, int> get_position() const;

        [[nodiscard]]
        Bearing get_bearing() const;

        void turn_right();

        void turn_left();

        void advance();

        void execute_sequence(const std::string &);

    private:
        int pos_x = 0;
        int pox_y = 0;
        Bearing bearing = Bearing::NORTH;
    };

}  // namespace robot_simulator
