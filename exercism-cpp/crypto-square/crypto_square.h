#pragma once
#include <string>

namespace crypto_square {
    class cipher {
    public:
        explicit cipher(std::string str);

        [[nodiscard]]
        std::string normalized_cipher_text() const;

    private:
        std::string orig_str;
    };
}  // namespace crypto_square
