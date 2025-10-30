#include "crypto_square.h"
#include <cmath>
#include <numeric>

namespace crypto_square {
    cipher::cipher(std::string str)
        : orig_str(std::move(str)) {
    }

    // 计算行r和列c
    std::pair<int, int> calc_r_c(const int size) {
        const double sqrt = std::sqrt(size);
        const double diff = sqrt - static_cast<int>(sqrt);
        int r = static_cast<int>(diff < 0.5 ? std::floor(sqrt) : std::ceil(sqrt));
        int c = r * r >= size ? r : r + 1;
        return std::make_pair(r, c);
    }

    std::string cipher::normalized_cipher_text() const {
        const auto effective_str=
            std::accumulate(orig_str.cbegin(), orig_str.cend(), std::string(), [](auto acc, auto ch) {
                if (isalnum(ch))
                    acc.push_back(tolower(ch));
                return acc;
        });
        const auto effective_size = static_cast<int>(effective_str.size());
        if (effective_size == 0)
            return "";

        auto [r, c] = calc_r_c(effective_size);
        std::string result;

        for (auto i = 0; i < c; ++i) {
            for (auto j = 0; j < r; ++j) {
                const auto idx = i + j * c;
                result.push_back(idx < effective_size ? effective_str[idx] : ' ');
            }
            if (i != c - 1)
                result.push_back(' ');
        }

        return result;
    }
} // namespace crypto_square
