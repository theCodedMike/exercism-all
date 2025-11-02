#include "isogram.h"
#include <unordered_set>

namespace isogram {

    bool is_isogram(const std::string & s) {
        if (s.empty())
            return true;

        std::unordered_set<int> letters;
        for (auto ch: s) {
            if (!isalpha(ch))
                continue;
            auto lower_ch = tolower(ch);
            if (letters.count(lower_ch) != 0)
                return false;
            letters.insert(lower_ch);
        }

        return true;
    }

}  // namespace isogram
