#include "rail_fence_cipher.h"

#include <vector>
#include <string>

namespace rail_fence_cipher {
    std::vector<std::vector<char>> build_rails(const std::string &plaintext, const int rol, const int col) {
        bool increasing = true;
        std::vector rails(rol, std::vector(col, ' '));
        for (auto i = 0, j = 0; j < col; ++j) {
            rails[i][j] = plaintext[j];

            if (increasing)
                ++i;
            else
                --i;
            if (i == rol - 1)
                increasing = false;
            else if (i == 0)
                increasing = true;
        }

        return rails;
    }

    std::string encode(const std::string &plaintext, const int num_rails) {
        const int size = static_cast<int>(plaintext.size());
        // build rails
        const auto rails = build_rails(plaintext, num_rails, size);
        // build ciphertext
        std::string ciphertext;
        for (auto i = 0; i < num_rails; ++i) {
            for (auto j = 0; j < size; ++j)
                if (const char &ch = rails[i][j]; ch != ' ')
                    ciphertext.push_back(ch);
        }
        return ciphertext;
    }

    std::string decode(const std::string &ciphertext, const int num_rails) {
        const int size = static_cast<int>(ciphertext.size());
        const std::string dummy(size, '*');
        // build rails
        auto rails = build_rails(dummy, num_rails, size);
        // fill rails
        for (auto i = 0, k = 0; i < num_rails; ++i) {
            for (auto j = 0; j < size; ++j)
                if (rails[i][j] == '*')
                    rails[i][j] = ciphertext[k++];
        }
        // build plaintext
        std::string plaintext;
        for (auto i = 0; i < size; ++i) {
            for (auto j = 0; j < num_rails; ++j)
                if (const char &ch = rails[j][i]; ch != ' ')
                    plaintext.push_back(ch);
        }
        return  plaintext;
    }
} // namespace rail_fence_cipher
