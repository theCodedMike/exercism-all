#include "isbn_verifier.h"

namespace isbn_verifier {
    bool is_valid(const std::string &isbn) {
        int sum = 0;

        auto [i, size] = std::make_pair(0, static_cast<int>(isbn.size()));
        for (auto j = 0; j < size; ++j) {
            switch (isbn[j]) {
                case 'X':
                    if (j != size - 1)
                        return false;
                    sum += 10;
                    ++i;
                    break;
                case '-':
                    break;
                default:
                    if (!isdigit(isbn[j]))
                        return false;
                    sum += (isbn[j] - '0') * (10 - i);
                    ++i;
                    break;
            }
        }

        if (i != 10)
            return false;
        return sum % 11 == 0;
    }
} // namespace isbn_verifier
