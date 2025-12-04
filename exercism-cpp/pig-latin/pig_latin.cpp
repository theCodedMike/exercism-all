#include "pig_latin.h"
#include <sstream>
#include <vector>

namespace pig_latin {
    std::string translate_word(const std::string &word) {
        const std::size_t size = word.size();
        std::size_t i = 0;
        auto rule_1 = [&]() -> std::string {
            return word + "ay";
        };
        auto rule_2 = [&]() -> std::string {
            return word.substr(i, size - i) + word.substr(0, i) + "ay";
        };

        for (; i < size; ++i) {
            switch (word[i]) {
                case 'u':
                    if (i >= 1 && word[i - 1] == 'q')
                        ++i;
                    [[fallthrough]];
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                    return i == 0 ? rule_1() : rule_2();
                default:
                    if (i == 0 && (word.substr(0, 2) == "xr" || word.substr(0, 2) == "yt"))
                        return rule_1();
                    if (i > 0 && word[i] == 'y')
                        return rule_2();
            }
        }

        return "";
    }

    std::string translate(const std::string &english_text) {
        std::vector<std::string> words;
        std::stringstream ss(english_text);
        std::string word;

        while (std::getline(ss, word, ' '))
            words.push_back(word);

        std::string result;
        for (std::size_t i = 0; i < words.size(); ++i) {
            if (i != 0)
                result += " ";
            result += translate_word(words[i]);
        }

        return result;
    }
} // namespace pig_latin
