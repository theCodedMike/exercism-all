#include "hexadecimal.h"

#include <cmath>

namespace hexadecimal {
    std::pair<bool, int> check(const char ch) {
        if ('0' <= ch && ch <= '9')
            return std::make_pair(true, ch - '0');
        if ('a' <= ch && ch <= 'f')
            return std::make_pair(true, ch - 'a' + 10);
        return std::make_pair(false, 0);
    }

    int convert(const std::string_view hex) {
        const std::size_t max_idx = hex.size() - 1;
        int sum = 0;

        for (std::size_t i = 0; i <= max_idx; ++i) {
            auto [is_valid, val] = check(hex[i]);
            if (!is_valid)
                return 0;
            sum += val * static_cast<int>(std::pow(16, max_idx - i));
        }

        return sum;
    }
} // namespace hexadecimal
