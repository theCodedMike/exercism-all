#include "armstrong_numbers.h"
#include <cmath>

namespace armstrong_numbers {

    bool is_armstrong_number(int num) {
        const int ori_num = num;
        const int num_of_digits = static_cast<int>(std::log10(num)) + 1;
        int sum_of_power = 0;

        while (num != 0) {
            const int digit = num % 10;
            sum_of_power += static_cast<int>(std::pow(digit, num_of_digits));
            num /= 10;
        }

        return sum_of_power == ori_num;
    }

}  // namespace armstrong_numbers
