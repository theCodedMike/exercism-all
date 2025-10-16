#include "pangram.h"

#include <bitset>
//#include <unordered_set>

namespace pangram {

    /*
    bool is_pangram(const std::string& s) {
        std::unordered_set<char> chars;

        for (const char ch : s) {
            if (!isalpha(ch))
                continue;

            if (isupper(ch))
                chars.insert(tolower(ch));
            else
                chars.insert(ch);
        }

        return chars.size() == 26;
    }
    */

    bool is_pangram(const std::string& s) {
        std::bitset<26> bits;

        for (const char ch: s) {
            if (!isalpha(ch))
                continue;

            if (isupper(ch))
                bits[ch - 'A'] = true;
            else
                bits[ch - 'a'] = true;
        }

        return bits.all();
    }
}  // namespace pangram
