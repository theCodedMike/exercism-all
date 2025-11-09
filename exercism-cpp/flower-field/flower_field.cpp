#include "flower_field.h"

namespace flower_field {
    std::vector<std::string> annotate(std::vector<std::string> &&board) {
        const int row = static_cast<int>(board.size());
        if (row == 0)
            return board;
        const int col = static_cast<int>(board[0].size());
        if (col == 0)
            return board;

        auto update_cell = [&](int i, int j) {
            if (i >= 0 && i < row && j >= 0 && j < col && board[i][j] != '*') {
                if (board[i][j] == ' ')
                    board[i][j] = '1';
                else
                    ++board[i][j];
            }
        };

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == '*') {
                    update_cell(i - 1, j - 1); update_cell(i - 1, j); update_cell(i - 1, j + 1);
                    update_cell(i, j - 1);                            update_cell(i, j + 1);
                    update_cell(i + 1, j - 1); update_cell(i + 1, j); update_cell(i + 1, j + 1);
                }
            }
        }

        return board;
    }
} // namespace flower_field
