#include "perfect_numbers.h"
#include <stdexcept>

namespace perfect_numbers {
    classification classify(const int num) {
        if (num <= 0)
            throw std::domain_error("");

        int sum = 0;
        for (auto i = 1; i <= num / 2; ++i)
            if (num % i == 0)
                sum += i;

        return sum == num ? classification::perfect : sum > num ? classification::abundant : classification::deficient;
    }
}  // namespace perfect_numbers
