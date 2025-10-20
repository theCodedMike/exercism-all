#include "nth_prime.h"
#include <stdexcept>

namespace nth_prime {

    bool is_prime(const unsigned num) {
        for (unsigned i = 2; i * i <= num; ++i) {
            if (num % i == 0)
                return false;
        }

        return true;
    }

    unsigned nth(unsigned _nth) {
        if (_nth == 0)
            throw std::domain_error("invalid parameter");

        unsigned num = 2;
        while (true) {
            if (is_prime(num))
                --_nth;
            if (_nth == 0)
                break;
            ++num;
        }

        return num;
    }

}  // namespace nth_prime
