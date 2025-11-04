#include "all_your_base.h"
#include <algorithm>
#include <stdexcept>

namespace all_your_base {

    std::vector<unsigned> convert(const unsigned from_base, const std::vector<unsigned> & in_digits, const unsigned to_base) {
        if (from_base < 2 || to_base < 2)
            throw std::invalid_argument("");

        unsigned base = 1;
        unsigned sum = 0;
        for (int i = in_digits.size() - 1; i >= 0; --i) {
            if (in_digits[i] >= from_base)
                throw std::invalid_argument("");

            sum += in_digits[i] * base;
            base *= from_base;
        }

        std::vector<unsigned> result;
        while (sum != 0) {
            result.push_back(sum % to_base);
            sum /= to_base;
        }
        std::reverse(result.begin(), result.end());

        return result;
    }

}  // namespace all_your_base
