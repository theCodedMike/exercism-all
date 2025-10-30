#include "etl.h"
#include <locale>
#include <numeric>

namespace etl {
    std::map<char, int> transform(const std::map<int, std::vector<char> > &one_to_many) {
        return std::accumulate(
            one_to_many.cbegin(), one_to_many.cend(), std::map<char, int>{}, [](auto &map, const auto &entry) {
                for (auto letter: entry.second) {
                    map[std::tolower(letter)] = entry.first;
                }
                return map;
            });
    }
} // namespace etl
