#include "trinary.h"
#include <cmath>

namespace trinary {
    int to_decimal(const std::string &trinary) {
        auto [val, max_idx] = std::make_pair(0, trinary.size() - 1);

        for (std::size_t i = 0; i <= max_idx; ++i) {
            if (const char ch = trinary[i]; ch == '0' || ch == '1' || ch == '2')
                val += (ch - '0') * static_cast<int>(std::pow(3, max_idx - i));
            else
                return 0;
        }

        return val;
    }
} // namespace trinary
