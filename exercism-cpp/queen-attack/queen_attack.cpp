#include "queen_attack.h"
#include <stdexcept>
#include <vector>

namespace queen_attack {

    chess_board::chess_board(const position_type &white, const position_type &black)
        : _white{ white }, _black{ black } {
        if (_white == _black)
            throw std::domain_error("Invalid Pos");

        const std::vector pos = {_white.first, _white.second, _black.first, _black.second};
        for (int i: pos) {
            if (i < 0 || i >= board_size)
                throw std::domain_error("Invalid Pos");
        }
    }

    chess_board::position_type chess_board::white() const {
        return _white;
    }

    chess_board::position_type chess_board::black() const {
        return _black;
    }

    bool chess_board::can_attack() const {
        const int delta_x = _white.first - _black.first;
        const int delta_y = _white.second - _black.second;

        return delta_x == 0 || delta_y == 0 || std::abs(delta_x) == std::abs(delta_y);
    }

}  // namespace queen_attack
