#include "hamming.h"
#include <stdexcept>

namespace hamming {

    unsigned compute(std::string&& strand1, std::string&& strand2) {
        if (strand1.size() != strand2.size())
            throw std::domain_error("strands must be of equal length");

        unsigned distance = 0;
        for (std::string::size_type i = 0; i < strand1.size(); ++i)
            if (strand1[i] != strand2[i])
                ++distance;

        return distance;
    }

}  // namespace hamming
