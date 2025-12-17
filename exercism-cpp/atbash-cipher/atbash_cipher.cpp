#include "atbash_cipher.h"

#include <numeric>

namespace atbash_cipher {
    std::string encode(const std::string &plain) {
        int valid_idx = 0;
        return std::accumulate(plain.cbegin(), plain.cend(), std::string(), [&](std::string &cipher, char c) {
            if (isalnum(c)) {
                if (valid_idx > 0 && valid_idx % 5 == 0)
                    cipher.push_back(' ');
                if (isdigit(c))
                    cipher.push_back(c);
                else if (isalpha(c)) {
                    const int lower_char = tolower(c);
                    cipher.push_back(static_cast<char>('z' - (lower_char - 'a')));
                }
                ++valid_idx;
            }

            return cipher;
        });
    }

    std::string decode(const std::string &cipher) {
        return std::accumulate(cipher.cbegin(), cipher.cend(), std::string(), [](std::string &plain, char c) {
            if (isdigit(c))
                plain.push_back(c);
            else if (isalpha(c))
                plain.push_back(static_cast<char>('a' + ('z' - c)));

            return plain;
        });
    }
} // namespace atbash_cipher
