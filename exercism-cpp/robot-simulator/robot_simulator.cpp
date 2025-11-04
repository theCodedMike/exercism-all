#include "robot_simulator.h"
#include <stdexcept>

namespace robot_simulator {
    std::pair<int, int> Robot::get_position() const {
        return std::make_pair(pos_x, pox_y);
    }

    Bearing Robot::get_bearing() const {
        return bearing;
    }

    void Robot::turn_right() {
        switch (bearing) {
            case Bearing::NORTH: bearing = Bearing::EAST; break;
            case Bearing::EAST: bearing = Bearing::SOUTH; break;
            case Bearing::SOUTH: bearing = Bearing::WEST; break;
            case Bearing::WEST: bearing = Bearing::NORTH; break;
        }
    }

    void Robot::turn_left() {
        switch (bearing) {
            case Bearing::NORTH: bearing = Bearing::WEST; break;
            case Bearing::EAST: bearing = Bearing::NORTH; break;
            case Bearing::SOUTH: bearing = Bearing::EAST; break;
            case Bearing::WEST: bearing = Bearing::SOUTH; break;
        }
    }

    void Robot::advance() {
        switch (bearing) {
            case Bearing::NORTH: pox_y += 1; break;
            case Bearing::EAST: pos_x += 1; break;
            case Bearing::SOUTH: pox_y -= 1; break;
            case Bearing::WEST: pos_x -= 1; break;
        }
    }

    void Robot::execute_sequence(const std::string & seq) {
        for (const char ch: seq) {
            switch (ch) {
                case 'R': turn_right(); break;
                case 'L': turn_left(); break;
                case 'A': advance(); break;
                default: throw std::invalid_argument("Invalid command");
            }
        }
    }
}  // namespace robot_simulator
