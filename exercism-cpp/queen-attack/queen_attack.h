#pragma once
#include <utility>

namespace queen_attack {

    class chess_board {
        const int board_size = 8;
        using position_type = std::pair<int, int>;

    public:
        chess_board(const position_type &, const position_type &);

        [[nodiscard]]
        position_type white() const;
        [[nodiscard]]
        position_type black() const;
        [[nodiscard]]
        bool can_attack() const;

    private:
        position_type _white;
        position_type _black;
    };

}  // namespace queen_attack
