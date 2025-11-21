#include "spiral_matrix.h"

namespace spiral_matrix {

    std::vector<std::vector<std::uint32_t>> spiral_matrix(const int size) {
        std::vector result(size, std::vector<std::uint32_t>(size));
        int val = 1;
        int x = 0, y = 0;
        std::vector<std::pair<int, int>> dir = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };
        int dir_idx = 0;

        while (val <= size * size) {
            result[x][y] = val;
            ++val;
            // 计算下一步的位置
            auto next_x = x + dir[dir_idx].first;
            auto next_y  = y + dir[dir_idx].second;
            // 检查是否需要转向
            if (next_x >= size || next_y >= size || next_x < 0 || next_y < 0 || result[next_x][next_y] != 0) {
                dir_idx = (dir_idx + 1) % 4;
                next_x = x + dir[dir_idx].first;
                next_y = y + dir[dir_idx].second;
            }
            // 更新位置
            x = next_x;
            y = next_y;
        }

        return result;
    }

}  // namespace spiral_matrix
