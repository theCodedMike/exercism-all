#include "raindrops.h"

namespace raindrops {
    std::string convert(const unsigned num) {
        std::string result;

        if (num % 3 == 0)
            result += PLING;
        if (num % 5 == 0)
            result += PLANG;
        if (num % 7 == 0)
            result += PLONG;

        if (result.empty())
            result = std::to_string(num);

        return result;
    }

}  // namespace raindrops
