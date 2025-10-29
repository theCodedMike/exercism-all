#include "word_count.h"

namespace word_count {
    constexpr char APOS = '\'';

    std::map<std::string, int> words(const std::string & s) {
        std::map<std::string, int> result;
        std::string word;
        bool need_deal = false;

        for (std::size_t i = 0; i < s.size(); ++i) {
            need_deal = false;

            if (isalnum(s[i]) || s[i] == APOS) {
                word.push_back(tolower(s[i]));
                if (i == s.size() - 1)
                    need_deal = true;
            } else {
                need_deal = true;
            }

            if (need_deal) {
                if (word.empty())
                    continue;
                if (word.back() == APOS)
                    word.pop_back();
                if (word.front() == APOS)
                    word.erase(0, 1);
                if (word.empty())
                    continue;

                std::string key = word;
                result[key] += 1;
                word.clear();
            }
        }

        return result;
    }
}  // namespace word_count
