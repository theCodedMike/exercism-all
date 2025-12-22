#include "rotational_cipher.h"

namespace rotational_cipher {

    std::string rotate(std::string plain, int shift) {
        shift %= 26;
        for (char & ch: plain) {
            if (isalpha(ch)) {
                auto [a_char, z_char] = isupper(ch) ? std::make_pair('A', 'Z') : std::make_pair('a', 'z');
                const int diff = z_char - ch;
                ch = static_cast<char>(shift <= diff ? ch + shift : a_char + shift - diff - 1);
            }
        }

        return plain;
    }

}  // namespace rotational_cipher
