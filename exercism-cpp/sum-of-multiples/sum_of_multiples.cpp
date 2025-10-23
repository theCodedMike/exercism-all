#include "sum_of_multiples.h"
#include <numeric>
#include <unordered_set>

namespace sum_of_multiples {
    // 方法1
    unsigned to(const std::initializer_list<unsigned> magical_items, const unsigned level) {
        std::unordered_set<unsigned> set;

        for (const unsigned base: magical_items) {
            for (auto i = base; i < level; i += base)
                set.insert(i);
        }

        return std::accumulate(set.cbegin(), set.cend(), static_cast<unsigned>(0));
    }

    // 方法2
    unsigned to2(const std::initializer_list<unsigned> magical_items, const unsigned level) {
        unsigned sum = 0;

        for (unsigned i = 0; i < level; ++i) {
            for (const unsigned item: magical_items) {
                if (i % item == 0) {
                    sum += i;
                    break;
                }
            }
        }

        return sum;
    }
}  // namespace sum_of_multiples
