#include "grains.h"

#include <stdexcept>

namespace grains {
    unsigned long long square(const unsigned num_of_square) {
        if (num_of_square < 1 || num_of_square > 64)
            throw std::invalid_argument("[1, 64]");

        return 1ULL << (num_of_square - 1);
    }

    unsigned long long total() {
        unsigned long long sum = 0;

        for (int i = 1; i <= 64; ++i) {
            sum += square(i);
        }

        return sum;
    }
}  // namespace grains
