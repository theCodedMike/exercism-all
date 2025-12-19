#include "luhn.h"
#include <cctype>

namespace luhn {
    bool valid(const std::string_view num_str) {
        auto beg = num_str.crbegin();
        int digit_count = 0;
        int sum = 0;

        while (beg != num_str.crend()) {
            if (isdigit(*beg)) {
                ++digit_count;
                const int digit = *beg - '0';
                if (digit_count % 2 == 1)
                    sum += digit;
                else
                    sum += digit * 2 > 9 ? digit * 2 - 9 : digit * 2;
            } else if (*beg == ' ') {
            } else
                return false;

            ++beg;
        }

        if (digit_count <= 1)
            return false;

        return sum % 10 == 0;
    }
} // namespace luhn
