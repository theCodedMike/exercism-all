#include "affine_cipher.h"

#include <numeric>
#include <stdexcept>

namespace affine_cipher {
    void check(const int a) {
        if (a % 2 == 0 || a % 13 == 0)
            throw std::invalid_argument("parameter a is invalid.");
    }

    int ex(const int a, const int b, const int lower_ch) {
        return (a * (lower_ch - 'a') + b) % 26;
    }

    int mmi(const int a) {
        int x = 1;

        while (true) {
            if (a * x % 26 == 1)
                break;
            ++x;
        }

        return x;
    }

    std::string encode(const std::string &plaintext, const int a, const int b) {
        check(a);

        int valid_char = 0;
        return std::accumulate(
            plaintext.cbegin(), plaintext.cend(), std::string(), [&](std::string &ciphertext, char ch) {
                if (isalnum(ch)) {
                    if (valid_char > 0 && valid_char % 5 == 0)
                        ciphertext.push_back(' ');
                    ++valid_char;

                    if (isdigit(ch))
                        ciphertext.push_back(ch);
                    else {
                        const int lower_ch = tolower(ch);
                        const char cipher_ch = static_cast<char>('a' + ex(a, b, lower_ch));
                        ciphertext.push_back(cipher_ch);
                    }
                }
                return ciphertext;
            });
    }

    std::string decode(const std::string &ciphertext, const int a, const int b) {
        check(a);

        return std::accumulate(
            ciphertext.cbegin(), ciphertext.cend(), std::string(), [&](std::string &plaintext, char ch) {
                if (isalnum(ch)) {
                    if (isdigit(ch))
                        plaintext.push_back(ch);
                    else {
                        const int lower_ch = tolower(ch);
                        const char plain_ch = static_cast<char>((mmi(a) * (lower_ch - 'a' - b) % 26 + 26) % 26 + 'a');
                        plaintext.push_back(plain_ch);
                    }
                }
                return plaintext;
            });
    }
} // namespace affine_cipher
