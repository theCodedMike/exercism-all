#include "difference_of_squares.h"

namespace difference_of_squares {

    unsigned long long square_of_sum(const unsigned n) {
        unsigned long long sum = 0;
        for (unsigned i = 1; i <= n; ++i)
            sum += i;
        return sum * sum;
    }

    unsigned long long sum_of_squares(const unsigned n) {
        unsigned long long sum = 0;
        for (unsigned i = 1; i <= n; ++i)
            sum += i * i;
        return sum;
    }

    unsigned long long difference(const unsigned n) {
        return square_of_sum(n) - sum_of_squares(n);
    }

}  // namespace difference_of_squares
