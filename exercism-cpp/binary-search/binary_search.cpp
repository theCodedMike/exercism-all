#include "binary_search.h"
#include <stdexcept>

namespace binary_search {
    std::size_t find(const std::vector<int> & data, const int target) {
        auto[left, right] = std::make_pair(0, (int)data.size());

        while (left < right) {
            auto mid = left + ((right - left) >> 1);
            if (target < data[mid])
                right = mid;
            else if (data[mid] < target)
                left = mid + 1;
            else
                return mid;
        }

        throw std::domain_error("cannot find...");
    }
}  // namespace binary_search
