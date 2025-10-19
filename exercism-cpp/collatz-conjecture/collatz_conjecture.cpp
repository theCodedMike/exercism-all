#include "collatz_conjecture.h"
#include <stdexcept>

namespace collatz_conjecture {

    /*
    unsigned steps(int num) {
        if (num <= 0)
            throw std::domain_error("num should be greater than 0");

        unsigned _steps = 0;

        while (num != 1) {
            if (num % 2 == 0)
                num /= 2;
            else
                num = num * 3 + 1;
            ++_steps;
        }

        return _steps;
    }
    */

    unsigned steps(int num) {
        if (num <= 0)
            throw std::domain_error("num should be greater than 0");

        if (num == 1)
            return 0;

        return 1 + steps(num % 2 == 0 ? num / 2 : num * 3 + 1);
    }

}  // namespace collatz_conjecture
