#include "pascals_triangle.h"

namespace pascals_triangle {

    std::vector<std::vector<int>> generate_rows(std::size_t row_num) {
        std::vector<std::vector<int>> result;

        for (std::size_t i = 1; i <= row_num; ++i) {
            std::vector<int> row;
            for (std::size_t j = 0; j < i; ++j) {
                if (j == 0 || j == i - 1)
                    row.push_back(1);
                else
                    row.push_back(result[i - 2][j - 1] + result[i - 2][j]);
            }
            result.push_back(row);
        }

        return result;
    }

}  // namespace pascals_triangle
