#include "prime_factors.h"

namespace prime_factors {

    std::vector<long long> of(long long num) {
        std::vector<long long> result;
        long long divisor = 2;

        while (num != 1) {
            if (num % divisor == 0) {
                result.push_back(divisor);
                num /= divisor;
            } else
                ++divisor;
        }

        return result;
    }

}  // namespace prime_factors
