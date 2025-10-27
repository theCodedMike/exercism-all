#include "series.h"
#include <stdexcept>

namespace series {
    std::vector<std::string> slice(const std::string &digits, const int sub_len) {
        auto total_len = static_cast<int>(digits.size());
        if (sub_len <= 0 || total_len == 0 || total_len < sub_len)
            throw std::domain_error("");

        std::vector<std::string> res;
        for (auto beg = digits.cbegin(); beg + sub_len <= digits.cend(); ++beg) {
            res.emplace_back(beg, beg + sub_len);
        }

        return res;
    }
}  // namespace series
